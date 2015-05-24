/*
 * DarkElves.h
 *
 *  Created on: Apr 25, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_VILLAGES_DARKELVES_H_
#define COM_MIDGARD_VILLAGES_DARKELVES_H_

#include "Population.h"

class Dark_Elves : public Population {
private:
	Random* _random;
public:
	Dark_Elves();
	virtual ~Dark_Elves();
};

#endif /* COM_MIDGARD_VILLAGES_DARKELVES_H_ */
