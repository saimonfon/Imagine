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
	
	
	Noeud*& Noeud::operator[](int i)
	{
		return getEnfants()[i];
	}
	
	void* Noeud::operator[](string s)
	{
		return attributs[s];
	}