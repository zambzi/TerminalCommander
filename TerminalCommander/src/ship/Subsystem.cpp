/*
 * Subsystem.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: zambzi
 */

#include "Subsystem.h"

Subsystem::Subsystem() : power(50), subsysHealth(Subsystem::MAX_HEALTH){}

Subsystem::~Subsystem() {}

void Subsystem::addPower(int amount){
	power+=amount;
	if(power>Subsystem::MAX_POWER)
		power = Subsystem::MAX_POWER;
}

void Subsystem::removePower(int amount){
	power-=amount;
	if(power<0)
		power=0;
}

void Subsystem::fullPower(){
	power = Subsystem::MAX_POWER;
}

void Subsystem::nullPower(){
	power=0;
}

void Subsystem::update(){

}
