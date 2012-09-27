#ifndef OBJ_LOADER
#define OBJ_LOADER
#include "objLoader/objLoader.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Modele.h"
#include "Polygone.h"
class Vec3;
class ObjReader
{
public :
	ObjReader();
	ObjReader(string fileName);
	Modele* polygones();
	Modele* polygones2(float epsilon);
	static Vec3 normale(obj_face* f,obj_vector** vertices);
	objLoader *objData;
private :

	map<Polygone*, set<Polygone*> > adj;
	map<Polygone*, set<Polygone*> > adj_edge_ext;
	map<Polygone*, set<Polygone*> > adj_edge_int;

	Vec3* normales;
	Polygone* composante(int i,int cur_comp,bool* marque);
	Polygone* composante2(int i,int cur_comp,bool* marque,
			set<pair<Vec3,Vec3> > seg_ext,
			set<pair<Vec3,Vec3> > seg_int);
	set<int>* incidence;
	set<int>* incidence_faces;
	int* composantes;
	//vector<Polygone*> res;
};
#endif
