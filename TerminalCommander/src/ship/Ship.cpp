/*
 * Ship.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: zambzi
 */

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

const glm::vec3* Ship::getBearings() const{
	return &bearings;
}

const glm::vec3* Ship::getPosition() const{
	return &position;
}

void Ship::update(){
	rWheels->update();
	thrusters->update(glm::length(velocity));
}

