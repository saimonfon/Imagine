#include "Matrice2.h"

Matrice2::Matrice2()
	{
		init();
	}

	Matrice2::Matrice2(float a, float b, float c, float d)
	{
		init();
		mat[0][0] = a;
		mat[0][1] = b;
		mat[1][0] = c;
		mat[1][1] = d;
	}
	
	Matrice2* Matrice2::transpose()
	{	
		return new Matrice2(this->mat[0][0],this->mat[1][0],this->mat[0][1],this->mat[1][1]);
	}
	
	void Matrice2::init()
	{
		mat = new float*[2];
		mat[0] = new float[2];
		mat[1] = new float[2];
	}