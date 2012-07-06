#include "OperateurCycle.h"
#include "parsing/NonTerminal.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include "Parser.h"
#include <list>
OperateurCycle::OperateurCycle(string nom, string tempname)
{
	init(nom,tempname);
}

set<Noeud*> OperateurCycle::noeudsFromGraphe()
{
	res.clear();
	//Numéroter les noeuds
	int N = dejaTraites.size();
	map<Noeud*,int> num;
	noeudsParNum = new Noeud*[N];
	int i=0;
	for(set<Noeud*>::iterator it=dejaTraites.begin();it!=dejaTraites.end();it++)
	{
		num[*it] = i;
		cout<<(*it)<<"->"<<i<<endl;
		noeudsParNum[i] = *it;
		++i;
	}
	succ_num.clear();
	for(map<Noeud*,set<Noeud*> >::iterator it = succ.begin();it!=succ.end();it++)
	{
		set<int> s;
		cout<<it->first->nom_parser<<"->";
		for(set<Noeud*>::iterator it2 = it->second.begin();it2!=it->second.end();it2++)
		{
			cout<<(*it2)->nom_parser<<",";
			s.insert(num[*it2]);
		}
		cout<<endl;
		succ_num[num[it->first]] = s;
	}

	//Détection de circuits
	mark = new bool[N];
	//Clear stacks
	while(!marked_stack.empty()) marked_stack.pop();
	while(!point_stack.empty()) point_stack.pop();
	cout<<"Ok ici"<<N<<endl;
	for(int i=0;i<N;i++)
	mark[i]=false;
	for(s=0;s<N;s++)
	{
		//cout<<"Backtracking "<<s<<endl;
		backtrack(s);
		while(!marked_stack.empty())
		{
			int u = marked_stack.top();
			mark[u]=false;
			marked_stack.pop();
		}
	}
	//cout<<"Ok ici"<<endl;
	//Les cycles étant orientés, 
	cout<<res.size()<<endl;
	return res;
}

bool OperateurCycle::backtrack(int v)
{
	bool f = false;
	point_stack.push(v);
	mark[v] = true;
	marked_stack.push(v);
	for(set<int>::iterator it = succ_num[v].begin();it!=succ_num[v].end();)
	{
		int w = *it;
		//cout<<w<<endl;
		if(w<s)
		{
			succ_num[v].erase(it++);
		}
		else
		{
			++it;
			if(w==s)
			{
				//cout<<"Circuit détecté"<<endl;//circuit
				stack<int> disp_stack = point_stack;
				vector<Noeud*> children;
				while(!disp_stack.empty())
				{
					//cout<<noeudsParNum[disp_stack.top()]->nom_parser<<"<-";
					children.push_back(noeudsParNum[disp_stack.top()]);
					disp_stack.pop();
				}
				if(children.size()>2) //on ne considère pas les cycles de taille 2
				{
					bool dejaVu = false;
					for(set<Noeud*>::iterator it = res.begin();it!=res.end();it++)
					{
					if(isPermutation((*it)->enfants,children))
					{
						dejaVu = true;
						break;
					}
					}
					if(!dejaVu)
					{
						NonTerminal* new_node = new NonTerminal(name,children);
						new_node->setAttribut("size",(void*) children.size());
						if(calculAtt!=NULL)
						{
							calculAtt->calculAttrib(new_node);
						}
						res.insert(new_node);
					}
					/*cout<<"Cycle :";
					for(vector<Noeud*>::iterator it = children.begin();it!=children.end();it++)
						cout<<(*it)->nom_parser<<" ";
					cout<<endl;*/
				}
				f=true;
			}
			else if(!mark[w])
			{
				bool g = backtrack(w);
				f =f ||g;
			}
		}
	}
	if(f)
	{
		while(marked_stack.top()!=v)
		{
			int u = marked_stack.top();
			marked_stack.pop();
			mark[u]=false;
		}
		marked_stack.pop();
		mark[v]=false;
	}
	point_stack.pop();
	return f;
}

static bool OperateurCycle::isPermutation(const vector<Noeud*>& v1,const vector<Noeud*> &v2)
{
	if(v1.size()!=v2.size())
	return false;
	/* Ce qui suit est dégueulasse. */
	for(vector<Noeud*>::const_iterator it = v1.begin();it!=v1.end();it++)
	{
		bool found=false;
		for(vector<Noeud*>::const_iterator it2 = v2.begin();it2!=v2.end();it2++)
			if(*it2==*it)
			{
				found=true;break;
			}
		if(!found)
			return false;
	}
	return true;
}