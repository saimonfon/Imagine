#ifndef CONDITION_EQU_H
#define CONDITION_EQU_H
#include "Condition.h"
#include <string>
using namespace std;
/** Condition d'égalité entre deux attributs.*/
class ConditionEgal : public Condition
{
public:
/** Constructeur. Instancie une condition d'égalité entre deux attributs (i.att_i et j.att_j doivent être égaux).
	@param i L'indice du premier membre droit impliqué dans la condition.
	@param att_i L'attribut du premier membre droit impliqué dans la condition d'égalité.
	@param j L'indice du second membre droit impliqué dans la condition.
	@param att_j L'attribut du second membre droit impliqué dans la condition d'égalité.*/
ConditionEgal(int i, string att_i, int j, string att_j);
int i,j;
string att_i,att_j;
};
#endif