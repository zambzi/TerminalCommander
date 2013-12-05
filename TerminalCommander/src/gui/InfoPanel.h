/*
 * InfoPanel.h
 *
 *  Created on: Dec 2, 2013
 *      Author: zambzi
 */

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
