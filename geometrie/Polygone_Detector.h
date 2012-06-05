#ifndef POLYGONE_DETECTOR_H
#define POLYGONE_DETECTOR_H
#include <vector>
#include "Polygone.h"
#include "Vec3.h"
#include "../objLoader/objLoader.h"
#include "Matrice2.h"
class Polygone_Detector
{
	public : 
	vector<Polygone*> detect(obj_face** faces,int nbFaces,obj_vector** vertices);
	bool adjacent(obj_face* f1,obj_face* f2,obj_vector** vertices);
	Vec3 normale(obj_face* f,obj_vector** vertices);
	Vec3 projectionSurPlan(Vec3 point,Vec3 normale, float d);
	Matrice2 rotationPlan(Vec3 normale, float d);
	Vec3 rotationPoint(Matrice2 rot, Vec3 point);
};
#endif