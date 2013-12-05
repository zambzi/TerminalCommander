/*
 * Bindings.h
 *
 *  Created on: Dec 3, 2013
 *      Author: zambzi
 */

#ifndef BINDINGS_H_
#define BINDINGS_H_

#include "../gui/OutputConsole.h"
#include "../ship/Ship.h"

class Bindings {
private:
	OutputConsole* 	output;
	Ship*			playerShip;

public:
	Bindings(OutputConsole* output, Ship* playerShip);
	virtual ~Bindings();

	void parseInput(CEGUI::String text);

	/**
	 * Add bindngs here
	 * @param funct name of a function to execute
	 * @param argc argument count
	 * @param argv array of arguments
	 */
	void runBinding(CEGUI::String funct, int argc, CEGUI::String* argv);

private:
	bool isNumber(CEGUI::String str);
	float strToF(CEGUI::String str);

	void echo(int argc, CEGUI::String* argv);
	void thrust(int argc, CEGUI::String* argv);
};

#endif /* BINDINGS_H_ */
