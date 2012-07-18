#include "Noeud.h"

Attribut* Noeud::getAttribut(string nom)
	{
		return attributs[nom];
	}
	
	map<string,Attribut*> Noeud::getAttributs()
	{
		return attributs;
	}
	
	void Noeud::setAttribut(string nom,Attribut* val)
	{
		attributs[nom] = val;
	}
	
	
	Noeud*& Noeud::operator[](int i)
	{
		return getEnfants()[i];
	}
	
	Attribut* Noeud::operator[](string s)
	{
		return attributs[s];
	}