#include "OperateurCluster.h"
#include <iostream>
#include <list>
#include "parsing/NonTerminal.h"
#include "Parser.h"
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
			//V�rifier ici que l'�l�ment qu'on va ajouter n'est pas exclusif des autres d�j� dans le cluster (algo glouton mais bon)
			bool ok=true;
			for(vector<Noeud*>::iterator itc = cluster.begin();itc!=cluster.end();itc++)
			{
				if(p->exclusivite[*itc].count(n)>0)
				{
					ok=false;
					break;
				}
			}
			if(!ok) //on ne peut pas ajouter le noeud n car le cluster contient un �l�ment exclusif, on se casse
				continue;
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
		new_node->setAttribut("size",new AttributInt(cluster.size()));
		cout<<"Cluster trouv� : ";
		for(vector<Noeud*>::iterator it = cluster.begin();it!=cluster.end();it++)
			cout<<(*it)->nom_parser<<" ";
		cout<<endl;
		if(calculAtt!=NULL)
					calculAtt->calculAttrib(new_node);
		//INTEGRER L'EXCLUSIVITE !!!!!!
		res.insert(new_node);
	}
	if(res.size()==0)
			res.insert(new NonTerminal(name,vector<Noeud*>()));
	return res;
}