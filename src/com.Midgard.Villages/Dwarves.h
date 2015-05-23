/*
 * Dwarves.h
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */


#ifndef COM_MIDGARD_VILLAGES_DWARVES_H_
#define COM_MIDGARD_VILLAGES_DWARVES_H_

#include "Population.h"
#include "../com.Midgard.DataAccess/Constants.h"
#include "../com.Midgard.Resources/RandomNumberGenerator/Random.h"

class Dwarves : public Population {

private:
	Random* _random;
public:
	Dwarves();
	virtual ~Dwarves();


};

#endif /* COM_MIDGARD_VILLAGES_DWARVES_H_ */
