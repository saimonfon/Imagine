#ifndef OBJ_LOADER
#define OBJ_LOADER
#include "objLoader/objLoader.h"
#include <string>
#include <vector>
#include "Polygone.h"
class Vec3;
class ObjReader
{
public :
ObjReader(string fileName);
vector<Polygone*> polygones();
private :
objLoader *objData;
Vec3 normale(obj_face* f,obj_vector** vertices);
Vec3* normales;
Polygone* composante(int i,bool* marque);
vector<int>* incidence;
};
#endif