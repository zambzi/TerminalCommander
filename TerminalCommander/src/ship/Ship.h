/********************************************//**
 *  \name		Ship
 *  \brief		Core Ship class
 *  \details	Controls all the subsystems of player ship and stores core info.
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#ifndef SHIP_H_
#define SHIP_H_


#include "../main/stdafx.h"
#include "ReactionWheels.h"
#include "Thrusters.h"
#include "Nav.h"

class Ship {
private:
	glm::vec3		position;
	glm::vec3		bearings;
	glm::vec3		velocity;

	int				mass;

public:
	ReactionWheels* rWheels;
	Thrusters* 		thrusters;
	Nav*			nav;

public:
	Ship();
	~Ship();
	friend class Physics;
	friend class Dials;

	void update();
	const glm::vec3 getBearings() const;
	const glm::vec3 getPosition() const;
};

#endif /* SHIP_H_ */
