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
	dialogMap[errParamNotFound] = 		"Error: parameter not found: ";
	dialogMap[errValNotFound] = 		"Error: no program with name: ";
	dialogMap[errWrongVal] = 			"Error: wrong value for: ";
	dialogMap[errValOutOfScope] = 		"Error: value out of scope: ";
	dialogMap[errNavMemEmpty] =			"Error: Navigation memory is empty. Use 'nav -s [name] [x] [y] [z] to save new value.";
	dialogMap[errCantFindNav] =			"Error: Cannot find navigation target: ";
	dialogMap[errCurrNA] =				"Error: functionality currently not available.";

	dialogMap[infThrustInProgress] = 	"Thrust change in progress...";
	dialogMap[infThrustFinished] = 		"Thrust change finished.";
	dialogMap[infBurnInProgress] = 		"Burn to match speed in progress...";
	dialogMap[infBurnFinished] = 		"Burn finished. Thrusters disabled.";
	dialogMap[infRotationInProgress] = 	"Ship rotation in progress...";
	dialogMap[infRotationFinished] = 	"Ship rotation finished.";

	dialogMap[infNavSet] = 				"Current navigation target set to: ";
	dialogMap[infNavSaved] = 			"Navigation target saved as: ";
	dialogMap[infNavDeleted] = 			"Navigation target deleted: ";
	dialogMap[infNavAllDeleted] =		"All navigation targets removed. Navigation data is now empty.";
	dialogMap[infNavPrint] = 			"\n\nSaved Nav data:\n"
										"    Name  |  X  |  Y  |  Z\n"
										"------------------------------\n";

	dialogMap[hlpThrust] = 	"------------------------------"
							"\n\nThrust Program:\n\n"
							"------------------------------\n"
							"Allows to control engines output.\n\n"
							"Arguments:\n"
							"  -n    : disables thrusters.\n"
							"  -f    : sets thrusters to full thrust\n"
							"  -q    : sets thrusters to quarter thrust\n"
							"  -h    : sets thrusters to half thrust\n"
							"  -t [thrust] : sets thrust to manual value [thrust] in scope [0,1], where 1 is maximum thrust\n"
							"  -v [velocity] : sets engines to burn at full speed until reaching [velocity]. This value must be positive. Keep in mind: you must align your ship towards or against your speed vector to take full advantage of this argument. See 'nav -?' for help.\n"
							"  -?    : shows this help menu\n\n"
							"Examples:\n"
							"  thrust -t 0.6  :sets thrust to 0.6 output\n"
							"  thrust -q  :sets thrust to quarter output\n"
							"  thrust -v 120  :starts burn to reach speed of 120\n"
							"------------------------------";

	dialogMap[hlpNav] = 	"------------------------------"
							"\n\nNavigation Program:\n\n"
							"------------------------------\n"
							"Allows to set and manage navigation targets.\n\n"
							"  -c [x] [y] [z] : sets current nav target.\n"
							"  -s [name] [x] [y] [z] : saves nav target.\n"
							"  -l [name] : loads nav target as current target.\n"
							"  -p : prints all saved nav targets.\n"
							"  -d [name1] [name2]...[nameN] : deletes saved nav targets\n"
							"  -d * : deletes all nav targets.\n"
							"  -?    : shows this help menu\n\n"
							"Examples:\n"
							"  nav -s MyNav 1 2 3 : saves nav target called 'MyNav' with coordinates of x:1, y:2, z:3.\n"
							"  nav -l MyNav : loads 'MyNav' target as current target\n"
							"  nav -d MyNav MyOtherNav : deletes both 'MyNav' and 'MyOtherNav'\n"
							"------------------------------";

	dialogMap[hlpRWheels] =	"------------------------------"
							"\n\nReactionWheels control program:\n\n"
							"------------------------------\n"
							"Allows to control ship bearings and limited flight in cardinal directions.\n\n"
							"rWheels program requires current nav point to be set via 'nav' program.\n\n"
							"  -t : turns ship in direction of current nav point\n"
							"  -s [Direction] : strafes in given direction. Strafe impulse is dependent of Reaction Wheels subsystem power levels.\n"
							"       Directions: FRONT, BACK, UP, DOWN, LEFT, RIGHT\n"
							"  -sl [Direction] : just like '-s' command, except this one loops (ie. instead of impulse, constant force is applied)\n"
							"  -nt : stops any rotation in progress\n"
							"  -ns : stops any strafes in progress\n"
							"  -n : stops all activity from Reaction Wheels subsystem.\n"
							"  -? : shows this help menu\n\n"
							"Examples:\n"
							"  nav -c 1 2 3\n"
							"  rwheels -t : turns ship in direction of x:1, y:2, z:3 point in space\n"
							"  rwheels -sl RIGHT : makes ship constantly strafe in direction of starboard\n"
							"  rwheels -ns : stops previous strafing command, while still allowing ship to turn\n"
							"------------------------------";

	dialogMap[hlpMain] = 	"------------------------------"
							"\n\nGlobal help\n\n"
							"------------------------------\n"
							"If you're using this file, then this means, that ship's OS is bricked.\n"
							"This command console was created specifically for such occasion.\n\n"
							"To control ship, you'll need to execute appropriate programs and learn about program parameters and values:\n\n"
							"To see instructions about Input Console syntax, type 'syntax'\n\n"
							"To check list of available programs, type 'list'\n\n"
							"To see list of keyboard shortcuts, type 'keys'.\n"
							"------------------------------";

	dialogMap[hlpSyntax] = 	"------------------------------"
							"\n\nProgram execution syntax:\n\n"
							"------------------------------\n"
							"Our terminal execution syntax goes as follows:\n\n"
							"  PROGRAM_NAME PAR1 PAR2 .. PARn\n\n"
							"Let's say, we have a program with the name 'thrust', that controls engines. Program takes PARAMETER '-t' that tells it at what thrust engines need to work. To specify the thrust, we use VALUES: \n\n"
							"  thrust -t 0.7\n\n"
							"As you can see: this calls program 'thrust' with parameter '-t' and value '0.7', which will operate engines at thrust level 0.7.\n"
							"Too see more info about any program parameters or values: \n\n"
							"  PROGRAM_NAME -?\n\n"
							"This will print help file for given program.\n"
							"------------------------------";

	dialogMap[hlpKeys] = 	"------------------------------"
							"\n\nKeyboard Shortcuts\n\n"
							"------------------------------\n"
							"[SHIFT]+[ENTER] = runs commands from input console\n"
							"[PAGE UP] OR [PAGE DOWN] = searches through input console history\n"
							"------------------------------";

	dialogMap[hlpList] = 	"------------------------------"
							"\n\nPrograms List:\n\n"
							"------------------------------\n"
							"help - shows global helpfile\n"
							"list - shows this list\n"
							"keys - shows list of keyboard shortcuts\n"
							"clear - clears output console\n"
							"thrust - controls engine output\n"
							"nav - controls navigation\n"
							"rwheels - controls ship's reaction wheels\n"
							"------------------------------";

	dialogMap[msgWelcome] = 	"Welcome to Terminal Commander Emergency Console!\n\n"
								"Your current OS is unable to boot, error code: 518\n"
								"------------------------------"
								"\n\nError message:\n\n"
								"------------------------------\n"
								"We're sorry, but your Portholes8 Operating System (TM) Mid-Aged Enterprise Spacer User License has expired.\n\n"
								"If you're interested in renewing your Mid-Aged Enterprise Spacer User License for another month, please visit our shop at: galaxy://flaccidSoft.shop.xeno\n\n"
								"Have a nice flight!\n"
								"------------------------------\n\n"

								"Type 'help' to see helpfile";

}

CEGUI::String Dialogs::getDialog(Dialogs::msg message){
	return dialogMap[message];
}
