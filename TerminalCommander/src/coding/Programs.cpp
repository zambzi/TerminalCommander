/*
 * Programs.cpp
 *
 *  Created on: Dec 4, 2013
 *      Author: zambzi
 */

#include "Bindings.h"
#include "../gui/Dialogs.h"
#include "../gui/ShipInterface.h"
#include "../utils/Vec3.h"

void Bindings::runBinding(CEGUI::String funct, int argc, CEGUI::String* argv){
	OutputConsole* output = ShipInterface::getInstance()->outputConsole;
	if(funct=="echo") echo(argc, argv);
	else if(funct=="thrust") thrust(argc,argv);
	else if(funct=="help") output->append(Dialogs::getInstance()->getDialog(Dialogs::hlpMain));
	else if(funct=="list") output->append(Dialogs::getInstance()->getDialog(Dialogs::hlpList));
	else if(funct=="keys") output->append(Dialogs::getInstance()->getDialog(Dialogs::hlpKeys));
	else if(funct=="syntax") output->append(Dialogs::getInstance()->getDialog(Dialogs::hlpSyntax));
	else if(funct=="clear") output->clear();
	else if(funct=="nav") nav(argc, argv);
	else if(funct=="rwheels") rWheels(argc, argv);
	else{
		output->append(Dialogs::getInstance()->getDialog(Dialogs::errValNotFound)+funct);
	}

}

void Bindings::echo(int argc, CEGUI::String* argv){
	OutputConsole* output = ShipInterface::getInstance()->outputConsole;
	for(int i=0; i<argc; i++){
		output->append(argv[i]);
	}
}


void Bindings::thrust(int argc,CEGUI::String* argv){
	const Ship* playerShip = ShipInterface::getInstance()->playerShip;
	OutputConsole* output = ShipInterface::getInstance()->outputConsole;

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
					output->append(Dialogs::getInstance()->getDialog(Dialogs::errValOutOfScope)+argv[i]);
				else
					playerShip->thrusters->setThrust(thrust);
			}
			else
				output->append(Dialogs::getInstance()->getDialog(Dialogs::errWrongVal)+argv[i]);
		}
		else if(argv[i]=="-v"){
			//TODO: finish thrust -v
			output->append(Dialogs::getInstance()->getDialog(Dialogs::errCurrNA));
			/*if(i+1<argc && isNumber(argv[i+1])){
				float velocity = strtof(argv[i+1].c_str(),NULL);
				if(velocity<0)
					output->append(Dialogs::getInstance()->getDialog(Dialogs::errValOutOfScope)+argv[i]);
				else
					playerShip->thrusters->setThrustToVelocity(velocity);
			}
			else
				output->append(Dialogs::getInstance()->getDialog(Dialogs::errWrongVal)+argv[i]);*/
		}
		else if(argv[i]=="-?")
			output->append(Dialogs::getInstance()->getDialog(Dialogs::hlpThrust));
		else
			output->append(Dialogs::getInstance()->getDialog(Dialogs::errParamNotFound)+argv[i]);

	}
}



