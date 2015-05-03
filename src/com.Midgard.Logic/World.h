/*
 * World.h
 *
 *  Created on: Apr 29, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_LOGIC_WORLD_H_
#define COM_MIDGARD_LOGIC_WORLD_H_

#include "../com.Midgard.Villages/DarkElves.h"
#include "../com.Midgard.Villages/Dwarves.h"
#include "../com.Midgard.Villages/Elves.h"
#include "../com.Midgard.Villages/Giants.h"

class World {

private:
	int* _matriz[30][30];
	Dark_Elves* _Dark_Elves;
	Elves* _Elves;
	Giants* _Giants;
	Dwarves* _Dwarves;

public:
	World();
	virtual ~World();

	void start();
};

#endif /* COM_MIDGARD_LOGIC_WORLD_H_ */
