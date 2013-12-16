/********************************************//**
 *  \name		Physics
 *  \brief		Simple space physics
 *  \details
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

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
	void applyForces(Ship* ship);
	void applyTorque(Ship* ship);
	void move(Ship* ship);
};

#endif /* PHYSICS_H_ */
