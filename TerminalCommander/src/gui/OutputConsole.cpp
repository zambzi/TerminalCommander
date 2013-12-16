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

#include "OutputConsole.h"
#include "Dialogs.h"

OutputConsole::OutputConsole() {
	CEGUI::WindowManager& mgr = CEGUI::WindowManager::getSingleton();
	field = static_cast<CEGUI::MultiLineEditbox*>(mgr.getWindow("consoleOutputFeed"));
	field->setText(Dialogs::getInstance()->getDialog(Dialogs::msgWelcome));
}

OutputConsole::~OutputConsole() {}

void OutputConsole::append(CEGUI::String text){
	field->appendText(">"+text);
	field->getVertScrollbar()->setScrollPosition(field->getVertScrollbar()->getDocumentSize()-field->getVertScrollbar()->getPageSize());
}

void OutputConsole::clear(){
	field->setText("");
}

