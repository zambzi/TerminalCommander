/********************************************//**
 *  \name		InputField
 *  \brief		Implementation of in-game Input Console
 *  \details
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

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
