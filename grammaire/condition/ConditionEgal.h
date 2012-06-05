#ifndef CONDITION_EQU_H
#define CONDITION_EQU_H
#include "Condition.h"
#include <string>
using namespace std;
class ConditionEgal : public Condition
{
public:
ConditionEgal(int i, string att_i, int j, string att_j);
int i,j;
string att_i,att_j;
};
#endif