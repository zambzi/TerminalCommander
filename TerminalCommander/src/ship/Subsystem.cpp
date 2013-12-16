/********************************************//**
 *  \name		Subsystem
 *  \brief		Basic common implementation of a ship subsystem.
 *  \details	Provides most common functionality shared between every
 *  			ship subsystem, like power and communication.
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#include "Subsystem.h"
#include "../gui/ShipInterface.h"

Subsystem::Subsystem() : power(100), subsysHealth(Subsystem::MAX_HEALTH){}

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

void Subsystem::sendMessage(Dialogs::msg message){
	ShipInterface::getInstance()->outputConsole->append(Dialogs::getInstance()->getDialog(message));
}
