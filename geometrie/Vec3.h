#ifndef VEC3_H
#define VEC3_H
#include "../objLoader/objLoader.h"
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
	
	float operator*(const Vec3& other) const
	{
		return this->x*other.x + this->y*other.y + this->z*other.z;
	}
	
	bool operator==(const Vec3 &other) const {
	return (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
	}
	
	void normalize()
	{
		float n = norm();
		this->x/=n;
		this->y/=n;
		this->z/=n;
	}
	
	float norm() const
	{
		return sqrt(x*x+y*y+z*z);
	}
	
	float x,y,z;
};
#endif