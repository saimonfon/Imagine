#ifndef POLYGONE_H
#define POLYGONE_H
#include <vector>
#include "../convexhull/ConvexHull.h"
#include "Vec3.h"
#include "Matrice2.h"
#include <cmath>
using namespace std;
class Polygone
{
	public:
	void setContour(vector<point2d> c);
	float getArea();
	vector<point2d> contour;
	vector<Vec3> points3D;
	float x;
	Matrice2* backRot;
	float* equation;
	unsigned short* belongingFaces;
	int nb_faces;
	//Rajouter les trous
	
	private:
	float area;
	void computeArea();
	void computePoints3D();

};
#endif