/********************************************//**
 *  \name		ReactionWheels
 *  \brief		Reaction Wheels subsystem implementation
 *  \details
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

#ifndef REACTIONWHEELS_H_
#define REACTIONWHEELS_H_

#include "Subsystem.h"

class ReactionWheels: public Subsystem {
private:
	float					strafeImpulse;
	int						strafeDirection;
	bool					strafing;

	glm::vec3 				normal;
	float					desiredAngle;
	float					angleIterator;
	float					angleIncrement;

public:
	const static float 		MAX_ROTATION = 0.5;
	const static float 		MAX_STRAFE = 0.2;

	enum direction 		{	FRONT,
							BACK,
							LEFT,
							RIGHT,
							UP,
							DOWN	};
public:
	ReactionWheels();
	~ReactionWheels();

	void turnToHeading(const glm::vec3 navVector, const glm::vec3 bearings, const glm::vec3 position);
	void strafe(direction dir, float impulse, bool loop);
	void stopTurn();
	void stopStrafe();

	bool isStrafing() const;
	bool isRotating() const;
	const glm::vec3& getNormalVector() const;
	const float getAngleIncrement() const;

	void update();
};

#endif /* REACTIONWHEELS_H_ */
