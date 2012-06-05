#ifndef NOEUD_H
#define NOEUD_H
#include <Vector>
#include <string>
#include <Map>
using namespace std;
class Noeud
{
	public:
	virtual vector<Noeud*> getEnfants() = 0;
	virtual string getType() = 0;
	void* getAttribut(string nom);
	map<string,void*> getAttributs();
	string nom_parser;
	void setAttribut(string nom,void* val);
	virtual bool equals(Noeud* n2)=0;
	float score;
	protected:
	map<string,void*> attributs;
};
#endif