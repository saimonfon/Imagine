#include "Noeud.h"

void* Noeud::getAttribut(string nom)
	{
		return attributs[nom];
	}
	
	map<string,void*> Noeud::getAttributs()
	{
		return attributs;
	}
	
	void Noeud::setAttribut(string nom,void* val)
	{
		attributs[nom] = val;
	}