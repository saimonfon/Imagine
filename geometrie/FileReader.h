#ifndef FILE_READER_H
#define FILE_READER_H
#include <vector>
#include "Modele.h"
#include "Vec3.h"
#include "Matrice2.h"
#include <string>
#include <set>
#include <map>
class FileReader
{
	public : 
	Modele* readFile(string fileName);
	Vec3 normale(obj_face* f,obj_vector** vertices);
	Vec3 projectionSurPlan(Vec3 point,Vec3 normale, float d);
	Matrice2 rotationPlan(Vec3 normale, float d);
	Vec3 rotationPoint(Matrice2 rot, Vec3 point);
	double CalcAngleSum(Vec3 q,vector<Vec3> p);
};
#endif