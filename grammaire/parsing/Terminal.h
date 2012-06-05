#ifndef TERMINAL_H
#define TERMINAL_H
#include "Noeud.h"
#include <Map>
#include "../../geometrie/Polygone.h"
using namespace std;
class Terminal : public Noeud
{
	public :
	Terminal(Polygone* polygone, int number);
	vector<Noeud*> getEnfants();
	string getType();
	bool equals(Noeud* n);
	private :
	string type;
};
#endif