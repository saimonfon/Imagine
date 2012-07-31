#ifndef MODELE_H
#define MODELE_H
#include <map>
#include "Polygone.h"
#include <vector>
#include <set>
class Modele
{
public : 
Modele(vector<Polygone*> polygones, map<Polygone*, set<Polygone*> > adj, bool triangule)
{
isObj = triangule;
this->polygones=  polygones;
this->adj  =adj;
}

void normaliser()
{
/* Scaling pour que le modèle soit inclus dans le carré de côté 1*/
float max_size=0;	
for(vector<Polygone*>::iterator it = polygones.begin();it!=polygones.end();it++)
{
for(vector<Vec3>::iterator it2 = (*it)->points3D.begin();it2!=(*it)->points3D.end();it2++)
{
  if((*it2).x > max_size)
	max_size = (*it2).x;
  if((*it2).y > max_size)
	max_size = (*it2).y;
	  if((*it2).z > max_size)
	max_size = (*it2).z;
}
}
float scale = 1 / max_size;

for(vector<Polygone*>::iterator it = polygones.begin();it!=polygones.end();it++)
{
for(vector<Vec3>::iterator it2 = (*it)->points3D.begin();it2!=(*it)->points3D.end();it2++)
{
  it2->x  =it2->x*scale;
  it2->y  =it2->y*scale;
  it2->z  =it2->z*scale;
}

for(vector<Vec3*>::iterator it2 = (*it)->triangles.begin();it2!=(*it)->triangles.end();it2++)
{
	for(int k=0;k<3;k++)
	{
  (*it2)[k].x  =(*it2)[k].x*scale;
  (*it2)[k].y  =(*it2)[k].y*scale;
  (*it2)[k].z  =(*it2)[k].z*scale;
  }
}
}
}

void inverserAxes()
{
for(vector<Polygone*>::iterator it = polygones.begin();it!=polygones.end();it++)
{
	for(vector<Vec3>::iterator it2 = (*it)->points3D.begin();it2!=(*it)->points3D.end();it2++)
	{
	//cout<<it2->y<<" "<<it2->z;
		it2->inverserYetZ();
	//cout<<"--->"<<it2->y<<" "<<it2->z<<endl;
	}
}
}

void setEchelle(float echelle)
{
this->echelle = echelle;
for(vector<Polygone*>::iterator it = polygones.begin();it!=polygones.end();it++)
{
	(*it)->computeAttributs();
	(*it)->area /= (echelle*echelle);
	cout<<(*it)->getArea()<<"\n";
	}
}
vector<Polygone*> polygones;
map<Polygone*, set<Polygone*> > adj;
float echelle;
bool isObj;
bool estTriangule(){return isObj;}
};
#endif