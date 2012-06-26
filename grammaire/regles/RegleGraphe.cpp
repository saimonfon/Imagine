#include "RegleGraphe.h"
#include <algorithm>

/** Crée une règle de type séquence.
	*@param nom Le nom du non-terminal.
	*@param type Le type répété (i.e. apparaissant en partie droite de la règle).*/
void RegleGraphe::construct(string nom, string type)
{
	this->nom = nom;
	this->type = type;
	calculAtt=NULL;
	}


/** Initialise la règle pour le parsing (doit être appelé avant chaque nouveau parsing). Réinitialise les structures utilisées lors du parsing.*/
void RegleGraphe::init()
{}

/** Renvoie les noeuds résultants de l'application de la règle à l'état courant du parser.
	*@param parser Le parser de la grammaire en cours d'exécutino
	*@return Les noeuds créés. */
vector<Noeud*> RegleGraphe::appliquer(Parser* parser)
{
	this->parser=parser;
	cout<<"Ok ici"<<endl;
	/* Ajouter les listes à un élément non encore construites */
	set_noeud candidats = parser->noeudsParType[this->type];
	int itt =0;
	for(set_noeud::iterator ite = candidats.begin();ite!=candidats.end();ite++)
	{
		cout<<"traitement noeud "<<(++itt)<<endl;
		if(dejaTraites.count(*ite)>0)
		continue;
		bool okCondition = true;
		for(vector<ConditionUnique*>::iterator it = conditions.begin();it!=conditions.end();it++)
		if(!((*it)->estVerifiee(*ite)))
		{
			okCondition = false;
			break;
		}
		if(!okCondition)
		continue;
		dejaTraites.insert(*ite);
		//cout<<"Ok là"<<endl;
		//Ajout à la table de hachage
		for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
		{
			ConditionAdj* cadj = *it;
			table_adj_i[cadj][(Polygone*)(*ite)->getAttribut(cadj->att_i)].insert(*ite);
			table_adj_j[cadj][(Polygone*)(*ite)->getAttribut(cadj->att_j)].insert(*ite);
		}
		for(vector<ConditionEgal*>::iterator it = condEgal.begin();it!=condEgal.end();it++)
		{
			ConditionEgal* ceg = *it;
			table_eg_i[ceg][(*ite)->getAttribut(ceg->att_i)].insert(*ite);
			table_eg_j[ceg][(*ite)->getAttribut(ceg->att_j)].insert(*ite);
		}
		//cout<<"Ok ajout table de hachage"<<endl;
		/*Ajouter les arêtes qui partent du nouveau noeud*/
		set<Noeud*> possible;// = dejaTraites;
		bool full = true;
		for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
		{
				ConditionAdj* cadj = *it;
				set<Polygone*> adj = parser->adj[(Polygone*) (*ite)->getAttribut(cadj->att_i)];
				//cout<<"Nombre de polygone adjacents "<<adj.size()<<endl;
				set<Noeud*> adj_elem;
				for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_j[cadj][*it2].begin(),table_adj_j[cadj][*it2].end());
				//cout<<"Nombre de sous listes adjacentes "<<adj_elem.size()<<endl;
				//cout<<"Taille de la table de hachage "<<table_adj_j[cadj].size()<<endl;
				//sort(adj_elem.begin(),adj_elem.end());
				if(full) //l'ensemble contient tous les éléments possibles, on doit le construire explicitement
				{
					possible = adj_elem;
					full=false;
				}
				else
				{
				set<Noeud*> new_set;
					set_intersection(possible.begin(),possible.end(),adj_elem.begin(),adj_elem.end(),std::inserter(new_set, new_set.begin()));
				possible = new_set;
				}
		}
		//cout<<"Ok traiteemnt condition d'ajdvne"<<endl;
		for(vector<ConditionEgal*>::iterator it = condEgal.begin();it!=condEgal.end();it++)
		{
				ConditionEgal* ceg = *it;
				set<Noeud*> eg_elem=table_eg_j[ceg][(*ite)->getAttribut(ceg->att_i)];
				set<Noeud*> new_set;
				if(full) //l'ensemble contient tous les éléments possibles, on doit le construire explicitement
				{
					possible = eg_elem;
					full=false;
				}
				else
				{
				set<Noeud*> new_set;
					set_intersection(possible.begin(),possible.end(),eg_elem.begin(),eg_elem.end(),std::inserter(new_set, new_set.begin()));
				possible = new_set;
				}
		}
		//Si le set est toujours plein, tant pis, on le construit explicitement
		if(full) possible = dejaTraites;
		//Exclusivite
		set<Noeud*> exclu = parser->exclusivite[*ite];
		for(set<Noeud*>::iterator it_exclu = exclu.begin();it_exclu!=exclu.end();it_exclu++)
		{
				possible.erase(*it_exclu);
				//cout<<"On supprime "<<(*it_exclu)->nom_parser<<" des succ de "<<(*ite)->nom_parser<<endl;
		}
		cout<<"Taille de possible"<<possible.size()<<endl;
		//cout<<"Ok avant vérif conditions générales"<<endl;
		/*Conditions générales entre deux éléments successifs*/
		for(set<Noeud*>::iterator it=possible.begin();it!=possible.end();it++)
		{
		bool ok=true;
		vector<Noeud*> v;
		v.push_back(*ite);
		v.push_back(*it);
		//cout<<(*ite)->nom_parser<<"<->"<<(*it)->nom_parser<<endl;
		for(vector<ConditionGenerale*>::iterator it_cond = condGen.begin();it_cond!=condGen.end();it_cond++)
			if(!(*it_cond)->estVerifiee(v,parser))
			{
				ok=false;
				break;
			}
			if(ok)
			succ[*ite].insert(*it);
		}
		//cout<<"ok thereee"<<endl;
		/*Ajouter les arêtes qui arrivent au nouveau noeud*/
		possible = set<Noeud*>();
		full = true;
		for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
		{
				ConditionAdj* cadj = *it;
				set<Polygone*> adj = parser->adj[(Polygone*) (*ite)->getAttribut(cadj->att_j)];
				//cout<<"Nombre de polygone adjacents "<<adj.size()<<endl;
				set<Noeud*> adj_elem;
				for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_i[cadj][*it2].begin(),table_adj_i[cadj][*it2].end());
				//cout<<"Nombre de sous listes adjacentes "<<adj_elem.size()<<endl;
				//cout<<"Taille de la table de hachage "<<table_adj_i[cadj].size()<<endl;
				//sort(adj_elem.begin(),adj_elem.end());
				if(full) //l'ensemble contient tous les éléments possibles, on doit le construire explicitement
				{
					possible = adj_elem;
					full=false;
				}
				else
				{
				set<Noeud*> new_set;
				set_intersection(possible.begin(),possible.end(),adj_elem.begin(),adj_elem.end(),std::inserter(new_set, new_set.begin()));
				possible = new_set;
				}
		}
		for(vector<ConditionEgal*>::iterator it = condEgal.begin();it!=condEgal.end();it++)
		{
				ConditionEgal* ceg = *it;
				set<Noeud*> eg_elem=table_eg_i[ceg][(*ite)->getAttribut(ceg->att_j)];
				if(full) //l'ensemble contient tous les éléments possibles, on doit le construire explicitement
				{
					possible = eg_elem;
					full=false;
				}
				else
				{
				set<Noeud*> new_set;
				set_intersection(possible.begin(),possible.end(),eg_elem.begin(),eg_elem.end(),std::inserter(new_set, new_set.begin()));
				possible = new_set;
				}
		}
		//Si le set est toujours plein, tant pis, on le construit explicitement
		if(full) possible = dejaTraites;
		//Exclusivite
		for(set<Noeud*>::iterator it_exclu = exclu.begin();it_exclu!=exclu.end();it_exclu++)
		{
				possible.erase(*it_exclu);
				
				//cout<<"On supprime "<<(*it_exclu)->nom_parser<<" des succ de "<<(*ite)->nom_parser<<endl;
		}
		cout<<"Taille de possible"<<possible.size()<<endl;
		/* Ajout des noeuds et vérif des contraintes générales*/
		for(set<Noeud*>::iterator it=possible.begin();it!=possible.end();it++)
		{
		bool ok=true;
		vector<Noeud*> v;
		v.push_back(*it);
		v.push_back(*ite);
		for(vector<ConditionGenerale*>::iterator it_cond = condGen.begin();it_cond!=condGen.end();it_cond++)
			if(!(*it_cond)->estVerifiee(v,parser))
			{
				ok=false;
				break;
			}
			if(ok)
			succ[*it].insert(*ite);
		}
		//cout<<"Ok élément traité"<<endl;
	}
	cout<<"OOKKK GRAPHE CONSTRUIT"<<endl;
	for(map<Noeud*,set<Noeud*> >::iterator it = succ.begin();it!=succ.end();it++)
	{
		cout<<it->first->nom_parser<<"->";
		for(set<Noeud*>::iterator it2 = it->second.begin();it2!=it->second.end();it2++)
			cout<<(*it2)->nom_parser<<", ";
		cout<<endl;
	}
	
	return noeudsFromGraphe();
}