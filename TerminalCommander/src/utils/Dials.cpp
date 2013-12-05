/*
 * Dials.cpp
 *
 *  Created on: Dec 4, 2013
 *      Author: zambzi
 */

#include "Dials.h"

const Vec3& Dials::getLocation(const Ship& ship){
	return ship.position;
}

const float Dials::getVelocity(const Ship& ship){
	return ship.velocity.getMagnitude();
}

const Vec3& Dials::getBearings(const Ship& ship){
	return ship.bearings;
}

const float& Dials::getThrust(const Ship& ship){
	return ship.thrusters->getThrust();
}




