/********************************************//**
 *  \name		TCApp
 *  \brief		Core App class
 *  \details	Main manager, consisting of main game loop, all SDL and
 *  			CEGUI initialization, core input setup and opengl setup,
 *  			as well as rendering.
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#ifndef TCAPP_H_
#define TCAPP_H_

#include "stdafx.h"
#include "SurfaceManager.h"
#include "../gui/ShipInterface.h"
#include "../ship/Ship.h"
#include "../ship/Physics.h"

class TCApp {
private:
	int						resolutionX;
	int						resolutionY;
	int						depth;
	const unsigned int		FPS;

	SDL_Surface*			displaySurface;

	ShipInterface* 			interface;
	Ship*					playerShip;
	Physics*				physics;

public:
	bool 					isRunning;

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
