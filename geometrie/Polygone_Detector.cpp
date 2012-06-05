#include "Polygone_Detector.h"
#include <iostream>
#include <list>
#include <cmath>
#include "../convexhull/GrahamScanConvexHull.h"

using namespace std;
vector<Polygone*> Polygone_Detector::detect(obj_face** faces, int nbFaces, obj_vector** vertices)
{
vector<Polygone*> res;
bool* treated = new bool[nbFaces];
for (int i=0;i<nbFaces;i++)
	treated[i] = false;
int faces_number = 0;

//Précalcul des normales
Vec3* normales = new Vec3[nbFaces];
for (int i=0;i<nbFaces;i++)
	normales[i] = this->normale(faces[i],vertices);
	
std::cout<<"OK cii"<<endl;

//Précalcul des adjacences
vector<vector<int> > adj;
adj.resize(nbFaces);
for(int i=0;i<nbFaces;i++)
{
if(i%10==0)
cout<<i<<endl;
	for(int j=0;j<nbFaces;j++)
		if(i!=j&&adjacent(faces[i],faces[j],vertices))
			adj[i].push_back(j);
}			
std::cout<<"OK cii"<<endl;
	
for (int i=0;i<nbFaces;i++)
{
	if(treated[i])
		continue;
	cout<<"Treating face"<<i<<endl;
	//cout<<faces[i]->vertex_count<<endl;
	float d = - (normales[i]*Vec3(vertices[faces[i]->vertex_index[0]]));
	Matrice2 rot = rotationPlan(normales[i],d);
	float x=0;
	std::list<int> l;
	std::vector<point2d> points;
	std::vector<unsigned short> belongingFaces;
	l.push_back(i);
	while(!l.empty())
	{
		int j = l.front();
		l.pop_front();
		treated[j] = true;
		for(int ind=0;ind<3;ind++)
		{
			Vec3 new_point = rotationPoint(rot,projectionSurPlan(Vec3(vertices[faces[j]->vertex_index[ind]]),normales[i],d));
			belongingFaces.push_back((unsigned short)faces[j]->vertex_index[ind]);
			x = new_point.x;
			points.push_back(point2d(new_point.y,new_point.z));
			
		}
			
		for(int k_ind = 0;k_ind<adj[j].size();k_ind++)
		{
			int k = adj[j][k_ind];
			if(treated[k]||k==j||(!adjacent(faces[j],faces[k],vertices)))
				continue;
			if(abs(normales[i]*normales[k])<0.99) //Autorise une déviation de 8°
				continue;
			//cout<<"OK ON A TROUVE UNE FACE ADJACENTE"<<endl;
			l.push_back(k);
		}
	}
	Polygone* p = new Polygone();
    std::vector<point2d> convex_hull;
	GrahamScanConvexHull()(points, convex_hull);
	p->backRot = rot.transpose();
	p->x = x;
	p->setContour(convex_hull);
	p->nb_faces = belongingFaces.size()/3;
	p->belongingFaces = new unsigned short [belongingFaces.size()];
	copy( belongingFaces.begin(), belongingFaces.end(), p->belongingFaces);
	
	res.push_back(p);
	faces_number++;
}
cout<<"Nombre de polygones détectés "<<faces_number<<endl;
vector<Polygone*> kept;
for(int i=0;i<res.size();i++)
	if((res[i])->getArea() > 0.001)
		kept.push_back(res[i]);
	else cout<<"Polygone rejeté d'aire"<<res[i]->getArea()<<endl;
		
return kept;
}

bool Polygone_Detector::adjacent(obj_face* f1,obj_face* f2, obj_vector** vertices)
{
	int nb_sommets_communs=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			Vec3 v1(vertices[f1->vertex_index[i]],vertices[f2->vertex_index[j]]);
			if(v1.norm()<0.1)
			{
				nb_sommets_communs++;
				break;
			}
		}
	}
	if(nb_sommets_communs==2)
		return true;
	return false;
}

Vec3 Polygone_Detector::normale(obj_face* f,obj_vector** vertices)
{
	Vec3 v1(vertices[f->vertex_index[1]],vertices[f->vertex_index[0]]);
	Vec3 v2(vertices[f->vertex_index[2]],vertices[f->vertex_index[0]]);
	Vec3 normale = v1^v2;
	normale.normalize();
	return normale;
}

Vec3 Polygone_Detector::projectionSurPlan(Vec3 point,Vec3 normale, float d)
{
	float dist = point*normale+d;
	return point - Vec3(dist*point.x,dist*point.y,dist*point.z);
}

Matrice2 Polygone_Detector::rotationPlan(Vec3 normale, float d)
{
	float c = normale.x;
	float angle;
	if(normale.z>=0 && -normale.y>=0)
		angle = acos(c);
	else
		angle = -acos(c);
	Matrice2 rot;
	rot.mat[0][0] = cos(angle);
	rot.mat[0][1] = -sin(angle);
	rot.mat[1][0] = sin(angle);
	rot.mat[1][1] = cos(angle);
	return rot;
}

Vec3 Polygone_Detector::rotationPoint(Matrice2 rot, Vec3 point)
{
	return Vec3(rot.mat[0][0]*point.x + rot.mat[0][1]*point.z,point.y,rot.mat[1][0]*point.x + rot.mat[1][1]*point.z);
}