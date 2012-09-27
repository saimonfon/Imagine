#ifndef CONDITION_ADJ_EXT_HEADER
#define CONDITION_ADJ_EXT_HEADER

#include "Condition.h"
#include <string>


/** Condition d'adjacence exterieure entre deux elements */

class ConditionAdj_Ext : public Condition{
public:
	/** Constructeur. Instancie une condition d'adjacence entre deux attibuts (i.att_i et j.att_j doivent etre adjacents).
	@param i L'indice du premier membre droit implique dans la condition.
	@param att_i L'attribut du premier membre droit implique dans la condition d'adjacence.
	@param j L'indice du second membre droit implique dans la condition.
	@param att_j L'attribut du second membre droit implique dans la condition d'adjacence.*/

	ConditionAdj_Ext(int i,std::string att_i, int j, std::string att_j);
	int i;
	int j;
	std::string att_i;
	std::string att_j;

};

#endif
