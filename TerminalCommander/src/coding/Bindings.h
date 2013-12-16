/********************************************//**
 *  \name		Bindings
 *  \brief		Bindings class is used to parse input and bind it
 *  			to apropriate methods.
 *  \details
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#ifndef BINDINGS_H_
#define BINDINGS_H_

#include "../gui/OutputConsole.h"
#include "../ship/Ship.h"

class Bindings {

public:
	Bindings();
	~Bindings();

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

	void echo(int argc, CEGUI::String* argv);
	void thrust(int argc, CEGUI::String* argv);
	void nav(int argc, CEGUI::String* argv);
	void rWheels(int argc, CEGUI::String* argv);
};

#endif /* BINDINGS_H_ */
