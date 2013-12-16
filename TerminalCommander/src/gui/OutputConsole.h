/********************************************//**
 *  \name		OutputConsole
 *  \brief		Implementation of in-game Output Console
 *  \details
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#ifndef OUTPUTCONSOLE_H_
#define OUTPUTCONSOLE_H_

#include "../main/stdafx.h"

class OutputConsole {
private:
	CEGUI::MultiLineEditbox* field;

public:
	OutputConsole();
	virtual ~OutputConsole();

	void append(CEGUI::String text);
	void clear();
};

#endif /* OUTPUTCONSOLE_H_ */
