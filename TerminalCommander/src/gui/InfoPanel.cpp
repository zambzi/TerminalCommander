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

	str<<	"POS: X:"			<<	Dials::getLocation(ship).x	<<
			"  Y:"				<<	Dials::getLocation(ship).y	<<
			"  Z:"				<<	Dials::getLocation(ship).z	<<
			"\nBEARINGS: x:"	<<	Dials::getBearings(ship).x	<<
			"  y:"				<<	Dials::getBearings(ship).y	<<
			"  z:"				<<	Dials::getBearings(ship).z	<<
			"\nNAV: x:"			<<  Dials::getNav(ship).x		<<
			"y:"				<<  Dials::getNav(ship).y		<<
			"z:"				<<  Dials::getNav(ship).z		<<
			"\nV:"				<<	Dials::getVelocity(ship)	<<
			"\nThrust:"			<<	Dials::getThrust(ship);


	text = str.str();

	field->setText("");
	field->appendText(text);
}

