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
ObjReader(string fileName);
Modele* polygones();
private :
map<Polygone*, set<Polygone*> > adj;
objLoader *objData;
Vec3 normale(obj_face* f,obj_vector** vertices);
Vec3* normales;
Polygone* composante(int i,int cur_comp,bool* marque);
vector<int>* incidence;
int* composantes;
	//vector<Polygone*> res;
};
#endif