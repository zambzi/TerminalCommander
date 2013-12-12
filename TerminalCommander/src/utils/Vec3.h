/*
 * Vec2.h
 *
 *  Created on: Dec 4, 2013
 *      Author: zambzi
 */

#ifndef VEC3_H_
#define VEC3_H_

class Vec3 {
public:
	float x;
	float y;
	float z;

public:
	Vec3();
	Vec3(float x, float y, float z);
	Vec3(const Vec3* vec3);
	~Vec3();

	void setCoords(float x, float y, float z);
	void setCoords(Vec3* vec3);
	float getMagnitude() const;
	void normalize();
/*
	Vec3& operator=(const Vec3& vec3);
	Vec3& operator+(const Vec3& vec3);
	Vec3& operator-(const Vec3& vec3);
	*/
};

#endif /* VEC3_H_ */
