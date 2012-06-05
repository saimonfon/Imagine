#ifndef CONDITION_GENERALE_H
#define CONDITION_GENERALE_H
#include "../parsing/Noeud.h"
#include "../Parser.h"
#include "Condition.h"

class ConditionGenerale : public Condition
{
public:
	virtual bool estVerifiee(vector<Noeud*> enfants, Parser* p)=0;
};
#endif