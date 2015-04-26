/*
 * Giant.h
 *
 *  Created on: Apr 25, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_ENTITIES_GIANT_H_
#define SRC_COM_MIDGARD_ENTITIES_GIANT_H_
#include "../com.Midgard.Entities/Entity.h"

/**
 * Clase Giant
 *
 * CROMOSOMAS FUERTES: Attack, RunesPower
 * CROMOSOMAS DÉBILES: Speed
 */
class Giant : public Entity{
public:
	Giant(bool pGender, Entity* pFather, Entity* pMother,Entity* pBrother,
	      Genome* pGenome, int pLife);
	virtual ~Giant();
};

#endif /* SRC_COM_MIDGARD_ENTITIES_GIANT_H_ */
