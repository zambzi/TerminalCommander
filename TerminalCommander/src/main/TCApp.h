/*
 * TCApp.h
 *
 *  Created on: Nov 24, 2013
 *      Author: zambzi
 */

#ifndef TCAPP_H_
#define TCAPP_H_

#include "stdafx.h"
#include "SurfaceManager.h"
#include "../gui/ShipInterface.h"

class TCApp {
private:
	int				resolutionX;
	int				resolutionY;
	int				depth;

	SDL_Surface*	displaySurface;

	ShipInterface* interface;

public:
	bool 			isRunning;

public:
	TCApp();
	TCApp(int _resolutionX, int _resolutionY, int _depth);
	virtual ~TCApp();

	int run();
	bool init();
	void render();
	void update();
	void cleanup();

	void event(SDL_Event* evt);
	void mouseDown(SDL_Event* evt);
	void mouseUp(SDL_Event* evt);
	void keyDown(SDL_Event* evt);
	CEGUI::uint convertKey(SDLKey key);

	void setupGL();
	void memSetupGL();

};

#endif /* TCAPP_H_ */
