/*
 * Reproduction.h
 *
 *  Created on: Apr 25, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_GENETIC_REPRODUCTION_H_
#define COM_MIDGARD_GENETIC_REPRODUCTION_H_

#include "../com.Midgard.Entities/Entity.h"
#include "../com.Midgard.Entities/Dwarve.h"
#include "../com.Midgard.Entities/Elve.h"
#include "../com.Midgard.Entities/Giant.h"
#include "../com.Midgard.Entities/Human.h"
#include "../com.Midgard.DataAccess/Constants.h"

#include "stdint.h"

class Reproduction {

private:
	static Reproduction* _Reproduction;
	Genome* mutate(Genome* pGenome);

public:
	Reproduction();
	virtual ~Reproduction();

	static Reproduction* getInstance();

	Entity* reproducir(Entity* pFather, Entity* pMother);

};

#endif /* COM_MIDGARD_GENETIC_REPRODUCTION_H_ */
