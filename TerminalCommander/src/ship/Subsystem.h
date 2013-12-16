/********************************************//**
 *  \name		Subsystem
 *  \brief		Basic common implementation of a ship subsystem.
 *  \details	Provides most common functionality shared between every
 *  			ship subsystem, like power and communication.
 *  \author		Łukasz Piotrowski
 *  \warning	This software is provided "AS IS", there is no warranty,
 *  			that the software will work, and creator is not to be
 *  			held liable due to any potential damages that may occur
 *  			due to use of this code.
 *  \copyright
 ***********************************************/

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
