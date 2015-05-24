/*
 * God.h
 *
 *  Created on: May 24, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_ENTITIES_GOD_H_
#define SRC_COM_MIDGARD_ENTITIES_GOD_H_

#include "../com.Midgard.DataAccess/Constants.h"
#include "../com.Midgard.Resources/RandomNumberGenerator/Random.h"
#include <string>

class God{

private:
	int _Life;
	float _Defense;
	bool _isAlive;
	std::string _Name;
	Random* _random;
public:

	God(std::string pName);
	virtual ~God();
	void receiveAttack(int pAttack);
	bool isGodAlive();
	int getLife();
};

#endif /* SRC_COM_MIDGARD_ENTITIES_GOD_H_ */
