#ifndef CONDITION_UNIQUE_H
#define CONDITION_UNIQUE_H
#include "Condition.h"
#include "../parsing/Noeud.h"
/** Condition portant sur un unique membre droit.*/
class ConditionUnique : public Condition
{
public :
/** Constructeur.
@param i L'indice du membre droit sur lequel porte la condition.*/
ConditionUnique(int i);
/** Retourne vrai si la condition est v�rifi�e par le noeud pass� en argument.
@param n Le noeud test�.
@return vrai si le noeud v�rifie la condition, faux sinon.*/
virtual bool estVerifiee(Noeud* n)=0;
ConditionUnique();
int indice;
};
#endif