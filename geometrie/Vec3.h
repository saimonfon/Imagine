#ifndef VEC3_H
#define VEC3_H
#include "objLoader/objLoader.h"
#include <cmath>
class Vec3
{
	public:
	Vec3()
	{
		this->x = this->y = this->z = 0;
	}
	Vec3(float x, float y, float z)
	{
		this->x=x;
		this->y=y;
		this->z=z;
	}
	
	Vec3(obj_vector* v)
	{
		this->x = v->e[0];
		this->y = v->e[1];
		this->z = v->e[2];
	}
	
	Vec3(obj_vector* p1,obj_vector* p2)
	{
		this->x = p2->e[0]-p1->e[0];
		this->y = p2->e[1]-p1->e[1];
		this->z = p2->e[2]-p1->e[2];
	}
	
	const Vec3 operator^(const Vec3& other) const
	{
		return Vec3(this->y*other.z-this->z*other.y,this->z*other.x-this->x*other.z,this->x*other.y-this->y*other.x);
	}
	
	const Vec3 operator-(const Vec3& other) const
	{
		return Vec3(this->x-other.x,this->y-other.y,this->z-other.z);
	}
	
	const Vec3 operator+(const Vec3& other) const
	{
		return Vec3(this->x+other.x,this->y+other.y,this->z+other.z);
	}
	
	const bool operator<(const Vec3& other) const
	{
		if(this->x < other.x){return true;}
		if(this->x == other.x){
			if(this->y < other.y){return true;}
			if(this->y == other.y){
				if(this->z < other.z){return true;}
			}
		}
		return false;
	}

	void operator+=(const Vec3& other)
	{
		this->x+=other.x;
		this->y+=other.y;
		this->z+=other.z;
	}
	
	float operator*(const Vec3& other) const
	{
		return this->x*other.x + this->y*other.y + this->z*other.z;
	}
	
	bool operator==(const Vec3 &other) const {
	return (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
	}
	
	Vec3 normalize()
	{
		float n = norm();
		this->x/=n;
		this->y/=n;
		this->z/=n;
		return *this;
	}
	
	float norm() const
	{
		return sqrt(x*x+y*y+z*z);
	}
	
	void inverserYetZ()
	{	
		float tmp = y;
		y=z;
		z=tmp;
	}

	Vec3 projetePlan(float* eq)
	{
		float xp = (eq[1]*eq[1]+eq[2]*eq[2])*x - eq[0]*eq[1]*y - eq[0]*eq[2]*z - eq[0]*eq[3];
		float yp = - eq[0]*eq[1]*x + (eq[0]*eq[0]+eq[2]*eq[2])*y - eq[1]*eq[2]*z - eq[1]*eq[3];
		float zp = - eq[0]*eq[2]*x - eq[1]*eq[2]*y - (eq[0]*eq[0]+eq[1]*eq[1])*z - eq[2]*eq[3];
		return Vec3(xp,yp,zp);
	}
	
	float distancePlan(float* eq)
	{
		return fabs (eq[0]*x + eq[1]*y + eq[2]*z + eq[3]);
	}
	
	float x,y,z;
};
#endif
