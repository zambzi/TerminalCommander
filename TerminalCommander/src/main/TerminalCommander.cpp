/********************************************//**
 *  \name 		TerminalCommander
 *  \brief 		Main source file for TC.
 *  \details
 *  \author		Łukasz Piotrowski
 *  \version	0.4
 *  \date		2013
 *  \bug
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/
#include "stdafx.h"
#include "TCApp.h"

int main() {
	static TCApp tcApp(1280,800,32,60);

	return tcApp.run();
}

