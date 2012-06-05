#ifndef MATRICE2_H
#define MATRICE2_H
#include <iostream>
class Matrice2
{
	public:
	float** mat;
	Matrice2();
	Matrice2(float a, float b, float c, float d);
	Matrice2* transpose();
	private:
	void init();
};
#endif