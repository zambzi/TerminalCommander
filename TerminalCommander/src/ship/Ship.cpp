/********************************************//**
 *  \name		Ship
 *  \brief		Core Ship class
 *  \details	Controls all the subsystems of player ship and stores core info.
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#include "Ship.h"

Ship::Ship():mass(10){
	position = glm::vec3(0,0,0);
	bearings = glm::vec3(1.0f,0,0);
	velocity = glm::vec3(0,0,0);
	thrusters = new Thrusters();
	nav = new Nav();
	rWheels = new ReactionWheels();
}

Ship::~Ship() {
	delete thrusters;
	delete nav;
	delete rWheels;
}

const glm::vec3 Ship::getBearings() const{
	return bearings;
}

const glm::vec3 Ship::getPosition() const{
	return position;
}

void Ship::update(){
	rWheels->update();
	thrusters->update(glm::length(velocity));
}

