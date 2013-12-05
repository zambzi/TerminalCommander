/*
 * Physics.h
 *
 *  Created on: Dec 4, 2013
 *      Author: zambzi
 */

#ifndef PHYSICS_H_
#define PHYSICS_H_

#include "Ship.h"

class Physics {
private:
	Ship* playerShip;
	static const int V_COEFFICIENT = 1000;

public:
	Physics(Ship* playerShip);
	~Physics();

	void update();

private:
	void thrustApply(Ship* ship);
	void move(Ship* ship);
};

#endif /* PHYSICS_H_ */
