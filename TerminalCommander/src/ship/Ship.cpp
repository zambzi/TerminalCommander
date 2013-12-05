/*
 * Ship.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: zambzi
 */

#include "Ship.h"

Ship::Ship():mass(10){
	position = new Vec3();
	bearings = new Vec3();
	velocity = new Vec3();
	thrusters = new Thrusters();
}

Ship::~Ship() {
	delete thrusters;
}

void Ship::update(){
	thrusters->update(velocity.getMagnitude());
}

