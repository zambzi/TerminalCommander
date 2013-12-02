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

class ShipInterface {
private:
	CEGUI::Window* rootWindow;
	CEGUI::Window* console;
	CEGUI::FrameWindow* testFrame;

public:
	OutputConsole* outputConsole;
	InputField* inputField;

public:
	ShipInterface();
	~ShipInterface();

	void update();
	void event(SDL_Event* evt);

private:
	void setResourceProvider();
	void setResourceGroups();
};

#endif /* SHIPINTERFACE_H_ */
