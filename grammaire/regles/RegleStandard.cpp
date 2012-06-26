#include "RegleStandard.h"
#include <algorithm>
#include "../Parser.h"
#include "../parsing/NonTerminal.h"
#include <iostream>
using namespace std;
bool comparator ( const pair<int,float>& l, const pair<int,float>& r);

RegleStandard::RegleStandard(string nom, vector<string> membresDroits)
{
	this->nom = nom;
	this->membresDroits = membresDroits;
	this->N = membresDroits.size();
	calculAtt=NULL;
}

vector<Noeud*> RegleStandard::appliquer(Parser* p)
{
	//CA NORMALEMENT A FAIRE AU DEBUT DU PARSING, PAS A CHAQUE APPLCIATION
	init();
	
	
	this->p=p;
	/* Ordre d'affectation statique pour le moment*/
	cout<<"Ok ici"<<endl;
	/*Création des domaines de chaque variable*/
	domaines = new set<Noeud*>[N];
	for(int i=0;i<N;i++)
	{
	set_noeud s = p->noeudsParType[membresDroits[i]];
	domaines[i] = set<Noeud*>(s.begin(),s.end());
	}
	cout<<"Ok là"<<endl;
	/* Utilisation des conditions unitaires pour réduire les domaines */
	for(vector<ConditionUnique*>::iterator it_cond = condUnique.begin();it_cond!=condUnique.end();it_cond++)
	{
		set<Noeud*> toErase;
		for(set<Noeud*>::iterator it = domaines[(*it_cond)->indice].begin();it!=domaines[(*it_cond)->indice].end();it++)
		if(!(*it_cond)->estVerifiee(*it))
		toErase.insert(*it);
		for(set<Noeud*>::iterator it = toErase.begin();it!=toErase.end();it++)
		domaines[(*it_cond)->indice].erase(*it);
	}
	cout<<"Ok domaines créés et réduits"<<endl;
	for(int i=0;i<N;i++)
		cout<<"Taille du domaine de "<<i<<" : "<<domaines[i].size()<<endl;
	/* Remplissage des tables de hachage */
	for(int k=0;k<N;k++)
	{
	for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
		{
			ConditionAdj* cadj = *it;
			if(cadj->i==k)
			for(set<Noeud*>::iterator ite = domaines[k].begin();ite!=domaines[k].end();ite++)
				table_adj_i[cadj][(Polygone*)(*ite)->getAttribut(cadj->att_i)].insert(*ite);
			else if(cadj->j==k)
			for(set<Noeud*>::iterator ite = domaines[k].begin();ite!=domaines[k].end();ite++)
				table_adj_j[cadj][(Polygone*)(*ite)->getAttribut(cadj->att_j)].insert(*ite);
		}
		for(vector<ConditionEgal*>::iterator it = condEgal.begin();it!=condEgal.end();it++)
		{
			ConditionEgal* ceg = *it;
			if(ceg->i==k)
			for(set<Noeud*>::iterator ite = domaines[k].begin();ite!=domaines[k].end();ite++)
				table_eg_i[ceg][(*ite)->getAttribut(ceg->att_i)].insert(*ite);
			else if(ceg->j==k)
			for(set<Noeud*>::iterator ite = domaines[k].begin();ite!=domaines[k].end();ite++)
				table_eg_j[ceg][(*ite)->getAttribut(ceg->att_j)].insert(*ite);
		}
	}
	//cout<<"Ok tables de hachage"<<endl;
	//cout<<"Taille des tables de hachage"<<endl;
	for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
	{
		ConditionAdj* cadj = *it;
		//cout<<"Adjacence de "<<cadj->i <<"("<<cadj->att_i<<") à "<<cadj->j<<" ( "<<cadj->att_j<<endl;
		//cout<<"Taille de la table de i "<<table_adj_i[cadj].size()<<" et de j "<<table_adj_j[cadj].size()<<endl<<endl;
	}
	/*Choix de l'ordre d'affectation selon l'heuristique : commencer par le min de taille domaine / nombre contraintes */
	vector<pair<int,float> > v;
	for(int i=0;i<N;i++)
	v.push_back(pair<int,float>(i,domaines[i].size()/((float)nb_contraintes[i]+0.1)));
	cout<<"Ok avant sort"<<endl;
	sort(v.begin(),v.end(),comparator);
	cout<<"Ok apres sort"<<endl;
	order = new int[N];
	for(int i=0;i<v.size();i++)
	order[i] = v[i].first;
	for(int i=0;i<N;i++)
		cout<<order[i]<<" ";
	cout<<endl;
	
	cout<<"Ok choix de l'ordre"<<endl;
	/*Ici parcours*/
	resultat.clear();
	vector<set<Noeud*> > vdoms;
	for(int i=0;i<N;i++)
		vdoms.push_back(domaines[i]);
	cout<<"Ok on appelle le CSP"<<endl;
	solveCSP(new Noeud*[N],0,vdoms);
	cout<<"Ok fini csp"<<endl;
	return resultat;
}

