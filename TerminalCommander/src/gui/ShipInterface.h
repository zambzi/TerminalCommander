/********************************************//**
 *  \name		ShipInterface
 *  \brief		Core UI class.
 *  \details	ShipInterface manages all aspects of interface, along with
 *  			3 main consoles (Output, Input, Info). Also, most CEGUI setup
 *  			is done here.
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#ifndef SHIPINTERFACE_H_
#define SHIPINTERFACE_H_

#include "../main/stdafx.h"
#include "InputField.h"
#include "OutputConsole.h"
#include "InfoPanel.h"
#include "../coding/Bindings.h"
#include "../ship/Ship.h"

class ShipInterface {
private:
	static bool				instanceExist;
	static ShipInterface*	interface;

	CEGUI::Window* 			rootWindow;
	CEGUI::Window* 			console;
	CEGUI::FrameWindow* 	testFrame;

public:
	OutputConsole* 			outputConsole;
	InputField* 			inputField;
	InfoPanel* 				infoPanel;
	Bindings* 				bindings;
	const Ship*				playerShip;

public:
	~ShipInterface();

	static ShipInterface* getInstance();
	static ShipInterface* instantiate(const Ship* playerShip);
	void update(const Ship& playerShip);
	void event(SDL_Event* evt);

private:
	ShipInterface(const Ship* playerShip);
	void setResourceProvider();
	void setResourceGroups();
};

#endif /* SHIPINTERFACE_H_ */
