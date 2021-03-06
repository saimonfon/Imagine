#include "Operateur.h"
#include "Parser.h"
#include <algorithm>
#include "parsing/NonTerminal.h"
class Polygone;
set<Noeud*> Operateur::getAffectations(Parser* p,Noeud** affectation, int N)
{
	this->p = p;
	this->affectation  =affectation;
	set_noeud candidats;
	cout<<"On va récupérer les noeuds candidats"<<endl;
	if(type==0) //Opérateur simple, les noeuds candidats sont des noeuds de l'arbre
	candidats = p->noeudsParType[this->nom];
	else //Opérateur ayant un opérateur imbriqué, il faut d'abord trouver les solutions de l'opérateur imbriqué
	{
	candidats = enfant->getAffectations(p,affectation,N);
	cout<<"oK ICI"<<endl;
	//Traiter le cas où le noeud retourné est le noeud "EnsembleVide"
	if(candidats.size()==1)
	{
		set_noeud::iterator it=candidats.begin();
		if((*it)->getType().compare("EnsembleVide")==0)
			candidats = set_noeud();
	}
	else
	{
		set_noeud candidats2 = set_noeud();
		for(set_noeud::iterator it = candidats.begin();it!=candidats.end();it++)
			candidats2.insert(p->ajouterNoeud(*it));
		candidats = candidats2;
	}
	}
	cout<<"OK on a récupéré les candidats"<<endl;
	dejaTraites = set<Noeud*>();
	succ = map<Noeud*,set<Noeud*> >();
	for(set_noeud::iterator ite = candidats.begin();ite!=candidats.end();ite++)
	{
		//cout<<"traitement noeud "<<(++itt)<<endl;
		if(dejaTraites.count(*ite)>0)
			continue;
		bool okCondition = true;
		for(vector<ConditionUnique*>::iterator it = condUnique.begin();it!=condUnique.end();it++)
			if(!((*it)->estVerifiee(*ite)))
			{
				okCondition = false;
				break;
			}
		if(!okCondition)
			continue;
		/* Traitement des conditions d'adjacence avec des trucs ext�rieurs */
		/* Le premier indice de la condition correspond � l'�l�ment de la s�quence, le second � l'indice de l'�l�ment externe dans la r�gle*/
		for(vector<ConditionAdj*>::iterator it = condAdjExt.begin();it!=condAdjExt.end();it++)
		{
			ConditionAdj* cadj = *it;
			//cout<<"Traitement d'une condition d'adjacence dans la construction du graphe"<<endl;
			if(affectation[cadj->j]==NULL) //Si la variable en question n'est pas affect�e, on traite pas.
				continue;
			//cout<<"Ok condition adjacecne, l'autre est affect�"<<endl;
			if(p->adj[affectation[cadj->j]->getAttribut(cadj->att_j)->polygoneValue()].count((*ite)->getAttribut(cadj->att_i)->polygoneValue())==0) //Si l'adjacence n'est pas respect�e, on ajoute pas le noeud au graphe.
			{
				okCondition = false;
				//cout<<"On vire le noeud"<<(*ite)->nom_parser<<" car il est pas adjacenct"<<endl;
				break;
			}
		}
		if(!okCondition)
			continue;

		/* Traitement de l'exclusivit� : si l'�l�ment est exclusif d'un �l�ment d�j� affect�, on le met pas dans le graphe.*/
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
		//Ajout � la table de hachage
		for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
		{
			ConditionAdj* cadj = *it;
			table_adj_i[cadj][(*ite)->getAttribut(cadj->att_i)->polygoneValue()].insert(*ite);
			table_adj_j[cadj][(*ite)->getAttribut(cadj->att_j)->polygoneValue()].insert(*ite);
		}
		for(vector<ConditionAdj_Ext*>::iterator it = condAdj_ext.begin();it!=condAdj_ext.end();it++)
		{
			ConditionAdj_Ext* cadj = *it;
			table_adj_ext_i[cadj][(*ite)->getAttribut(cadj->att_i)->polygoneValue()].insert(*ite);
			table_adj_ext_j[cadj][(*ite)->getAttribut(cadj->att_j)->polygoneValue()].insert(*ite);
		}
		for(vector<ConditionAdj_Int*>::iterator it = condAdj_int.begin();it!=condAdj_int.end();it++)
		{
			ConditionAdj_Int* cadj = *it;
			table_adj_int_i[cadj][(*ite)->getAttribut(cadj->att_i)->polygoneValue()].insert(*ite);
			table_adj_int_j[cadj][(*ite)->getAttribut(cadj->att_j)->polygoneValue()].insert(*ite);
		}

		for(vector<ConditionEgal*>::iterator it = condEgal.begin();it!=condEgal.end();it++)
		{
			ConditionEgal* ceg = *it;
			table_eg_i[ceg][(*ite)->getAttribut(ceg->att_i)].insert(*ite);
			table_eg_j[ceg][(*ite)->getAttribut(ceg->att_j)].insert(*ite);
		}
		/*Ajouter les ar�tes qui partent du nouveau noeud*/
		set<Noeud*> possible;// = dejaTraites;
		bool full = true;
		for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
		{
			ConditionAdj* cadj = *it;
			set<Polygone*> adj = p->adj[(*ite)->getAttribut(cadj->att_i)->polygoneValue()];
			set<Noeud*> adj_elem;
			for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_j[cadj][*it2].begin(),table_adj_j[cadj][*it2].end());
			if(full) //l'ensemble contient tous les �l�ments possibles, on doit le construire explicitement
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


		for(vector<ConditionAdj_Ext*>::iterator it = condAdj_ext.begin();it!=condAdj_ext.end();it++)
		{
			ConditionAdj_Ext* cadj = *it;
			set<Polygone*> adj = p->adj_ext[(*ite)->getAttribut(cadj->att_i)->polygoneValue()];
			set<Noeud*> adj_elem;
			for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_ext_j[cadj][*it2].begin(),table_adj_ext_j[cadj][*it2].end());
			if(full) //l'ensemble contient tous les �l�ments possibles, on doit le construire explicitement
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

		for(vector<ConditionAdj_Int*>::iterator it = condAdj_int.begin();it!=condAdj_int.end();it++)
		{
			ConditionAdj_Int* cadj = *it;
			set<Polygone*> adj = p->adj_int[(*ite)->getAttribut(cadj->att_i)->polygoneValue()];
			set<Noeud*> adj_elem;
			for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_int_j[cadj][*it2].begin(),table_adj_int_j[cadj][*it2].end());
			if(full) //l'ensemble contient tous les �l�ments possibles, on doit le construire explicitement
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
			if(full) //l'ensemble contient tous les �l�ments possibles, on doit le construire explicitement
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
		//cout<<"Ok avant v�rif conditions g�n�rales"<<endl;
		/*Conditions g�n�rales entre deux �l�ments successifs*/
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
		/*Ajouter les ar�tes qui arrivent au nouveau noeud*/
		possible = set<Noeud*>();
		full = true;
		for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
		{
			ConditionAdj* cadj = *it;
			set<Polygone*> adj = p->adj[(*ite)->getAttribut(cadj->att_j)->polygoneValue()];
			set<Noeud*> adj_elem;
			for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_i[cadj][*it2].begin(),table_adj_i[cadj][*it2].end());
			if(full) //l'ensemble contient tous les �l�ments possibles, on doit le construire explicitement
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
		for(vector<ConditionAdj_Ext*>::iterator it = condAdj_ext.begin();it!=condAdj_ext.end();it++)
		{
			ConditionAdj_Ext* cadj = *it;
			set<Polygone*> adj = p->adj_ext[(*ite)->getAttribut(cadj->att_j)->polygoneValue()];
			set<Noeud*> adj_elem;
			for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_ext_i[cadj][*it2].begin(),table_adj_ext_i[cadj][*it2].end());
			if(full) //l'ensemble contient tous les �l�ments possibles, on doit le construire explicitement
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
		for(vector<ConditionAdj_Int*>::iterator it = condAdj_int.begin();it!=condAdj_int.end();it++)
		{
			ConditionAdj_Int* cadj = *it;
			set<Polygone*> adj = p->adj_int[(*ite)->getAttribut(cadj->att_j)->polygoneValue()];
			set<Noeud*> adj_elem;
			for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_int_i[cadj][*it2].begin(),table_adj_int_i[cadj][*it2].end());
			if(full) //l'ensemble contient tous les �l�ments possibles, on doit le construire explicitement
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
			if(full) //l'ensemble contient tous les �l�ments possibles, on doit le construire explicitement
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
		/* Ajout des noeuds et v�rif des contraintes g�n�rales*/
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
	cout<<"Noeuds du graphe :"<<endl;
	for(set<Noeud*>::iterator it=dejaTraites.begin();it!=dejaTraites.end();it++)
		cout<<(*it)->nom_parser<<endl;
	for(map<Noeud*,set<Noeud*> >::iterator it = succ.begin();it!=succ.end();it++)
	{
		cout<<it->first->nom_parser<<"->";
		for(set<Noeud*>::iterator it2 = it->second.begin();it2!=it->second.end();it2++)
			cout<<(*it2)->nom_parser<<", ";
		cout<<endl;
	}
	set<Noeud*> res = noeudsFromGraphe();
	cout<<"On a r�cup�r� "<<res.size()<<" r�sultats"<<endl;
	set<Noeud*> toErase;
	for(set<Noeud*>::iterator ite = res.begin();ite!=res.end();ite++)
	{
		/*S'il y a deux �l�ments exclusifs, on supprime*/
		for(vector<Noeud*>::iterator it1 = (*ite)->enfants.begin();it1 != (*ite)->enfants.end();it1++)
		{
			bool goOn = true;
			for(vector<Noeud*>::iterator it2 = (*ite)->enfants.begin();it2 != (*ite)->enfants.end();it2++)
			{
				if((it1!=it2) && this->p->exclusivite[*it1].count(*it2)>0)
				{
					cout<<"On supprime un noeud car "<<(*it1)->nom_parser<<" et "<<(*it2)->nom_parser<<" sont exclusifs"<<endl;
					goOn=false;
					toErase.insert(*ite);
					break;
				}
			}
			if(!goOn)
				break;
		}
		
	cout<<"OK ICI"<<endl;
		cout<<parent<<" : "<<parent->condUnique.size();
		for(vector<ConditionUnique*>::iterator it = parent->condUnique.begin();it!=parent->condUnique.end();it++)
		{
			//cout<<"Traitement de la condition unique "<<(*it)->indice<<" et this->position vaut "<<this->position<<endl;
			if((*it)->indice != this->position)
				continue;
			if(!((*it)->estVerifiee(*ite)))
			{
				cout<<"On doit supprimer car size = "<<(*ite)->getAttribut("size")->intValue()<<endl;
				toErase.insert(*ite);
				break;
			}
		}
	}
	cout<<"OK ICI"<<endl;
	for(set<Noeud*>::iterator ite = toErase.begin();ite!=toErase.end();ite++)
		res.erase(*ite);
	/*if(res.size()==0)
			res.insert(new NonTerminal(name,vector<Noeud*>()));*/
	return res;
}

void Operateur::init(string nom ,string name)
{
	this->nom = nom;
	this->name = name;
	calculAtt = NULL;
	type=0;
}

void Operateur::init(Operateur* enfant, string name)
{
	this->enfant = enfant;
	this->name = name;
	cout<<"NOM DE l'OP IMBRIQUE :"<<name<<endl;
	calculAtt = NULL;
	type=1;
}

void Operateur::init (Regle* parent, int position)
{
	cout<<"On appelle la version spéciale opérateur"<<endl;
	MembreDroit::init(parent,position);
	if(type==1)
	{
		enfant->init(parent,position);
		cout<<"On appelle bien initi sur l'operateur imbriqué"<<endl;
	}
}