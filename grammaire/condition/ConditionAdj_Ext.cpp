#include "ConditionAdj_Ext.h"
#include <iostream>

using namespace std;

ConditionAdj_Ext::ConditionAdj_Ext(int i, string att_i, int j, string att_j){
	this->i = i;
	this->j = j;
	this->att_i = att_i;
	this->att_j = att_j;

	cout << "Creation condition adj_ext " << att_i << " " << att_j << endl;

}
