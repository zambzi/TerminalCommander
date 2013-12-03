/*
 * OutputConsole.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: zambzi
 */

#include "OutputConsole.h"

OutputConsole::OutputConsole() {
	CEGUI::WindowManager& mgr = CEGUI::WindowManager::getSingleton();
	field = static_cast<CEGUI::MultiLineEditbox*>(mgr.getWindow("consoleOutputFeed"));
}

OutputConsole::~OutputConsole() {
}

void OutputConsole::append(CEGUI::String text){
	field->appendText(">"+text);
}

void OutputConsole::clear(){
	field->setText(">Cleared");
}

