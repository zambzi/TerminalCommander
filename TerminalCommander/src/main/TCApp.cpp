/*
 * TCApp.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: zambzi
 */

#include "TCApp.h"

TCApp::TCApp():FPS(60){
	resolutionX=640;
	resolutionY=480;
	depth=32;
	displaySurface=NULL;
	isRunning=true;
	interface=NULL;
	playerShip = NULL;
	physics = NULL;
}

TCApp::TCApp(int resolutionX, int resolutionY, int depth, int FPS):FPS(FPS){
	this->resolutionX=resolutionX;
	this->resolutionY=resolutionY;
	this->depth=depth;
	displaySurface=NULL;
	isRunning=true;
	interface=NULL;
	playerShip = NULL;
	physics = NULL;
}

TCApp::~TCApp() {}

int TCApp::run(){
	if(init()==false){
		return -1;
	}

	SDL_Event evt;

	Uint32 start = SDL_GetTicks();
	while(isRunning){
		while(SDL_PollEvent(&evt)){
			event(&evt);
		}

		update();
		render();

		Uint32 difference = SDL_GetTicks()-start;
		if(1000/FPS>difference){
			SDL_Delay(1000/FPS-difference);
		}
	}
	return 0;
}

bool TCApp::init(){
	if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		return false;
	}

	memSetupGL();

	displaySurface = SDL_SetVideoMode(resolutionX, resolutionY, depth, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);
	if(displaySurface == NULL){
		return false;
	}
	setupGL();

	CEGUI::OpenGLRenderer::bootstrapSystem();

	playerShip = new Ship();
	physics = new Physics(playerShip);
	interface = ShipInterface::instantiate(playerShip);

	SDL_EnableUNICODE(1);
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	SDL_ShowCursor(SDL_DISABLE);
	return true;
}

void TCApp::render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	CEGUI::System::getSingleton().renderGUI();

	SDL_GL_SwapBuffers();
}

void TCApp::update(){
	interface->update(*playerShip);
	physics->update();
	playerShip->update();
}

void TCApp::cleanup(){
	delete interface;
	delete playerShip;
	delete physics;
	interface = NULL;
	playerShip = NULL;
	physics = NULL;
	SDL_FreeSurface(displaySurface);
	SDL_Quit();
}

void TCApp::setupGL(){
	glClearColor(0,0,0,1.0f);
	glClearDepth(1.0f);

	glViewport(0,0,resolutionX, resolutionY);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, resolutionX, resolutionY, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();
}

void TCApp::memSetupGL(){
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
}


