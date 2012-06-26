#ifndef CONDITION_H
#define CONDITION_H
#include <Vector>
/** Classe abstraite décrivant une condition (i.e. une contrainte).*/
class Condition
{
public:
virtual ~Condition() {}
	protected : 
	std::vector<int> indices;
};
#endif