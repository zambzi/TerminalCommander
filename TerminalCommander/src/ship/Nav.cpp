/********************************************//**
 *  \name		Nav
 *  \brief		Navigation subsystem implementation
 *  \details
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#include "Nav.h"
#include <sstream>

Nav::Nav() {
	headingNav = glm::vec3(1,0,0);
}

Nav::~Nav() {
	navMemory.clear();
}


void Nav::setNav(float x, float y, float z){
	headingNav = glm::vec3(x,y,z);
}

const glm::vec3 Nav::getNav(){
	return headingNav;
}

void Nav::saveNav(CEGUI::String name, float x, float y, float z){
	navMemory[name] = glm::vec3(x,y,z);
}

std::map<CEGUI::String, glm::vec3>::iterator Nav::getNavFromMem(CEGUI::String name){
	std::map<CEGUI::String, glm::vec3>::iterator i;

	i = navMemory.find(name);
	return i;
}

const glm::vec3* Nav::loadNav(CEGUI::String name){
	std::map<CEGUI::String, glm::vec3>::iterator i = getNavFromMem(name);

	if(i!=navMemory.end())
		return &i->second;
	else
		return NULL;
}



bool Nav::deleteNav(CEGUI::String name){
	std::map<CEGUI::String, glm::vec3>::iterator i = getNavFromMem(name);

	if(i!=navMemory.end()){
		navMemory.erase(i);
		return true;
	}
	return false;
}

bool Nav::deleteAllNavs(){
	if(navMemory.empty())
		return false;

	navMemory.clear();

	return true;
}

CEGUI::String Nav::printNavs(){
	CEGUI::String navs;
	std::stringstream str;
	str.precision(2);
	str<<std::fixed;

	std::map<CEGUI::String, glm::vec3>::iterator i;

	if(navMemory.empty()) return "";

	for(i = navMemory.begin(); i!=navMemory.end(); i++){
		str<<	"   "	<<
				i->first << " | "<<
				i->second.x<< " | "<<
				i->second.y<< " | "<<
				i->second.z<< "\n";
	}

	navs = str.str();
	return navs;
}

