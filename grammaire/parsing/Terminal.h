#ifndef TERMINAL_H
#define TERMINAL_H
#include "Noeud.h"
#include <map>
#include "../../geometrie/Polygone.h"
using namespace std;
/** Classe décrivant un terminal (i.e. un polygone).*/
class Terminal : public Noeud
{
	public :
	/** Constructeur.
	@param polygone Le polygone correspondant au terminal.
	@param number Sert à rien !!*/
	Terminal(Polygone* polygone, int number);
	vector<Noeud*> getEnfants() const;
	string getType() const;
	bool equals(const Noeud* n2) const;
	private :
	string type;
};
#endif
