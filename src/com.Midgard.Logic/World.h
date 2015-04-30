/*
 * World.h
 *
 *  Created on: Apr 29, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_LOGIC_WORLD_H_
#define COM_MIDGARD_LOGIC_WORLD_H_

class World {

private:
	int* _matriz[30][30];

public:
	World();
	virtual ~World();
};

#endif /* COM_MIDGARD_LOGIC_WORLD_H_ */
