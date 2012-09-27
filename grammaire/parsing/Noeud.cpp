#include "Noeud.h"

Attribut* Noeud::getAttribut(string nom)
{
	if(attributs.count(nom)==0)
		cout<<"Erreur, attribut "<<nom<<" inexistant pour le noeud "<<nom_parser<<" : le programme va crasher"<<endl;
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
	if(attributs.count(s)==0)
		cout<<"Erreur, attribut "<<s<<" inexistant pour le noeud "<<nom_parser<<" : le programme va crasher"<<endl;
	return attributs[s];
}

