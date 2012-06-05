#ifndef REGLE_H
#define REGLE_H
#include "../parsing/Noeud.h"
#include <Map>
#include <Vector>
#include "CalculAttributs.h"
class Parser;
class Regle
{
	public:
	virtual vector<Noeud*> appliquer(Parser* p)=0;
	CalculAttributs* calculAtt;
};
#endif