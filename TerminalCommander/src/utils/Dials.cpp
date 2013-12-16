/********************************************//**
 *  \name		Dials
 *  \brief		Small class that allows to get info from ship.
 *  \details
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

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
