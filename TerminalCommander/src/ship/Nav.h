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

#ifndef NAV_H_
#define NAV_H_

#include "Subsystem.h"
#include <map>

class Nav: public Subsystem{
private:
	glm::vec3							headingNav;
	std::map<CEGUI::String, glm::vec3>	navMemory;

public:
	Nav();
	~Nav();

	void setNav(float x, float y, float z);
	const glm::vec3 getNav();

	void saveNav(CEGUI::String name, float x, float y, float z);
	const glm::vec3* loadNav(CEGUI::String name);
	bool deleteNav(CEGUI::String name);
	bool deleteAllNavs();
	CEGUI::String printNavs();

private:
	void deleteAll();
	std::map<CEGUI::String, glm::vec3>::iterator getNavFromMem(CEGUI::String name);
};

#endif /* NAV_H_ */
