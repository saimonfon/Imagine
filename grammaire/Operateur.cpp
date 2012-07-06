#include "Operateur.h"
#include "Parser.h"
#include <algorithm>
#include "parsing/NonTerminal.h"
class Polygone;
set<Noeud*> Operateur::getAffectations(Parser* p,Noeud** affectation, int N)
{
	this->p = p;
	this->affectation  =affectation;
	/** Construire le graphe ici */
	set_noeud candidats = p->noeudsParType[this->nom];
	int itt =0;
	dejaTraites = set<Noeud*>();
	succ = map<Noeud*,set<Noeud*> >(); 
	for(set_noeud::iterator ite = candidats.begin();ite!=candidats.end();ite++)
	{
		//cout<<"traitement noeud "<<(++itt)<<endl;
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
		/* Traitement des conditions d'adjacence avec des trucs extérieurs */
		/* Le premier indice de la condition correspond à l'élément de la séquence, le second à l'indice de l'élément externe dans la règle*/
		for(vector<ConditionAdj*>::iterator it = condAdjExt.begin();it!=condAdjExt.end();it++)
		{
			ConditionAdj* cadj = *it;
			cout<<"Traitement d'une condition d'adjacence dans la construction du graphe"<<endl;
			if(affectation[cadj->j]==NULL) //Si la variable en question n'est pas affectée, on traite pas.
				continue;
			cout<<"Ok condition adjacecne, l'autre est affecté"<<endl;
			if(p->adj[(Polygone*) affectation[cadj->j]->getAttribut(cadj->att_j)].count((Polygone*) (*ite)->getAttribut(cadj->att_i))==0) //Si l'adjacence n'est pas respectée, on ajoute pas le noeud au graphe.
			{
				okCondition = false;
				cout<<"On vire le noeud"<<(*ite)->nom_parser<<" car il est pas adjacenct"<<endl;
				break;
			}
		}
		if(!okCondition)
			continue;
			
		/* Traitement de l'exclusivité : si l'élément est exclusif d'un élément déjà affecté, on le met pas dans le graphe.*/
		for(int i=0;i<N;i++)
		{
			if(affectation[i]!=NULL && p->exclusivite[affectation[i]].count(*ite)>0)
			{
				okCondition = false;
				break;
			}
		}
		if(!okCondition)
			continue;
		dejaTraites.insert(*ite);
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
		/*Ajouter les arêtes qui partent du nouveau noeud*/
		set<Noeud*> possible;// = dejaTraites;
		bool full = true;
		for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
		{
				ConditionAdj* cadj = *it;
				set<Polygone*> adj = p->adj[(Polygone*) (*ite)->getAttribut(cadj->att_i)];
				set<Noeud*> adj_elem;
				for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_j[cadj][*it2].begin(),table_adj_j[cadj][*it2].end());
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
		set<Noeud*> exclu = p->exclusivite[*ite];
		for(set<Noeud*>::iterator it_exclu = exclu.begin();it_exclu!=exclu.end();it_exclu++)
		{
				possible.erase(*it_exclu);
				//cout<<"On supprime "<<(*it_exclu)->nom_parser<<" des succ de "<<(*ite)->nom_parser<<endl;
		}
		//cout<<"Taille de possible"<<possible.size()<<endl;
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
			if(!(*it_cond)->estVerifiee(v,p))
			{
				ok=false;
				break;
			}
			if(ok)
			succ[*ite].insert(*it);
		}
		/*Ajouter les arêtes qui arrivent au nouveau noeud*/
		possible = set<Noeud*>();
		full = true;
		for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
		{
				ConditionAdj* cadj = *it;
				set<Polygone*> adj = p->adj[(Polygone*) (*ite)->getAttribut(cadj->att_j)];
				set<Noeud*> adj_elem;
				for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_i[cadj][*it2].begin(),table_adj_i[cadj][*it2].end());
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
		}
		//cout<<"Taille de possible"<<possible.size()<<endl;
		/* Ajout des noeuds et vérif des contraintes générales*/
		for(set<Noeud*>::iterator it=possible.begin();it!=possible.end();it++)
		{
		bool ok=true;
		vector<Noeud*> v;
		v.push_back(*it);
		v.push_back(*ite);
		for(vector<ConditionGenerale*>::iterator it_cond = condGen.begin();it_cond!=condGen.end();it_cond++)
			if(!(*it_cond)->estVerifiee(v,p))
			{
				ok=false;
				break;
			}
			if(ok)
			succ[*it].insert(*ite);
		}
	}
	cout<<"OOKKK GRAPHE CONSTRUIT"<<endl;
	for(map<Noeud*,set<Noeud*> >::iterator it = succ.begin();it!=succ.end();it++)
	{
		cout<<it->first->nom_parser<<"->";
		for(set<Noeud*>::iterator it2 = it->second.begin();it2!=it->second.end();it2++)
			cout<<(*it2)->nom_parser<<", ";
		cout<<endl;
	}
	set<Noeud*> res = noeudsFromGraphe();
	cout<<"On a récupéré "<<res.size()<<" résultats"<<endl;
	set<Noeud*> toErase;
	for(set<Noeud*>::iterator ite = res.begin();ite!=res.end();ite++)
	{
	/*S'il y a deux éléments exclusifs, on supprime*/
	for(vector<Noeud*>::iterator it1 = (*ite)->enfants.begin();it1 != (*ite)->enfants.end();it1++)
	{
	bool goOn = true;
	for(vector<Noeud*>::iterator it2 = (*ite)->enfants.begin();it2 != (*ite)->enfants.end();it2++)
	{
		if((it1!=it2) && this->p->exclusivite[*it1].count(*it2)>0)
		{
			goOn=false;
			toErase.insert(*ite);
			break;
	}
	}
		if(!goOn)
			break;
	}
	for(vector<ConditionUnique*>::iterator it = parent->condUnique.begin();it!=parent->condUnique.end();it++)
	{
		if((*it)->indice != this->position)
			continue;
		if(!((*it)->estVerifiee(*ite)))
		{
			//cout<<"On doit supprimer car size = "<<(int)((*ite)->getAttribut("size"))<<endl;
			toErase.insert(*ite);
			break;
		}
	}
	}
	
	for(set<Noeud*>::iterator ite = toErase.begin();ite!=toErase.end();ite++)
		res.erase(*ite);
		if(res.size()==0)
			res.insert(new NonTerminal(name,vector<Noeud*>()));
	return res;
}

void Operateur::init(string nom ,string name)
{
	this->nom = nom;
	this->name = name;
	calculAtt = NULL;
}