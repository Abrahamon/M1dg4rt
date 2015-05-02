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
#include "../com.Midgard.Resources/RandomNumberGenerator/Random.h"

class Population {
private:

protected:
	Random* _random;
	Fitness* _Fitness;
	LinkedList<Entity*>* _individuos;



public:
	Population();
	virtual ~Population();

	Entity* randomSelectTheFittest();
	Entity* randomSelectTheFittestMother();
	Entity* randomSelectTheFittestFather();
	Entity* reproductionFor(Entity* pFather, Entity* pMother);

};

#endif /* COM_MIDGARD_VILLAGES_POPULATION_H_ */
