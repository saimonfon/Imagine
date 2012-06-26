#ifndef CONDITION_ADJ_H
#define CONDITION_ADJ_H
#include "Condition.h"
#include <string>
using namespace std;
/** Condition d'adjacence entre deux éléments.*/
class ConditionAdj : public Condition
{
	public :
	/** Constructeur. Instancie une condition d'adjacence entre deux attributs (i.att_i et j.att_j doivent être adjacents).
	@param i L'indice du premier membre droit impliqué dans la condition.
	@param att_i L'attribut du premier membre droit impliqué dans la condition d'adjacence.
	@param j L'indice du second membre droit impliqué dans la condition.
	@param att_j L'attribut du second membre droit impliqué dans la condition d'adjacence.*/
	ConditionAdj(int i, string att_i, int j, string att_j);	
	int i;
	int j;
	string att_i;
	string att_j;
};
#endif