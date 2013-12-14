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
#include "../ship/Ship.h"
#include "../ship/Physics.h"

class TCApp {
private:
	int				resolutionX;
	int				resolutionY;
	int				depth;
	const int		FPS;

	SDL_Surface*	displaySurface;

	ShipInterface* 	interface;
	Ship*			playerShip;
	Physics*		physics;

public:
	bool 			isRunning;

public:
	TCApp();
	TCApp(int resolutionX, int resolutionY, int depth, int FPS);
	virtual ~TCApp();

	int run();
	bool init();
	void render();
	void update();
	void cleanup();

	void event(SDL_Event* evt);
	void mouseDown(SDL_Event* evt);
	void mouseUp(SDL_Event* evt);
	bool keyDown(SDL_Event* evt);
	CEGUI::uint convertKey(SDLKey key);

	void setupGL();
	void memSetupGL();

};

#endif /* TCAPP_H_ */
