/*
 * Bindings.h
 *
 *  Created on: Dec 3, 2013
 *      Author: zambzi
 */

#ifndef BINDINGS_H_
#define BINDINGS_H_

#include "../gui/OutputConsole.h"

class Bindings {
private:
	OutputConsole* output;

public:
	Bindings(OutputConsole* output);
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
	void echo(int argc, CEGUI::String* argv);
};

#endif /* BINDINGS_H_ */
