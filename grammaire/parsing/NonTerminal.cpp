#include "NonTerminal.h"
#include <string>

vector<Noeud*> NonTerminal::getEnfants()
{
	return enfants;
}
string NonTerminal::getType()
{
	return type;
}

NonTerminal::NonTerminal(string type, vector<Noeud*> enfants)
	{
	attributs = map<string,void*>();
	attributs["type"]= new string(type);
	this->type = type;
	this->enfants = enfants;
	score=1;
	}
	
bool NonTerminal::equals(Noeud* n)
{
	if(type.compare(n->getType())!=0)
		return false;
	return enfants == n->getEnfants();
}