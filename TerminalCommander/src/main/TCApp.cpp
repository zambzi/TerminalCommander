/*
 * TCApp.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: zambzi
 */

#include "TCApp.h"

TCApp::TCApp():
	resolutionX(640),
	resolutionY(480),
	depth(32),
	displaySurface(NULL),
	isRunning(true){
	interface=NULL;

}

TCApp::TCApp(int _resolutionX, int _resolutionY, int _depth):
				resolutionX(_resolutionX),
				resolutionY(_resolutionY),
				depth(_depth),
				displaySurface(NULL),
				isRunning(true){
	interface=NULL;
}

TCApp::~TCApp() {
}

int TCApp::run(){
	if(init()==false){
		return -1;
	}

	SDL_Event evt;

	while(isRunning){
		while(SDL_PollEvent(&evt)){
			event(&evt);
		}

		update();
		render();
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
	interface = new ShipInterface();
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

}

void TCApp::cleanup(){
	delete interface;
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

	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
}

