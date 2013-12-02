/*
 * OutputConsole.h
 *
 *  Created on: Dec 2, 2013
 *      Author: zambzi
 */

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
