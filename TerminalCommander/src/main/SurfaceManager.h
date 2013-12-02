/*
 * SurfaceManager.h
 *
 *  Created on: Nov 24, 2013
 *      Author: zambzi
 */

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
