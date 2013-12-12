/*
 * ReactionWheels.cpp
 *
 *  Created on: Dec 6, 2013
 *      Author: zambzi
 */

#include "ReactionWheels.h"

#include "../gui/ShipInterface.h"

ReactionWheels::ReactionWheels() {
	strafeImpulse = 0;
	strafeDirection = FRONT;
	strafing = false;
	normal = glm::vec3(1,0,0);
	desiredAngle = 0;
	angleIncrement = 0;
	angleIterator = 0;
}

ReactionWheels::~ReactionWheels() {}

void ReactionWheels::turnToHeading(const glm::vec3* navVector, const glm::vec3* bearings, const glm::vec3* position){
	//TODO: Send msg
	//TODO: Wrong vectors safety code
	//TODO: paramaters via value

	if(*navVector != *position){
		glm::vec3 source(*bearings);
		glm::vec3 destination(*navVector - *position);
		source = glm::normalize(source);
		std::cout<<"before normalize\n";
		destination = glm::normalize(destination);
		std::cout<<"after normalize\n";


		float cosine = glm::dot(source,destination) / (glm::length(source)*glm::length(destination));
		float acosine = glm::acos(cosine)*180/M_PI;

		if(cosine<-1+0.001f){ //parallel vectors
			normal = glm::cross(glm::vec3(0,1.0f,0), source);
			if(glm::length2(normal)<0.01){
				normal = glm::cross(glm::vec3(1.0f,0,0), source);
			}
		}
		else{
			normal = glm::cross(source, destination);
		}

		desiredAngle = acosine;
		float powerModifier = (float)power/1000.0;
		angleIncrement = acosine*powerModifier;
	}
}

void ReactionWheels::strafe(direction dir, float impulse, bool loop){
	//TODO: send msg
	strafing = true;
	strafeDirection = dir;
	strafeImpulse = impulse;
	//TODO:Add loop;
}


void ReactionWheels::stopStrafe(){
	strafing = false;
}

const glm::vec3& ReactionWheels::getNormalVector() const{
	return normal;
}
const float ReactionWheels::getAngleIncrement() const{
	return angleIncrement;
}

void ReactionWheels::update(){
	if(angleIterator >= desiredAngle){
		angleIncrement = 0;
		angleIterator = 0;
	}
	else
		angleIterator+=angleIncrement;
}
