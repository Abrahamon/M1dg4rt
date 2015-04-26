/*
 * Dwarve.h
 *
 *  Created on: Apr 25, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_ENTITIES_DWARVE_H_
#define COM_MIDGARD_ENTITIES_DWARVE_H_

#include "Entity.h"

class Dwarve : public Entity {

private:
protected:
public:
	Dwarve(bool pGender, Entity* pFather, Entity* pMother,Entity* pBrother,Genome* pGenome);
	virtual ~Dwarve();
};

#endif /* COM_MIDGARD_ENTITIES_DWARVE_H_ */
