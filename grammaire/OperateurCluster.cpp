#include "OperateurCluster.h"
#include <iostream>
#include <list>
#include "parsing/NonTerminal.h"
OperateurCluster::OperateurCluster(string nom, string tempname)
{
	init(nom, tempname);
}

set<Noeud*> OperateurCluster::noeudsFromGraphe()
{
	set<Noeud*> res;
	
	/*Parcours en profondeur du graphe pour trouver tous les chemins */
	/*Tri topologique*/
	int N = dejaTraites.size();
	cout<<"Taille du graphe "<<N<<endl;
	set<Noeud*> marque;
	for(set<Noeud*>::iterator it=dejaTraites.begin();it!=dejaTraites.end();it++)
	{
		Noeud* cur = *it;
		if(marque.count(cur)>0)
			continue;
		//Parcours en profondeur
		std::list<Noeud*> aVoir;
		vector<Noeud*> cluster;
		aVoir.push_front(cur);
		while(!aVoir.empty())
		{
			Noeud* n = aVoir.front();
			aVoir.pop_front();
			cluster.push_back(n);
			marque.insert(n);
			for(set<Noeud*>::iterator it2 = succ[n].begin();it2!=succ[n].end();it2++)
			{
				if(marque.count(*it2)>0)
					continue;
				marque.insert(*it2);
				aVoir.push_front(*it2);
			}
		}
		NonTerminal* new_node = new NonTerminal(name,cluster);
		cout<<"Cluster trouvé : ";
		for(vector<Noeud*>::iterator it = cluster.begin();it!=cluster.end();it++)
			cout<<(*it)->nom_parser<<" ";
		cout<<endl;
		if(calculAtt!=NULL)
					calculAtt->calculAttrib(new_node);
		//INTEGRER L'EXCLUSIVITE !!!!!!
		res.insert(new_node);
	}
	return res;
}