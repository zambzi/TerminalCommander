/*
 * Vec3.cpp
 *
 *  Created on: Dec 4, 2013
 *      Author: zambzi
 */

#include "Vec3.h"
#include <math.h>

Vec3::Vec3() : x(0), y(0), z(0) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3::Vec3(Vec3* vec3) : x(vec3->x), y(vec3->y), z(vec3->z) {}

Vec3::~Vec3() {
	// TODO Auto-generated destructor stub
}

void Vec3::setCoords(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vec3::setCoords(Vec3* vec3){
	this->x = vec3->x;
	this->y = vec3->y;
	this->z = vec3->z;
}

float Vec3::getMagnitude() const{
	return sqrt(x*x+y*y+z*z);
}

void Vec3::normalize(){
	float magnitude = getMagnitude();
	x/=magnitude;
	y/=magnitude;
	z/=magnitude;
}
/*
Vec3& Vec3::operator=(const Vec3& vec3){
	if(this == &vec3)
		return *this;

	this->x=vec3.x;
	this->y=vec3.y;
	this->z=vec3.z;
	return *this;
}

Vec3& Vec3::operator+(const Vec3& vec3){
	this->x+=vec3.x;
	this->y+=vec3.y;
	this->z+=vec3.z;
	return *this;
}

Vec3& Vec3::operator-(const Vec3& vec3){

	this->x-=vec3.x;
	this->y-=vec3.y;
	this->z-=vec3.z;
	return *this;
}
*/
