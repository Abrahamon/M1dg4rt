/*
 * Pupolation.h
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_VILLAGES_POPULATION_H_
#define COM_MIDGARD_VILLAGES_POPULATION_H_

#include "../com.Midgard.DataStructures/linkedList.h"
#include "../com.Midgard.Entities/Entity.h"
#include "../com.Midgard.Genetic/Fitness.h"

class Population {

private:
	Fitness* _Fitness;
	LinkedList<Entity*>* _individuos;

public:
	Population();
	virtual ~Population();
	void generacionCero();
};

#endif /* COM_MIDGARD_VILLAGES_POPULATION_H_ */
