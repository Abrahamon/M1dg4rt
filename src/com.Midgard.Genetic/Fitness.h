/*
 * Fitness.h
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_GENETICSMANAGER_FITNESS_H_
#define COM_MIDGARD_GENETICSMANAGER_FITNESS_H_

#include "../com.Midgard.Entities/Entity.h"
#include "../com.Midgard.Entities/Dwarve.h"

class Fitness {

private:

	int _IniStrength;
	int _IniAttack;
	int _IniSpeed;
	int _IniDefense;
	int _IniIntelligence;
	int _IniMagic;
	int _IniEnergy;
	int _IniBloot;
	int _IniRunesPower;

public:
	Fitness();
	virtual ~Fitness();


	void setBase(LinkedList<Entity*>* pListEntities);
	int calculateFitness(Dwarve* pDwarve);


};

#endif /* COM_MIDGARD_GENETICSMANAGER_FITNESS_H_ */
