#include "ConditionAdj_Int.h"
#include <iostream>

using namespace std;

ConditionAdj_Int::ConditionAdj_Int(int i, string att_i, int j, string att_j){
	this->i = i;
	this->j = j;
	this->att_i = att_i;
	this->att_j = att_j;

	cout << "Creation condition adj_int " << att_i << " " << att_j << endl;

}
