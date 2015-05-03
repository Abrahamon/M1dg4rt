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

	double _IniStrength;
	double _IniAttack;
	double _IniSpeed;
	double _IniDefense;
	double _IniIntelligence;
	double _IniMagic;
	double _IniEnergy;
	double _IniBloot;
	double _IniRunesPower;
	int _sumAll;

public:
	Fitness();
	virtual ~Fitness();
	int getSumOfAll();

	void setBase(LinkedList<Entity*>* pListEntities);
	double caculateFitness(Entity* pEntity);


};

#endif /* COM_MIDGARD_GENETICSMANAGER_FITNESS_H_ */
