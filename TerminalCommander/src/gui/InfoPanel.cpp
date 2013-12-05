/*
 * InfoPanel.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: zambzi
 */

#include "InfoPanel.h"
#include "../utils/Dials.h"
#include <strstream>

InfoPanel::InfoPanel() {
	CEGUI::WindowManager& mgr = CEGUI::WindowManager::getSingleton();
	field = static_cast<CEGUI::MultiLineEditbox*>(mgr.getWindow("panelOutputFeed"));
}

InfoPanel::~InfoPanel() {

}

void InfoPanel::update(const Ship& ship){
	std::string text;
	std::ostringstream str;
	str.precision(2);
	str<<std::fixed;

	str<<	"POS: X:"	<<	Dials::getLocation(ship).x	<<
			"  Y:"		<<	Dials::getLocation(ship).y	<<
			"  Z:"		<<	Dials::getLocation(ship).z	<<
			"\nDIR: X:"	<<	Dials::getBearings(ship).x	<<
			"  Y:"		<<	Dials::getBearings(ship).y	<<
			"  Z:"		<<	Dials::getBearings(ship).z	<<
			"\nV:"		<<	Dials::getVelocity(ship)	<<
			"\nThrust:"	<<	Dials::getThrust(ship);


	text = str.str();

	field->setText("");
	field->appendText(text);
}

