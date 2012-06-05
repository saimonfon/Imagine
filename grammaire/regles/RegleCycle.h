#ifndef REGLE_CYCLE_H
#define REGLE_CYCLE_H
#include <stack>
#include "RegleGraphe.h"

class RegleCycle : public RegleGraphe
{
	public :
	RegleCycle(string nom,string type);
	vector<Noeud*> noeudsFromGraphe();
	private :
	int s;
	stack<int> marked_stack; 
	Noeud** noeudsParNum;
	vector<Noeud*> res;
stack<int> point_stack;
bool* mark;
bool backtrack(int v);
map<int,set<int> > succ_num;
};
#endif