/*
 * Dials.h
 *
 *  Created on: Dec 4, 2013
 *      Author: zambzi
 */

#ifndef DIALS_H_
#define DIALS_H_

#include "Vec3.h"
#include "../ship/Ship.h"

class Dials {
public:
	static const Vec3& getLocation(const Ship& ship);
	static const float getVelocity(const Ship& ship);
	static const Vec3& getBearings(const Ship& ship);
	static const float& getThrust(const Ship& ship);
};

#endif /* DIALS_H_ */
