/*
 * InputField.h
 *
 *  Created on: Dec 2, 2013
 *      Author: zambzi
 */

#ifndef INPUTFIELD_H_
#define INPUTFIELD_H_

#include "../main/stdafx.h"
#include "../coding/Bindings.h"
#include "OutputConsole.h"
#include "deque"

class InputField {
private:
	CEGUI::MultiLineEditbox* 	field;
	CEGUI::PushButton* 			runBtn;

	OutputConsole* 				output;
	Bindings*					bindings;

	std::deque<CEGUI::String>	inputHistory;
	unsigned int				currHistoryRecord;
	static const unsigned int	MAX_HISTORY=100;

public:
	InputField(OutputConsole* output, Bindings* bindings);
	~InputField();

	void historyUp();
	void historyDown();
	void processCode();

private:
	bool runCode(const CEGUI::EventArgs& evt);
};

#endif /* INPUTFIELD_H_ */
