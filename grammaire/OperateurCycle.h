#ifndef OPERATEURCYCLE_H
#define OPERATEURCYCLE_H
#include "Operateur.h"
#include <stack>
class OperateurCycle : public Operateur
{
public :
OperateurCycle(string nom, string tempname);
set<Noeud*> noeudsFromGraphe();

int s;
	stack<int> marked_stack; 
	Noeud** noeudsParNum;
	set<Noeud*> res;
stack<int> point_stack;
bool* mark;
bool backtrack(int v);
map<int,set<int> > succ_num;

static bool isPermutation(const vector<Noeud*>& v1,const vector<Noeud*> &v2);
};
#endif