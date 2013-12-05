/*
 * Ship.h
 *
 *  Created on: Dec 3, 2013
 *      Author: zambzi
 */

#ifndef SHIP_H_
#define SHIP_H_


#include "../main/stdafx.h"
#include "../utils/Vec3.h"
#include "Thrusters.h"

class Ship {
private:
	Vec3		position;
	Vec3		bearings;
	Vec3		velocity;

	const int	mass;

public:
	Thrusters* 	thrusters;

public:
	Ship();
	~Ship();
	friend class Physics;
	friend class Dials;

	void update();
};

#endif /* SHIP_H_ */