void RegleStandard::solveCSP(Noeud** affectPart, int curInd, vector<set<Noeud*> > domaines)
{
	if(curInd==N) //On a une affectation complète
	{
		
		vector<Noeud*> enfants;
		for(int i=0;i<N;i++)
		enfants.push_back(affectPart[i]);
		//On vérifie ici que les conditions générales soient satisfaites
		for(vector<ConditionGenerale*>::iterator it = condGen.begin();it!=condGen.end();it++)
		{
			if(!((*it)->estVerifiee(enfants,this->p)))
			return;
		}
		NonTerminal* new_node = new NonTerminal(nom,enfants);
		if(calculAtt!=NULL)
			calculAtt->calculAttrib(new_node);
		
		resultat.push_back(new_node);
		return;
	}
	int var = order[curInd];
	//cout<<"On choisit la variable "<<var<<", taille du domaine "<<domaines[var].size()<<endl;
	//cout<<"TAILLE DU DOMAINE"<<domaines[var].size()<<endl;
	int w=0;
	for(set<Noeud*>::iterator ite = domaines[var].begin();ite!=domaines[var].end();ite++)
	{
		//cout<<(w++)<<endl;
		//cout<<"Valeur "<<(*ite)->nom_parser<<"pour la variable "<<var<<endl;
		//Affecter à la variable var la valeur it
		affectPart[var] = *ite;
		//Modifier les domaines des autres variables en conséquence
		vector<set<Noeud*> > new_domaines = domaines;
		for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
		{
			ConditionAdj* cadj = *it;
			if(cadj->i==var)
			{
			//cout<<"Prise en comppte d'une condition d'adjacence"<<endl;
			set<Polygone*> adj = p->adj[(Polygone*) (*ite)->getAttribut(cadj->att_i)];
			//cout<<"Nombre d'éléments adjacents :"<<adj.size()<<endl;
			set<Noeud*> adj_elem;
			for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_j[cadj][*it2].begin(),table_adj_j[cadj][*it2].end());
			set<Noeud*> new_set;
				set_intersection(new_domaines[cadj->j].begin(),new_domaines[cadj->j].end(),adj_elem.begin(),adj_elem.end(),std::inserter(new_set, new_set.begin()));
				new_domaines[cadj->j] = new_set;
				
			//cout<<"Nombre de successsuers :"<<new_set.size()<<endl;
			}
			else if(cadj->j==var)
			{
			//cout<<"Prise en comppte d'une condition d'adjacence"<<endl;
			set<Polygone*> adj = p->adj[(Polygone*) (*ite)->getAttribut(cadj->att_j)];
			//cout<<"Nombre d'éléments adjacents :"<<adj.size()<<endl;
			set<Noeud*> adj_elem;
			for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(table_adj_i[cadj][*it2].begin(),table_adj_i[cadj][*it2].end());
			set<Noeud*> new_set;
				set_intersection(new_domaines[cadj->i].begin(),new_domaines[cadj->i].end(),adj_elem.begin(),adj_elem.end(),std::inserter(new_set, new_set.begin()));
				new_domaines[cadj->i] = new_set;
			//cout<<"Nombre de successsuers :"<<new_set.size()<<endl;
			}
		}
		
		for(vector<ConditionEgal*>::iterator it = condEgal.begin();it!=condEgal.end();it++)
		{
			ConditionEgal* ceg = *it;
			if(ceg->i==var)
			{
				set<Noeud*> eg_elem=table_eg_j[ceg][(*ite)->getAttribut(ceg->att_i)];
				set<Noeud*> new_set;
				set_intersection(new_domaines[ceg->j].begin(),new_domaines[ceg->j].end(),eg_elem.begin(),eg_elem.end(),std::inserter(new_set, new_set.begin()));
				new_domaines[ceg->j] = new_set;
			}
			else if(ceg->j==var)
			{
				set<Noeud*> eg_elem=table_eg_i[ceg][(*ite)->getAttribut(ceg->att_j)];
				set<Noeud*> new_set;
				set_intersection(new_domaines[ceg->i].begin(),new_domaines[ceg->i].end(),eg_elem.begin(),eg_elem.end(),std::inserter(new_set, new_set.begin()));
				new_domaines[ceg->i] = new_set;
			}
		}
		//Relation d'exclusivité
		set<Noeud*> exclu = p->exclusivite[*ite];
		//cout<<"Taille de l'exclu : "<<exclu.size()<<endl;
		for(int i=0;i<N;i++)
		{
			if(i==var)
				continue;
			
			//cout<<"Suppression du domaines "<<i<<" de taille "<<new_domaines[i].size()<<endl;
			//cout<<exclu.size()<<endl;
			for(set<Noeud*>::iterator it_exclu = exclu.begin();it_exclu!=exclu.end();it_exclu++)
				new_domaines[i].erase(*it_exclu);
			//cout<<"Nouvelle taille "<<new_domaines[i].size()<<endl;
		}
		//cout<<"Ok là"<<endl;
		//	for(int i=0;i<N;i++)
		//cout<<"Taille du domaine de "<<i<<" : "<<new_domaines[i].size()<<endl;
		//Appeler récursivement le CSP
		solveCSP(affectPart,curInd+1,new_domaines);
	}
}

void RegleStandard::init()
{
	/* On compte les contraintes pour chaque variable */
	nb_contraintes = new int[N];
	for(vector<ConditionAdj*>::iterator it_cond = condAdj.begin();it_cond!=condAdj.end();it_cond++)
	{
		nb_contraintes[(*it_cond)->i]+=1;
		nb_contraintes[(*it_cond)->j]+=1;
	}
	for(vector<ConditionEgal*>::iterator it_cond = condEgal.begin();it_cond!=condEgal.end();it_cond++)
	{
		nb_contraintes[(*it_cond)->i]+=1;
		nb_contraintes[(*it_cond)->j]+=1;
	}	
}

bool comparator ( const pair<int,float>& l, const pair<int,float>& r)
{ return l.second < r.second; }
