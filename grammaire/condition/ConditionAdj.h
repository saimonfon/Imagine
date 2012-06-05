#ifndef CONDITION_ADJ_H
#define CONDITION_ADJ_H
#include "Condition.h"
#include <string>
using namespace std;
class ConditionAdj : public Condition
{
	public :
	ConditionAdj(int i, string att_i, int j, string att_j);	
	int i;
	int j;
	string att_i;
	string att_j;
};
#endif