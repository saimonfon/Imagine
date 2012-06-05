#ifndef CONDITION_H
#define CONDITION_H
#include <Vector>
class Condition
{
public:
virtual ~Condition() {}
	protected : 
	std::vector<int> indices;
};
#endif