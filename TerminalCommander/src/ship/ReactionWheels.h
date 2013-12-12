/*
 * ReactionWheels.h
 *
 *  Created on: Dec 6, 2013
 *      Author: zambzi
 */

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

	void turnToHeading(const glm::vec3* navVector, const glm::vec3* bearings, const glm::vec3* position);
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
