#include "RegleCycle.h"
#include "../parsing/NonTerminal.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
using namespace std;
vector<Noeud*> RegleCycle::noeudsFromGraphe()
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
	cout<<res.size()<<endl;
	return res;
}

bool RegleCycle::backtrack(int v)
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
					NonTerminal* new_node = new NonTerminal(this->nom,children);
					if(calculAtt!=NULL)
					calculAtt->calculAttrib(new_node);
					res.push_back(new_node);
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

RegleCycle::RegleCycle(string nom,string type)
{
	construct(nom,type);
}