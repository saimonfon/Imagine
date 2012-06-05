#ifndef CALCUL_ATTRIBUTS_H
#define CALCUL_ATTRIBUTS_H
#include "../parsing/Noeud.h"
class CalculAttributs
{
	public:
	virtual void calculAttrib(Noeud* nouveau) = 0;
};
#endif