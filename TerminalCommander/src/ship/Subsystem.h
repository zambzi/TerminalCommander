/*
 * Subsystem.h
 *
 *  Created on: Dec 3, 2013
 *      Author: zambzi
 */

#ifndef SUBSYSTEM_H_
#define SUBSYSTEM_H_

#include "../gui/Dialogs.h"

class Subsystem {
protected:
	int					power;
	static const int	MAX_POWER = 100;

	int					subsysHealth;
	static const int	MAX_HEALTH = 100;

public:
	Subsystem();
	virtual ~Subsystem();

protected:
	void addPower(int amount);
	void removePower(int amount);
	void fullPower();
	void nullPower();

	void sendMessage(Dialogs::msg message);

	void update();
};

#endif /* SUBSYSTEM_H_ */
