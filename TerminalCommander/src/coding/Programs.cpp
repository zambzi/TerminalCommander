/*
 * Programs.cpp
 *
 *  Created on: Dec 4, 2013
 *      Author: zambzi
 */

#include "Bindings.h"
#include "../gui/Dialogs.h"

void Bindings::runBinding(CEGUI::String funct, int argc, CEGUI::String* argv){
	if(funct=="echo") echo(argc, argv);
	else if(funct=="thrust") thrust(argc,argv);
	else if(funct=="help") output->append(Dialogs::getInstance()->getDialog(Dialogs::hlpMain));
	else if(funct=="list") output->append(Dialogs::getInstance()->getDialog(Dialogs::hlpList));
	else if(funct=="clear") output->clear();
	else{
		output->append(Dialogs::getInstance()->getDialog(Dialogs::errProgNotFound)+funct);
	}

}

void Bindings::echo(int argc, CEGUI::String* argv){
	for(int i=0; i<argc; i++){
		output->append(argv[i]);
	}
}

/**
 * Thrust program
 * Controls engines.
 * Parameters:
 * -n, -q, -h, -f : null, quater, half, full thrust;
 * -t ## : set thrust to ##. Values: [0,1];
 * -v ## : disable thrust at ## velocity;
 * -? : opens help
 */
void Bindings::thrust(int argc,CEGUI::String* argv){
	for(int i=0; i<argc; i++){
		if(argv[i]=="-n")
			playerShip->thrusters->nullThrust();
		else if(argv[i]=="-q")
			playerShip->thrusters->setThrust(Thrusters::MAX_THRUST/4);
		else if(argv[i]=="-h")
			playerShip->thrusters->setThrust(Thrusters::MAX_THRUST/2);
		else if(argv[i]=="-f")
			playerShip->thrusters->setThrust(Thrusters::MAX_THRUST);
		else if(argv[i]=="-t"){
			if(i+1<argc && isNumber(argv[i+1])){
				float thrust = strtof(argv[i+1].c_str(),NULL);
				if(thrust>Thrusters::MAX_THRUST || thrust<0)
					output->append(Dialogs::getInstance()->getDialog(Dialogs::errParamOutOfScope)+argv[i]);
				else
					playerShip->thrusters->setThrust(thrust);
			}
			else
				output->append(Dialogs::getInstance()->getDialog(Dialogs::errWrongParam)+argv[i]);
		}
		else if(argv[i]=="-v"){
			if(i+1<argc && isNumber(argv[i+1])){
				float velocity = strtof(argv[i+1].c_str(),NULL);
				if(velocity<0)
					output->append(Dialogs::getInstance()->getDialog(Dialogs::errParamOutOfScope)+argv[i]);
				else
					playerShip->thrusters->setThrustToVelocity(velocity);
			}
			else
				output->append(Dialogs::getInstance()->getDialog(Dialogs::errWrongParam)+argv[i]);
		}
		else if(argv[i]=="-?")
			output->append(Dialogs::getInstance()->getDialog(Dialogs::hlpThrust));

	}
}
