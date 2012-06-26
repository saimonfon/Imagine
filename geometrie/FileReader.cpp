#include "FileReader.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <cmath>

#define EPSILON  0.01
#define MODULUS(p) (sqrt(p.x*p.x + p.y*p.y + p.z*p.z))
#define TWOPI 6.283185307179586476925287
#define RTOD 57.2957795

using namespace std;
vector<Polygone*> FileReader::readFile(string fileName)
{
vector<Polygone*> res;
std::ifstream infile(fileName.c_str());
string line;
//Lecture du fichier et ajout des polygones
while(getline(infile,line))
{
	vector<Vec3> v;
	std::istringstream iss(line);
	float x,y,z;
	//cout<<"POLYGONE"<<endl;
	while(iss>>x>>y>>z)
	{
		v.push_back(Vec3(x,y,z));
		//cout<<x<<" "<<y<<" "<<z<<endl;
	}
	//Calcul de l'équation du plan à partir des 3 premiers points
	Vec3 normale = (v[1]-v[0])^(v[2]-v[0]);
	if(normale.y<0)
		normale = Vec3(0,0,0)-normale;
	normale.normalize();
	float d = - (normale*v[0]);
	Matrice2 rot = rotationPlan(normale,d);
	x = 0;
	vector<point2d> contour;
	for(vector<Vec3>::iterator it = v.begin();it!=v.end();it++)
	{
		//Vec3 new_point = rotationPoint(rot,projectionSurPlan(*it,normale,d));
		Vec3 new_point = rotationPoint(rot,*it);
		//cout<<"Rotated : "<<new_point.x<<" "<<new_point.y<<" "<<new_point.z<<endl;
		x = new_point.x;
		//cout<<new_point.x<<" "<<new_point.y<<" "<<new_point.z<<endl;
		contour.push_back(point2d(new_point.y,new_point.z));
	}
	Polygone* p = new Polygone();
	p->backRot = rot.transpose();
	p->x = x;
	p->setContour(contour);
	p->points3D = v;
	float* equation = new float[4];
	equation[0]  = normale.x;
	equation[1]  = normale.y;
	equation[2]  = normale.z;
	equation[3]  = d;
	p->equation = equation;
	bool pasDedans = true;
	for(int i=0;i<res.size();i++)
	if(res[i]->egal(p))
	{
		pasDedans=false;
		break;
	}
	if(pasDedans)
		res.push_back(p);
}


	
//Précalcul des adjacences
//Ne traite pas les polygones coplanaires
//cf http://stackoverflow.com/questions/6195413/intersection-between-3d-flat-polygons
adj.clear();
for(int i=0;i<res.size();i++)
	for(int j=0;j<res.size();j++)
	{
		bool adjacent=false;
		//S'ils ont un sommet commun, c'est réglé
		for(int k=0;k<res[i]->points3D.size();k++)
			for(int l=0;l<res[j]->points3D.size();l++)
			{
				//cout<<i<<" "<<j<<(res[i]->points3D[k]-res[j]->points3D[l]).norm()<<endl;
				if((res[i]->points3D[k]-res[j]->points3D[l]).norm()<1)
				{
					adj[res[i]].insert(res[j]);
					adj[res[j]].insert(res[i]);
					//cout<<"ADJACENTS "<<i<<" "<<j<<endl;
					adjacent=true;
					break;
				}
			}
		//Sinon
		//Pour chaque arete du premier polygone, intersection avec le plan du second
		for(int k=0;k<res[i]->points3D.size();k++)
		{
			Vec3 p1 = res[i]->points3D[k];
			Vec3 p2 = res[i]->points3D[(k+1)%res[i]->points3D.size()];
			float u = res[j]->equation[0]*p1.x + res[j]->equation[1]*p1.y + res[j]->equation[2]*p1.z + res[j]->equation[3];
			u/= res[j]->equation[0]*(p1.x-p2.x) + res[j]->equation[1]*(p1.y-p2.y) + res[j]->equation[2]*(p1.z-p2.z) + res[j]->equation[3];
			if(u<0||u>1)
				continue;
			Vec3 pt_inter = p1 + Vec3(u*(p2.x-p1.x),u*(p2.y-p1.y),u*(p2.z-p1.z));
			//cout<<pt_inter.x<<","<<pt_inter.y<<","<<pt_inter.z<<endl;
			//cout<<"Arête "<<k<<" du plan "<<i<<" sur plan "<<j<<" : "<<abs(CalcAngleSum(pt_inter,res[j]->points3D)-TWOPI)<<endl;
			if(abs(CalcAngleSum(pt_inter,res[j]->points3D)-TWOPI)<0.1)
			{
				adjacent = true;
				break;
			}
		}
		if(adjacent)
		{
			adj[res[i]].insert(res[j]);
			adj[res[j]].insert(res[i]);
			//cout<<"ADJACENTS "<<i<<" "<<j<<endl;
		}
	}
	

//Affichage des coordonnées 3D pour verif
/*for(int i=0;i<res.size();i++)
{
for(int k=0;k<res[i]->points3D.size();k++)
{
			Vec3 p1 = res[i]->points3D[k];
			cout<<"("<<p1.x<<","<<p1.y<<","<<p1.z<<") ";
			}
			cout<<endl;
			}*/

			//Ecriture dans un fichier texte de l'adjacence pour affichage Matlab
ofstream adjfile;
  adjfile.open ("adja.txt");
  for(int i=0;i<res.size();i++)
  {
	for(int j=0;j<res.size();j++)
		if(adj[res[i]].count(res[j])>0)
			adjfile<<"1 ";
		else
			adjfile<<"0 ";
		adjfile<<endl;
  }
  adjfile.close();

return res;
}

Vec3 FileReader::projectionSurPlan(Vec3 point,Vec3 normale, float d)
{
	float dist = point*normale+d;
	return point - Vec3(dist*point.x,dist*point.y,dist*point.z);
}

Matrice2 FileReader::rotationPlan(Vec3 normale, float d)
{
	float c = normale.x;
	float angle;
	//if(normale.z>=0 && -normale.y>=0)
	if(normale.z<=0)
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

Vec3 FileReader::rotationPoint(Matrice2 rot, Vec3 point)
{
	return Vec3(rot.mat[0][0]*point.x + rot.mat[0][1]*point.z,point.y,rot.mat[1][0]*point.x + rot.mat[1][1]*point.z);
}

// http://paulbourke.net/geometry/insidepoly/
double FileReader::CalcAngleSum(Vec3 q,vector<Vec3> p)
{
   int i;
   double m1,m2;
   double anglesum=0,costheta;
   Vec3 p1,p2;
	int n = p.size();
   for (i=0;i<n;i++) {
		p1 = p[i]-q;
		p2 = p[(i+1)%n] - q;

      m1 = p1.norm();
      m2 = p2.norm();
      if (m1*m2 <= EPSILON)
         return(TWOPI); /* We are on a node, consider this inside */
      else
         costheta = p1*p2 / (m1*m2);
		
      anglesum += acos(costheta);
   }
   return(anglesum);
}