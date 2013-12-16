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

#include "SurfaceManager.h"

SurfaceManager::SurfaceManager() {}

SurfaceManager::~SurfaceManager() {}

SDL_Surface* SurfaceManager::loadSurface(char* file){
	SDL_Surface* surface = NULL;
	SDL_Surface* formattedSurface = NULL;

	surface = SDL_LoadBMP(file);

	if(surface==NULL) return NULL;

	formattedSurface = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);

	return formattedSurface;
}

bool SurfaceManager::drawSurface(SDL_Surface* destination, SDL_Surface* source, int x, int y){
	if(destination == NULL || source == NULL) return false;

	SDL_Rect destinationRect;
	destinationRect.x = x;
	destinationRect.y = y;

	SDL_BlitSurface(source, NULL, destination, &destinationRect);
	return true;
}
