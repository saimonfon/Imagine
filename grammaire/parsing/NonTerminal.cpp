#include "NonTerminal.h"
#include <string>
vector<Noeud*> NonTerminal::getEnfants() const
{
	return enfants;
}
string NonTerminal::getType() const
{
	return type;
}

NonTerminal::NonTerminal(string type, vector<Noeud*> enfants)
	{
	attributs = map<string,void*>();
	attributs["type"]= new string(type);
	this->type = type;
	this->enfants = enfants;
	attributs["size"] = (void*) enfants.size();
	score=1;
	}
	
bool NonTerminal::equals(const Noeud* n) const
{
	if(type.compare(n->getType())!=0)
		return false;
	return enfants == n->getEnfants();
}