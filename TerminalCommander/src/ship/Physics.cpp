/*
 * Physics.cpp
 *
 *  Created on: Dec 4, 2013
 *      Author: zambzi
 */

#include "Physics.h"

Physics::Physics(Ship* playerShip) {
	this->playerShip = playerShip;
}

Physics::~Physics() {
	// TODO Auto-generated destructor stub
}

void Physics::thrustApply(Ship* ship){
	//TODO: add bearings;

	ship->velocity.x+=ship->thrusters->getThrust()/(float)ship->mass;
	ship->velocity.y+=ship->thrusters->getThrust()/(float)ship->mass;
	ship->velocity.z+=ship->thrusters->getThrust()/(float)ship->mass;
}

void Physics::move(Ship* ship){
	ship->position.x+=ship->velocity.x/Physics::V_COEFFICIENT;
	ship->position.y+=ship->velocity.y/Physics::V_COEFFICIENT;
	ship->position.z+=ship->velocity.z/Physics::V_COEFFICIENT;
}

void Physics::update(){
	thrustApply(playerShip);
	move(playerShip);
}
