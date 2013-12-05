/*
 * Thrusters.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: zambzi
 */

#include "Thrusters.h"

Thrusters::Thrusters(){
	thrust=0;
	desiredThrust=0;
	desiredVelocity=0;
	thrustChange=false;
	speedMatching=false;
}

Thrusters::~Thrusters() {}

void Thrusters::setThrust(float value){
	desiredThrust = value;
	thrustChange = true;
}

void Thrusters::setThrustToVelocity(float velocity){
	desiredVelocity = velocity;
	speedMatching = true;
}

void Thrusters::fullThrust(){
	desiredThrust = Thrusters::MAX_THRUST;
	thrustChange = true;
}

void Thrusters::nullThrust(){
	desiredThrust = 0;
	thrustChange = true;
}

void Thrusters::changeThrust(){
	float powerModifier = (float)power/100.0;
	int sign = (thrust-desiredThrust<0)? 1 : -1;
	thrust+=Thrusters::THRUST_CHANGE_RATE*sign*powerModifier;

	if(thrust>=Thrusters::MAX_THRUST*powerModifier){
		thrust=Thrusters::MAX_THRUST*powerModifier;
		thrustChange = false;
	}

	if(thrust<0){
		thrust=0;
		thrustChange = false;
	}

	if(thrust<desiredThrust+Thrusters::THRUST_CHANGE_RATE*2 &&
			thrust>desiredThrust-Thrusters::THRUST_CHANGE_RATE*2){
		thrust=desiredThrust;
		thrustChange = false;
	}

}

void Thrusters::matchToSpeed(const float currentVelocity){
	thrustChange = true;
	if(currentVelocity>desiredVelocity){}
}

void Thrusters::update(const float currentVelocity){
	if(thrustChange)
		changeThrust();
	if(speedMatching)
		matchToSpeed(currentVelocity);
}

const float Thrusters::getThrust(){
	return thrust;
}

