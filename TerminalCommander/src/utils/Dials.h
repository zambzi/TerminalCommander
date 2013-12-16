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

#ifndef DIALS_H_
#define DIALS_H_

#include "../ship/Ship.h"

class Dials {
public:
	static const glm::vec3 getLocation(const Ship& ship);
	static const float getVelocity(const Ship& ship);
	static const glm::vec3 getBearings(const Ship& ship);
	static const float getThrust(const Ship& ship);
	static const glm::vec3 getNav(const Ship& ship);
};

#endif /* DIALS_H_ */
