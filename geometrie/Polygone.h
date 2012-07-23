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
	void computeAttributs();
	float getArea();
	int number;
	vector<point2d> contour;
	vector<Vec3> points3D;
	float x;
	Matrice2* backRot;
	float* equation;
	unsigned short* belongingFaces;
	int nb_faces;
	vector<Polygone*> trous;
	bool egal(const Polygone* p) const;
	Vec3& operator[](int i);
	int size();
	private:
	void computePoints3D();
float area;
};
#endif