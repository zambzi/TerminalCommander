/********************************************//**
 *  \name		Thrusters
 *  \brief		Thrusters subsystem implementation
 *  \details
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

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
	sendMessage(Dialogs::infThrustInProgress);
	desiredThrust = value;
	thrustChange = true;
}

void Thrusters::setThrustToVelocity(float velocity){
	sendMessage(Dialogs::infBurnInProgress);
	desiredVelocity = velocity;
	speedMatching = true;
}

void Thrusters::fullThrust(){
	sendMessage(Dialogs::infThrustInProgress);
	desiredThrust = Thrusters::MAX_THRUST;
	thrustChange = true;
}

void Thrusters::nullThrust(){
	sendMessage(Dialogs::infThrustInProgress);
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
		sendMessage(Dialogs::infThrustFinished);
	}

	if(thrust<0){
		thrust=0;
		thrustChange = false;
		sendMessage(Dialogs::infThrustFinished);
	}

	if(thrust<desiredThrust+Thrusters::THRUST_CHANGE_RATE*2 &&
			thrust>desiredThrust-Thrusters::THRUST_CHANGE_RATE*2){
		thrust=desiredThrust;
		thrustChange = false;
		sendMessage(Dialogs::infThrustFinished);
	}

}

//TODO: finish burn
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

