/*
 * SurfaceManager.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: zambzi
 */

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
