/*
 * Dwarve.h
 *
 *  Created on: Apr 25, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_ENTITIES_DWARVE_H_
#define SRC_COM_MIDGARD_ENTITIES_DWARVE_H_

#include "../com.Midgard.Entities/Entity.h"

/**
 * Clase Enano
 *
 * CROMOSOMAS FUERTES: Intelligence, Energy, Defense
 * CROMOSOMAS DÉBILES: Attack, Speed
 */
class Dwarve : public Entity{

public:
	Dwarve(bool pGender, Entity* pFather, Entity* pMother,Entity* pBrother,
			   Genome* pGenome, int pLife);
	virtual ~Dwarve();
};
#endif /* SRC_COM_MIDGARD_ENTITIES_DWARVE_H_ */

