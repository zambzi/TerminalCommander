/*
 * ShipInterface.h
 *
 *  Created on: Nov 25, 2013
 *      Author: zambzi
 */

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
	CEGUI::Window* 			rootWindow;
	CEGUI::Window* 			console;
	CEGUI::FrameWindow* 	testFrame;

public:
	OutputConsole* 			outputConsole;
	InputField* 			inputField;
	InfoPanel* 				infoPanel;
	Bindings* 				bindings;

public:
	ShipInterface(Ship* playerShip);
	~ShipInterface();

	void update(const Ship& ship);
	void event(SDL_Event* evt);

private:
	void setResourceProvider();
	void setResourceGroups();
};

#endif /* SHIPINTERFACE_H_ */
