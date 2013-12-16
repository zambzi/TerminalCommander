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

#include "Bindings.h"
#include <algorithm>

Bindings::Bindings() {}

Bindings::~Bindings() {}

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

		//TODO:multiple lines implementation

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
}


bool Bindings::isNumber(CEGUI::String str){
	bool isFloat = false;
	if(str.empty()) return false;
	for(unsigned int i=0; i<str.length(); i++){
		if(i==0 && str[i]=='-'){
			continue;
		}
		if(!std::isdigit(str[i])){
			if(str[i]!='.' || isFloat)
				return false;
			else
				isFloat = true;
		}
	}
	return true;
}
