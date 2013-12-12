/*
 * InputField.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: zambzi
 */

#include "InputField.h"
#include "../ship/Ship.h"


InputField::InputField(OutputConsole* output, Bindings* bindings){
	this->output = output;
	CEGUI::WindowManager& mgr = CEGUI::WindowManager::getSingleton();
	field = static_cast<CEGUI::MultiLineEditbox*>(mgr.getWindow("consoleInputField"));
	runBtn = static_cast<CEGUI::PushButton*>(mgr.getWindow("runBtn"));
	currHistoryRecord = 0;

	this->bindings = bindings;

	runBtn->subscribeEvent(CEGUI::PushButton::EventClicked,
			CEGUI::Event::Subscriber(&InputField::runCode,this));
}

InputField::~InputField() {
	if(!inputHistory.empty()){
		std::deque<CEGUI::String>::iterator i;
		for(i = inputHistory.begin(); i != inputHistory.end(); i++){
			i->clear();
		}
		inputHistory.clear();
	}
}

bool InputField::runCode(const CEGUI::EventArgs& evt){
	processCode();
	return true;
}

void InputField::processCode(){
	if(!field->getText().empty()){
		inputHistory.push_front(field->getText());
		if(inputHistory.size()>InputField::MAX_HISTORY)
			inputHistory.pop_back();
		currHistoryRecord=0;

		bindings->parseInput(field->getText());
		field->setText("");
	}
}


//TODO:eliminate double history index, while changing down-up events
void InputField::historyUp(){
	if(inputHistory.size()!=0){
		if(currHistoryRecord>=inputHistory.size())
			currHistoryRecord=0;
		field->setText(inputHistory[currHistoryRecord]);
		field->setCaratIndex(inputHistory[currHistoryRecord].length());
		currHistoryRecord++;
	}
}

void InputField::historyDown(){
	if(inputHistory.size()!=0 && currHistoryRecord>0){
		field->setText(inputHistory[currHistoryRecord-1]);
		field->setCaratIndex(inputHistory[currHistoryRecord-1].length());
		currHistoryRecord--;
	}
	else{
		field->setText("");
		currHistoryRecord=inputHistory.size();
	}
}
