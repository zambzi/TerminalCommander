/*
 * InputField.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: zambzi
 */

#include "InputField.h"


InputField::InputField(OutputConsole* output) {
	this->output = output;
	CEGUI::WindowManager& mgr = CEGUI::WindowManager::getSingleton();
	field = static_cast<CEGUI::MultiLineEditbox*>(mgr.getWindow("consoleInputField"));
	runBtn = static_cast<CEGUI::PushButton*>(mgr.getWindow("runBtn"));

	runBtn->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&InputField::runCode,this));
}

InputField::~InputField() {
	// TODO Auto-generated destructor stub
}

bool InputField::runCode(const CEGUI::EventArgs& evt){
	output->append(field->getText());
	//TODO: Code execution here
	return true;
}

