#ifndef CONDITION_H
#define CONDITION_H
#include <Vector>
/** Classe abstraite d�crivant une condition (i.e. une contrainte).*/
class Condition
{
public:
virtual ~Condition() {}
	protected : 
	std::vector<int> indices;
};
#endif