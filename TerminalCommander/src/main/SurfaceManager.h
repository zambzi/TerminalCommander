/********************************************//**
 *  \name		SurfaceManager
 *  \brief		Basic Surface Manager for SDL
 *  \details	Currently not used. At first it was just test class, to
 *  			check if SDL is working at current setup. However, it will
 *  			be modified and reused in future.
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#ifndef SURFACEMANAGER_H_
#define SURFACEMANAGER_H_

#include "stdafx.h"

class SurfaceManager {
public:
	static SDL_Surface* loadSurface(char* file);
	static bool drawSurface(SDL_Surface* destination, SDL_Surface* source, int x, int y);

public:
	SurfaceManager();
	virtual ~SurfaceManager();
};

#endif /* SURFACEMANAGER_H_ */
