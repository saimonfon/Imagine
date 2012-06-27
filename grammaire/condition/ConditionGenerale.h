#ifndef CONDITION_GENERALE_H
#define CONDITION_GENERALE_H
#include "../parsing/Noeud.h"
#include "Condition.h"
class Parser;
/** Classe abstraite d�crivant une condition g�n�rale.*/
class ConditionGenerale : public Condition
{
public:
/** Retourne vrai si la condition est v�rifi�e par l'affectation pass�e en param�tre.
@param enfants L'affectation test�e.
@param p Le parser d�crivant l'�tat courant du syst�me.
@return true si l'affectation v�rifie la condition, false sinon.*/
	virtual bool estVerifiee(vector<Noeud*> enfants, Parser* p)=0;
};
#endif