void Bindings::nav(int argc,CEGUI::String* argv){
	const Ship* playerShip = ShipInterface::getInstance()->playerShip;
	OutputConsole* output = ShipInterface::getInstance()->outputConsole;

	float x,y,z;

	for(int i=0; i<argc; i++){
		if(argv[i]=="-c"){
			if(i+3<argc && 	isNumber(argv[i+1]) &&
							isNumber(argv[i+2]) &&
							isNumber(argv[i+3])){
				x = strtof(argv[i+1].c_str(),NULL);
				y = strtof(argv[i+2].c_str(),NULL);
				z = strtof(argv[i+3].c_str(),NULL);
				playerShip->nav->setNav(x,y,z);

				output->append(Dialogs::getInstance()->getDialog(Dialogs::infNavSet)+argv[i+1]+" "+argv[i+2]+" "+argv[i+3]);
			}
			else
				output->append(Dialogs::getInstance()->getDialog(Dialogs::errWrongVal)+argv[i]);
		}
		else if(argv[i]=="-s"){

			if(i+4<argc && 	isNumber(argv[i+2]) &&
							isNumber(argv[i+3]) &&
							isNumber(argv[i+4])){
				x = strtof(argv[i+2].c_str(),NULL);
				z = strtof(argv[i+3].c_str(),NULL);
				y = strtof(argv[i+4].c_str(),NULL);
				playerShip->nav->saveNav(argv[i+1],x,y,z);
				output->append(Dialogs::getInstance()->getDialog(Dialogs::infNavSaved)+argv[i+1]);
			}
			else
				output->append(Dialogs::getInstance()->getDialog(Dialogs::errWrongVal)+argv[i]);

		}
		else if(argv[i]=="-l"){

			const glm::vec3* vector = playerShip->nav->loadNav(argv[i+1]);
			if(vector!=NULL){
				playerShip->nav->setNav(vector->x, vector->y, vector->z);
				output->append(Dialogs::getInstance()->getDialog(Dialogs::infNavSet)+argv[i+1]);
			}
			else
				output->append(Dialogs::getInstance()->getDialog(Dialogs::errCantFindNav)+argv[i+1]);
			delete vector;

		}
		else if(argv[i]=="-p"){
			CEGUI::String navlist = playerShip->nav->printNavs();
			if(navlist!=""){
				output->append(Dialogs::getInstance()->getDialog(Dialogs::infNavPrint)+navlist);
			}
			else
				output->append(Dialogs::getInstance()->getDialog(Dialogs::errNavMemEmpty));
		}
		else if(argv[i]=="-d"){
			if(i+1 >= argc){
				output->append(Dialogs::getInstance()->getDialog(Dialogs::errWrongVal)+argv[i]);
			}
			else if(argv[i+1]=="*"){
				if(playerShip->nav->deleteAllNavs())
					output->append(Dialogs::getInstance()->getDialog(Dialogs::infNavAllDeleted));
				else
					output->append(Dialogs::getInstance()->getDialog(Dialogs::errNavMemEmpty));
			}
			else{
				for(int j=i+1; j<argc; j++){
					if(playerShip->nav->deleteNav(argv[i+j]))
						output->append(Dialogs::getInstance()->getDialog(Dialogs::infNavDeleted)+argv[i+j]);
					else
						output->append(Dialogs::getInstance()->getDialog(Dialogs::errCantFindNav)+argv[i+j]);
				}
			}
		}
		else if(argv[i]=="-?"){
			output->append(Dialogs::getInstance()->getDialog(Dialogs::hlpNav));
		}
		else
			output->append(Dialogs::getInstance()->getDialog(Dialogs::errParamNotFound)+argv[i]);
	}
}

//TODO:Finish rwheels
void Bindings::rWheels(int argc,CEGUI::String* argv){
	const Ship* playerShip = ShipInterface::getInstance()->playerShip;
	OutputConsole* output = ShipInterface::getInstance()->outputConsole;

	for(int i=0; i<argc; i++){
		if(argv[i]=="-t"){
			playerShip->rWheels->turnToHeading(playerShip->nav->getNav(), playerShip->getBearings(), playerShip->getPosition());
		}
		else if(argv[i]=="-s"){
			output->append(Dialogs::getInstance()->getDialog(Dialogs::errCurrNA));
		}
		else if(argv[i]=="-sl"){
			output->append(Dialogs::getInstance()->getDialog(Dialogs::errCurrNA));
		}
		else if(argv[i]=="-n"){
			output->append(Dialogs::getInstance()->getDialog(Dialogs::errCurrNA));
		}
		else if(argv[i]=="-nt"){
			output->append(Dialogs::getInstance()->getDialog(Dialogs::errCurrNA));
		}
		else if(argv[i]=="-ns"){
			output->append(Dialogs::getInstance()->getDialog(Dialogs::errCurrNA));
		}
		else if(argv[i]=="-?"){
			output->append(Dialogs::getInstance()->getDialog(Dialogs::hlpRWheels));
		}
		else
			output->append(Dialogs::getInstance()->getDialog(Dialogs::errParamNotFound)+argv[i]);

	}

}
