#ifndef CONDITION_GENERALE_H
#define CONDITION_GENERALE_H
#include "../parsing/Noeud.h"
#include "Condition.h"
class Parser;
/** Classe abstraite décrivant une condition générale.*/
class ConditionGenerale : public Condition
{
public:
/** Retourne vrai si la condition est vérifiée par l'affectation passée en paramètre.
@param enfants L'affectation testée.
@param p Le parser décrivant l'état courant du système.
@return true si l'affectation vérifie la condition, false sinon.*/
	virtual bool estVerifiee(vector<Noeud*> enfants, Parser* p)=0;
};
#endif