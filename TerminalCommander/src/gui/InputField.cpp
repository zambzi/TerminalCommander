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
	ifWindow = static_cast<CEGUI::Window*>(mgr.getWindow("backgroundWindow"));
	currHistoryRecord = 0;

	bindings = new Bindings(output);

	runBtn->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&InputField::runCode,this));
}

InputField::~InputField() {
	// TODO Auto-generated destructor stub
}

bool InputField::runCode(const CEGUI::EventArgs& evt){
	processCode();
	return true;
}

void InputField::processCode(){
	if(!field->getText().empty()){
		inputHistory.push_front(field->getText());
		if(inputHistory.size()>maxHistory)
			inputHistory.pop_back();
		currHistoryRecord=-1;

		bindings->parseInput(field->getText());
		field->setText("");
	}
}

void InputField::historyUp(){
	if(inputHistory.size()!=0){
		currHistoryRecord++;
		if(currHistoryRecord>=inputHistory.size())
			currHistoryRecord=0;
		field->setText(inputHistory[currHistoryRecord]);
	}
}

void InputField::historyDown(){
	if(inputHistory.size()!=0){
		currHistoryRecord--;
		if(currHistoryRecord<0)
			currHistoryRecord=inputHistory.size()-1;
		field->setText(inputHistory[currHistoryRecord]);
	}
}
