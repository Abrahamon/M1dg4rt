/*
 * Reproduction.h
 *
 *  Created on: Apr 25, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_GENETIC_REPRODUCTION_H_
#define COM_MIDGARD_GENETIC_REPRODUCTION_H_

#include "../com.Midgard.Entities/Entity.h"
#include "../com.Midgard.DataStructures/linkedList.h"
#include "../com.Midgard.DataStructures/linkedNode.h"
#include "../com.Midgard.Entities/Dwarve.h"
#include "../com.Midgard.Entities/Elve.h"
#include "../com.Midgard.Entities/Giant.h"
#include "../com.Midgard.Entities/Human.h"
#include "../com.Midgard.DataAccess/Constants.h"
#include "../com.Midgard.Genetic/largo.h"
#include"../com.Midgard.DataStructures/bitvector.h"
#include "../com.Midgard.Resources/RandomNumberGenerator/Random.h"
#include <math.h>
#include <iostream>
#include "stdint.h"
using namespace std;
class Reproduction {

private:
	static Reproduction* _Reproduction;
	Genome* mutate(Genome* pGenome);
	Random* _Random;
public:
	Reproduction();
	virtual ~Reproduction();

	static Reproduction* getInstance();

	Entity* reproducir(Entity* pFather, Entity* pMother);
};

#endif /* COM_MIDGARD_GENETIC_REPRODUCTION_H_ */
