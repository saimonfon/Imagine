#include "Polygone.h"

void Polygone::setContour(vector<point2d> c)
{
		this->contour = c;
	}
	
float Polygone::getArea()
	{
return area;
	}

/** Calcule les points 3D du polygone à partir des points 2D et de la matrice de rotation.
* Attention : ne marche pas !!*/
void Polygone::computePoints3D()
{
	points3D = vector<Vec3>();
	float** m = this->backRot->mat;
	for(unsigned int i=0;i<contour.size();i++)
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

/** Calcule la normale et l'aire (http://thebuildingcoder.typepad.com/blog/2008/12/3d-polygon-areas.html) */
void Polygone::computeAttributs()
{
int n = points3D.size();
Vec3 a(0,0,0);
Vec3 b = points3D[n-2];
Vec3 c = points3D[n-1];
Vec3 normale(0,0,0);
for( int i = 0; i < n; ++i ) {
      a = b;
      b = c;
      c = points3D[i];
 
      normale.x += b.y * ( c.z - a.z );
      normale.y += b.z * ( c.x - a.x );
      normale.z += b.x * ( c.y - a.y );
    }
area = normale.norm()/2;
normale.normalize();
equation = new float[4];
equation[0] = normale.x;
equation[1] = normale.y;
equation[2] = normale.z;
}