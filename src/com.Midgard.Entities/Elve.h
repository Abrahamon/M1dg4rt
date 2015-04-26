/*
 * Elve.h
 *
 *  Created on: Apr 25, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_ENTITIES_ELVE_H_
#define SRC_COM_MIDGARD_ENTITIES_ELVE_H_

#include "../com.Midgard.Entities/Entity.h"

/**
 * Clase Elfo
 *
 * CROMOSOMAS FUERTES: Attack, Magic, Energy
 * CROMOSOMAS DÉBILES: Speed
 */
class Elve : public Entity{
public:
	Elve(bool pGender, Entity* pFather, Entity* pMother,Entity* pBrother,
		Genome* pGenome, int pLife);
	virtual ~Elve();
};

#endif /* SRC_COM_MIDGARD_ENTITIES_ELVE_H_ */
