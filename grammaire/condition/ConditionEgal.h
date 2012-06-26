#ifndef CONDITION_EQU_H
#define CONDITION_EQU_H
#include "Condition.h"
#include <string>
using namespace std;
/** Condition d'�galit� entre deux attributs.*/
class ConditionEgal : public Condition
{
public:
/** Constructeur. Instancie une condition d'�galit� entre deux attributs (i.att_i et j.att_j doivent �tre �gaux).
	@param i L'indice du premier membre droit impliqu� dans la condition.
	@param att_i L'attribut du premier membre droit impliqu� dans la condition d'�galit�.
	@param j L'indice du second membre droit impliqu� dans la condition.
	@param att_j L'attribut du second membre droit impliqu� dans la condition d'�galit�.*/
ConditionEgal(int i, string att_i, int j, string att_j);
int i,j;
string att_i,att_j;
};
#endif