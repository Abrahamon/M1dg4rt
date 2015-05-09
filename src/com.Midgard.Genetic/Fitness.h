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

	float _IniAttack;
	float _IniSpeed;
	float _IniDefense;
	float _IniIntelligence;
	float _IniMagic;
	float _IniEnergy;
	float _IniBloot;
	float _IniRunesPower;
	int _sumAll;

public:
	Fitness();
	virtual ~Fitness();
	int getSumOfAll();
	void restarData();

	void setBase(LinkedList<Entity*>* pListEntities);
	float caculateFitness(Entity* pEntity);
};

#endif /* COM_MIDGARD_GENETICSMANAGER_FITNESS_H_ */
