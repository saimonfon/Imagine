#ifndef CONDITION_UNIQUE_H
#define CONDITION_UNIQUE_H
#include "Condition.h"
#include "../parsing/Noeud.h"
class ConditionUnique : public Condition
{
public :
ConditionUnique(int i);
virtual bool estVerifiee(Noeud* n)=0;
ConditionUnique();
int indice;
};
#endif