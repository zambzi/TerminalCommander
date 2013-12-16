/********************************************//**
 *  \name		Dialogs
 *  \brief		Hardcoded string values for program messages.
 *  \details	This file will be modified in future to work with xml
 *  			files instead of hardcoded values
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#ifndef DIALOGS_H_
#define DIALOGS_H_

#include "../main/stdafx.h"
#include<map>

class Dialogs {
private:
	static bool 						instanceExist;
	static Dialogs* 					dialogs;

public:
	enum msg					{		errValNotFound,
										errParamNotFound,
										errWrongVal,
										errValOutOfScope,
										errNavMemEmpty,
										errCantFindNav,
										errCurrNA,
										infThrustInProgress,
										infThrustFinished,
										infBurnInProgress,
										infBurnFinished,
										infRotationInProgress,
										infRotationFinished,
										infNavSet,
										infNavSaved,
										infNavDeleted,
										infNavAllDeleted,
										infNavPrint,
										hlpMain,
										hlpKeys,
										hlpList,
										hlpSyntax,
										hlpThrust,
										hlpNav,
										hlpRWheels,
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
