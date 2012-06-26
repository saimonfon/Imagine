#include "Polygone.h"

void Polygone::setContour(vector<point2d> c)
{
		this->contour = c;
		this->computeArea();
		
		//this->computePoints3D(); //A remettre quand ça marchera
	}
	
float Polygone::getArea()
	{
		return area;
	}
	
void Polygone::computeArea()
{
		int n = contour.size();
		area = 0;
		for(int i=0;i<n;i++)
			area += contour[i].x*contour[(i+1)%n].y - contour[i].y*contour[(i+1)%n].x;
		area = abs(area)/2;
}

/** Calcule les points 3D du polygone à partir des points 2D et de la matrice de rotation.
* Attention : ne marche pas !!*/
void Polygone::computePoints3D()
{
	//cout<<"Computing 3d points"<<endl;
	points3D = vector<Vec3>();
	float** m = this->backRot->mat;
	//cout<<"Computing 3d points 2"<<endl;
	//cout<<m[0][0]<<endl;
	for(int i=0;i<contour.size();i++)
	{
		point2d p  = contour[i];
		points3D.push_back(Vec3(m[0][0]*this->x + m[0][1]*p.y,p.x,m[1][0]*this->x + m[1][1]*p.y));
	}
}

bool Polygone::egal(const Polygone* p) const
{
	return this->points3D == p->points3D;
}

Vec3& Polygone::operator[](int i)
{
	return points3D[i];
}

int Polygone::size()
{
	return points3D.size();
}