/********************************************//**
 *  \name		InfoPanel
 *  \brief		Implementation of Information Panel on TC Console
 *  \details
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#ifndef INFOPANEL_H_
#define INFOPANEL_H_

#include "../ship/Ship.h"

class InfoPanel {
private:
	CEGUI::MultiLineEditbox* 	field;

public:
	InfoPanel();
	~InfoPanel();

	void update(const Ship& ship);
};

#endif /* INFOPANEL_H_ */
