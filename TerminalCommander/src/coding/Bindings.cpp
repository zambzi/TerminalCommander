/*
 * Bindings.cpp
 *
 *  Created on: Dec 3, 2013
 *      Author: zambzi
 */

#include "Bindings.h"
#include <algorithm>

Bindings::Bindings(OutputConsole* output) {
	this->output = output;

}

Bindings::~Bindings() {
	// TODO Auto-generated destructor stub
}

/**
 * This method will iterate through text string from input console
 * and read data in format:
 *  FUNCTION ARG1 ARG2 ... ARG3
 *  Where single space works as a divider (clearing any stray whitespace)
 *
 *
 */
void Bindings::parseInput(CEGUI::String text){
	int argc = 0;
	CEGUI::String argv[20];
	CEGUI::String funct;
	int lastWhitespace = 0;
	for(unsigned int i = 0; i<text.length(); i++){

		if(text[i]==' ' || text[i]=='\0' || i>=text.length()-1){

			if(funct.empty()){
				funct=text.substr(0,i);
				funct.erase(remove_if(funct.begin(), funct.end(), ::isspace),funct.end());
				if(funct.length()<=0) continue;
				std::cout<<"F|"<<funct<<"|"<<std::endl;
			}
			else{
				argv[argc] = text.substr(lastWhitespace+1, i-lastWhitespace-1);
				argv[argc].erase(remove_if(argv[argc].begin(), argv[argc].end(), ::isspace),argv[argc].end());
				if(argv[argc].length()<=0) continue;
				std::cout<<"|"<<argv[argc]<<"|"<<std::endl;
				argc++;
			}
			lastWhitespace = i;
		}
	}
	runBinding(funct, argc, argv);

	CEGUI::WindowManager& mgr = CEGUI::WindowManager::getSingleton();
	CEGUI::MultiLineEditbox* field = static_cast<CEGUI::MultiLineEditbox*>(mgr.getWindow("consoleOutputFeed"));
	field->getVertScrollbar()->setScrollPosition(field->getVertScrollbar()->getDocumentSize()-field->getVertScrollbar()->getPageSize());
}


void Bindings::echo(int argc, CEGUI::String* argv){
	for(int i=0; i<argc; i++){
		output->append(argv[i]);
	}
}

void Bindings::runBinding(CEGUI::String funct, int argc, CEGUI::String* argv){
	if(funct=="echo") echo(argc, argv);
	else{
		output->append("Error: can't find program '"+funct+"'!");
	}

}
