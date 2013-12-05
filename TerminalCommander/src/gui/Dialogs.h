/*
 * Dialogs.h
 *
 *  Created on: Dec 5, 2013
 *      Author: zambzi
 */

#ifndef DIALOGS_H_
#define DIALOGS_H_

#include "../main/stdafx.h"
#include<map>

class Dialogs {
private:
	static bool 						instanceExist;
	static Dialogs* 					dialogs;

public:
	enum msg					{	errProgNotFound,
										errArgNotFound,
										errWrongParam,
										errParamOutOfScope,
										infThrustInProgress,
										infThrustFinished,
										infBurnInProgress,
										infBurnFinished,
										hlpThrust,
										hlpMain,
										hlpList,
										msgWelcome
									};

	std::map<msg, CEGUI::String>	dialogMap;

private:
	Dialogs(){}

	void setDialogs();

public:
	~Dialogs();

	static Dialogs* getInstance();
	CEGUI::String getDialog(msg message);
};

#endif /* DIALOGS_H_ */
