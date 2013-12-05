/*
 * Dialogs.cpp
 *
 *  Created on: Dec 5, 2013
 *      Author: zambzi
 */

#include "Dialogs.h"

bool Dialogs::instanceExist = false;
Dialogs* Dialogs::dialogs = NULL;


Dialogs::~Dialogs() {
	instanceExist=false;
}

Dialogs* Dialogs::getInstance(){
	if(!instanceExist){
		dialogs = new Dialogs();
		instanceExist = true;
		dialogs->setDialogs();
		return dialogs;
	}
	else
		return dialogs;
}

//TODO: make that into xml
void Dialogs::setDialogs(){
	dialogMap[errArgNotFound] = "Error: argument not found: ";
	dialogMap[errProgNotFound] = "Error: no program with name: ";
	dialogMap[errWrongParam] = "Error: wrong parameter for: ";
	dialogMap[errParamOutOfScope] = "Error: parameter out of scope: ";

	dialogMap[infThrustInProgress] = "Thrust in progress...";
	dialogMap[infThrustFinished] = "Thrust finished.";
	dialogMap[infBurnInProgress] = "Burn to match speed in progress...";
	dialogMap[infBurnFinished] = "Burn finished. Thrusters disabled.";

	dialogMap[hlpThrust] = 	"\n\n\nThrust Program:\n"
							"Allows to control engines output.\n\n"
							"Arguments:\n"
							"  -n    : disables thrusters.\n"
							"  -f    : sets thrusters to full thrust\n"
							"  -q    : sets thrusters to quarter thrust\n"
							"  -h    : sets thrusters to half thrust\n"
							"  -t ## : sets thrust to manual value ## in scope [0,1], where 1 is maximum thrust\n"
							"  -v ## : sets engines to burn at full speed until reaching ## velocity. ## must be positive. Keep in mind: you must align your ship towards or against your speed vector to take full advantage of this argument. See 'nav -?' for help.\n"
							"  -?    : shows this help menu\n\n"
							"Examples:\n"
							"  thrust -t 0.6  :sets thrust to 0.6 output\n"
							"  thrust -q  :sets thrust to quarter output\n"
							"  thrust -v 120  :starts burn to reach speed of 120";

	dialogMap[hlpMain] = 	"\n\n\nGlobal help\n"
							"If you're using this file, then this means, that ship's OS is bricked... hopefully you're not in deep space right now.\n"
							"Anyway - this command console was created specifically for such occasion, and it is our task to help you out in your survival.\n\n"
							"To control ship, you'll need to execute appropriate programs and learn about program arguments and parameters.\n"
							"Our terminal execution syntax goes as follows:\n\n"
							"  PROGRAM_NAME ARG1 ARG2 .. ARGn\n\n"
							"Let's say, we have a program with the name 'thrust', that controls engines. Program takes argument '-t' that tells it at what thrust engines need to work. To specify the thrust, we use PARAMETERS: \n\n"
							"  thrust -t 0.7\n\n"
							"As you can see: this calls program 'thrust' with argument '-t' and parameter to this argument '0.7', which will operate engines at thrust level 0.7.\n"
							"Too see more info about any program arguments or parameters: \n\n"
							"  PROGRAM_NAME -?\n\n"
							"This will print help file for given program.\n\n"
							"Also, you can use 'list' to print all installed programs in the system.";

	dialogMap[hlpList] = 	"\n\n\nPrograms List:\n\n"
							"help - shows global helpfile\n"
							"list - shows this list\n"
							"clear - clears output console\n"
							"thrust - controls engine output\n"
							"nav - controls navigation\n";

	dialogMap[msgWelcome] = 	"Welcome to Terminal Commander Emergency Console!\n\n"
								"Your current OS is unable to boot, error code: 518\n"
								"---Error message---\n\n"
								"We're sorry, but your Portholes8 Operating System (TM) Mid-Aged Enterprise Spacer User License has expired.\n\n"
								"If you're interested in renewing your Mid-Aged Enterprise Spacer User License for another month, please visit our shop at: galaxy://flaccidSoft.shop.xeno\n\n"
								"Have a nice flight!\n\n"
								"---End of message---\n"
								"Type 'help' to see helpfile";

}

CEGUI::String Dialogs::getDialog(Dialogs::msg message){
	return dialogMap[message];
}
