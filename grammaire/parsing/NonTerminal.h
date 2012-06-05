#ifndef NONTERMINAL_H
#define NONTERMINAL_H
#include "Noeud.h"
#include <Map>
using namespace std;
class NonTerminal : public Noeud
{
	public :
	NonTerminal(string type, vector<Noeud*> enfants);
	vector<Noeud*> getEnfants();
	string getType();
	bool equals(Noeud* n);
	private :
	vector<Noeud*> enfants;
	string type;
};
#endif