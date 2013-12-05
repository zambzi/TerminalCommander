/*
 * Thrusters.h
 *
 *  Created on: Dec 3, 2013
 *      Author: zambzi
 */

#ifndef THRUSTERS_H_
#define THRUSTERS_H_


#include "Subsystem.h"

class Thrusters: public Subsystem {
public:
	const static float	MAX_THRUST=1.0;
	const static float	THRUST_CHANGE_RATE = 0.006;

private:
	float 				thrust;
	float				desiredThrust;
	float				desiredVelocity;

	bool				thrustChange;
	bool				speedMatching;


public:
	Thrusters();
	~Thrusters();

	void setThrust(float value);
	void setThrustToVelocity(float velocity);
	void fullThrust();
	void nullThrust();
	const float getThrust();

	void update(const float currentVelocity);

private:
	void changeThrust();
	void matchToSpeed(const float currentVelocity);
};

#endif /* THRUSTERS_H_ */
