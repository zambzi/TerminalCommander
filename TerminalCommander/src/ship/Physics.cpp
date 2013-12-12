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

Physics::~Physics() {}

void Physics::applyForces(Ship* ship){

	ship->velocity.x+=ship->bearings.x*ship->thrusters->getThrust()/(float)ship->mass;
	ship->velocity.y+=ship->bearings.y*ship->thrusters->getThrust()/(float)ship->mass;
	ship->velocity.z+=ship->bearings.z*ship->thrusters->getThrust()/(float)ship->mass;
}

void Physics::applyTorque(Ship* ship){
	if(ship->rWheels->getAngleIncrement()!=0){
		ship->bearings = glm::rotate(ship->bearings, ship->rWheels->getAngleIncrement(),ship->rWheels->getNormalVector());
		ship->bearings = glm::normalize(ship->bearings);
	}
}

void Physics::move(Ship* ship){
	ship->position.x+=ship->velocity.x/Physics::V_COEFFICIENT;
	ship->position.y+=ship->velocity.y/Physics::V_COEFFICIENT;
	ship->position.z+=ship->velocity.z/Physics::V_COEFFICIENT;
}

void Physics::update(){
	applyTorque(playerShip);
	applyForces(playerShip);
	move(playerShip);
}
