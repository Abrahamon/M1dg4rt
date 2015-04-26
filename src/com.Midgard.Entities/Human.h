/*
 * Humans.h
 *
 *  Created on: Apr 25, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_ENTITIES_HUMAN_H_
#define SRC_COM_MIDGARD_ENTITIES_HUMAN_H_
#include "../com.Midgard.Entities/Entity.h"

/**
 * Clase Humanas
 *
 * CROMOSOMAS FUERTES: Attack, Blot, RunesPower
 * CROMOSOMAS DÉBILES: Magia, Energy
 */
class Human : public Entity{
public:
	Human(bool pGender, Entity* pFather, Entity* pMother,Entity* pBrother,
		   Genome* pGenome, int pLife);
	virtual ~Human();
};

#endif /* SRC_COM_MIDGARD_ENTITIES_HUMAN_H_ */
