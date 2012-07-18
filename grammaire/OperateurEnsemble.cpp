#include "OperateurEnsemble.h"
#include <iostream>
#include <list>
#include "parsing/NonTerminal.h"
#include <algorithm>
OperateurEnsemble::OperateurEnsemble(string nom, string tempname)
{
	init(nom, tempname);
}

/** Trouver les cliques dans le graphe 
@return Les cliques du graphe.*/
set<Noeud*> OperateurEnsemble::noeudsFromGraphe()
{
	vector<setNoeud> cliques;
	bk_recursive(setNoeud(),dejaTraites,dejaTraites,&cliques);
	set<Noeud*> res;
	for(vector<setNoeud>::iterator it = cliques.begin();it!=cliques.end();it++)
	{
		cout<<"Clique trouvée :";
		vector<Noeud*> enfants;
		for(setNoeud::iterator it2 = it->begin();it2!=it->end();it2++)
		{
			enfants.push_back(*it2);
			cout<<(*it2)->nom_parser<<" ";
		}
		cout<<endl;
		NonTerminal* n = new NonTerminal(name,enfants);
		n->setAttribut("size",new AttributInt(enfants.size()));
		if(calculAtt!=NULL)
			calculAtt->calculAttrib(n);
		res.insert(n);
	}
	return res;
}

/** Procédure récursive pour trouver les cliques du graphe (Algorithme de Bron-Kerbosch).*/
void OperateurEnsemble::bk_recursive(setNoeud combination, setNoeud intersection, setNoeud possible, vector<setNoeud>* res)
{
	/*cout<<"Current :";
	for(setNoeud::iterator it = combination.begin();it!=combination.end();it++)
		cout<<(*it)->nom_parser<<" ";
	cout<<endl;
	cout<<"Possible :";
	for(setNoeud::iterator it = possible.begin();it!=possible.end();it++)
		cout<<(*it)->nom_parser<<" ";
	cout<<endl;
	cout<<"Intersection :";
	for(setNoeud::iterator it = intersection.begin();it!=intersection.end();it++)
		cout<<(*it)->nom_parser<<" ";
	cout<<endl<<endl;*/
	if(intersection.empty()) //plus rien à ajouter, on a trouvé une clique
	{
		res->push_back(combination);
		return;
	}
	setNoeud S = possible;
	for(setNoeud::iterator it = S.begin();it!=S.end();it++) //pour chaque noeud à traiter
	{
		possible.erase(*it); //on supprime l'élément sélectionné des candidats
		setNoeud new_inter;
		set_intersection(intersection.begin(),intersection.end(),succ[*it].begin(),succ[*it].end(),inserter(new_inter,new_inter.begin())); //intersection avec les voisins du noeud sélectionné
		
		setNoeud new_possible;
		set_intersection(possible.begin(),possible.end(),succ[*it].begin(),succ[*it].end(),inserter(new_possible,new_possible.begin())); //intersection avec les voisins du noeud sélectionné
		
		setNoeud new_comb = combination;
		new_comb.insert(*it);
		bk_recursive(new_comb,new_inter,new_possible,res);
	}
}