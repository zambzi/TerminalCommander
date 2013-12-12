/*
 * Dials.cpp
 *
 *  Created on: Dec 4, 2013
 *      Author: zambzi
 */

#include "Dials.h"

const glm::vec3 Dials::getLocation(const Ship& ship){
	return ship.position;
}

const float Dials::getVelocity(const Ship& ship){
	return glm::length(ship.velocity);
}

const glm::vec3 Dials::getBearings(const Ship& ship){
	return ship.bearings;
}

const float Dials::getThrust(const Ship& ship){
	return ship.thrusters->getThrust();
}

const glm::vec3 Dials::getNav(const Ship& ship){
	return ship.nav->getNav();
}
