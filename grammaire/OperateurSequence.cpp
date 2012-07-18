#include "OperateurSequence.h"
#include "parsing/NonTerminal.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include "Parser.h"
#include <list>
OperateurSequence::OperateurSequence(string nom, string tempname)
{
init(nom,tempname);
}

void dfs(Noeud* n, map<Noeud*,set<Noeud*> >& succ, std::list<Noeud*>& order, set<Noeud*>& marque);

set<Noeud*> OperateurSequence::noeudsFromGraphe()
{
cout<<"Appel de l'opérateur séquence"<<endl;
set<Noeud*> res;
	
	/*Parcours en profondeur du graphe pour trouver tous les chemins */
	/*Tri topologique*/
	int N = dejaTraites.size();
	cout<<"Taille du graphe "<<N<<endl;
	Noeud** triTopo = new Noeud*[N];
	set<Noeud*> marque;
	int cur_i=0;
	std::list<Noeud*> topOrdre;
	for(set<Noeud*>::iterator it=dejaTraites.begin();it!=dejaTraites.end();it++)
	{
		Noeud* cur = *it;
		if(marque.count(cur)>0)
			continue;
		//Parcours en profondeur
		dfs(cur,succ,topOrdre,marque);
		
	}
	/*Parcours en profondeur et chemins*/
	marque.clear();
	for(std::list<Noeud*>::iterator it = topOrdre.begin();it!=topOrdre.end();it++)
	{
		Noeud* cur = *it;
		//cout<<"On dépile "<<cur->nom_parser<<endl;
		if(marque.count(cur)>0)
			continue;
		stack<pair<Noeud*, vector<Noeud*> > > p;
		vector<Noeud*> v;
		v.push_back(cur);
		p.push(pair<Noeud*, vector<Noeud*> >(cur,v));
		while(!p.empty())
		{
			pair<Noeud*, vector<Noeud*> > cur = p.top();
			p.pop();
			marque.insert(cur.first);
			int nb_children = 0;
			for(set<Noeud*>::iterator it = succ[cur.first].begin();it!=succ[cur.first].end();it++)
				{
					if(marque.count(*it)>0)
						continue;
					bool exclu = false;
					for( vector<Noeud*>::iterator it2 = cur.second.begin();it2!=cur.second.end();it2++)
						if(this->p->exclusivite[*it2].count(*it)>0)
						{
							exclu = true;
							break;
						}
					if(!exclu)
					{
					nb_children++;
					vector<Noeud*> new_set = cur.second;
					new_set.push_back(*it);
					p.push(pair<Noeud*, vector<Noeud*> >(*it,new_set)); 
					}
				}
			if(nb_children==0)
			{
				cout<<"On ajoute le noeud avec enfants "<<cur.second.size()<<endl;
				NonTerminal* new_node = new NonTerminal(name,cur.second);
				new_node->setAttribut("size",new AttributInt(cur.second.size()));
				if(calculAtt!=NULL)
					calculAtt->calculAttrib(new_node);
				/* bool okExclu = true;
				for(int i=0;i<cur.second.size();i++)
				{
					for(int j=0;j<cur.second.size();j++)
					{
						if(i==j)
							continue;
						if(parser->exclusivite[cur.second[i]].count(cur.second[j])>0)
						{
							okExclu=false;
							goto sortir;
						}
					}
				} 
				sortir:
				if(okExclu)*/
				res.insert(new_node);
			}
			else
			{
				
			}
		}
	}
	cout<<"OK à la fin de l'opérateur séquence "<<res.size()<<endl;
	return res;
	}

void dfs(Noeud* n, map<Noeud*,set<Noeud*> >& succ, std::list<Noeud*>& ordre, set<Noeud*>& marque)
{
	marque.insert(n);
	for(set<Noeud*>::iterator it = succ[n].begin();it!=succ[n].end();it++)
	{
		if(marque.count(*it)>0)
			continue;
		dfs(*it,succ,ordre,marque);
	}
	ordre.push_front(n);
}

