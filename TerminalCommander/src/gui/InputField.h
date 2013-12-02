/*
 * InputField.h
 *
 *  Created on: Dec 2, 2013
 *      Author: zambzi
 */

#ifndef INPUTFIELD_H_
#define INPUTFIELD_H_

#include "../main/stdafx.h"
#include "OutputConsole.h"

class InputField {
private:
	CEGUI::MultiLineEditbox* field;
	CEGUI::PushButton* runBtn;

	OutputConsole* output;

public:
	InputField(OutputConsole* output);
	~InputField();

	void isRunClicked(OutputConsole* output);

private:
	bool runCode(const CEGUI::EventArgs& e);
};

#endif /* INPUTFIELD_H_ */
