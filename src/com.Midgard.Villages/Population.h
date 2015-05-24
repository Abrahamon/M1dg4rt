/*
 * Pupolation.h
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_VILLAGES_POPULATION_H_
#define COM_MIDGARD_VILLAGES_POPULATION_H_

#include "../com.Midgard.DataStructures/linkedList.h"
#include "../com.Midgard.Entities/Entity.h"
#include "../com.Midgard.Genetic/Reproduction.h"
#include "../com.Midgard.Genetic/Fitness.h"
#include "../com.Midgard.Resources/RandomNumberGenerator/Random.h"
#include "../com.Midgard.DataStructures/vBinaryTree.h"
#include "../com.Midgard.DataStructures/vBinaryNode.h"
#include <math.h>
#include <pthread.h>

class Population {
private:

protected:
	Fitness* _Fitness;
	LinkedList<Entity*>* _individuos;
	Random* _Random;
	Reproduction* _reproduction;
	string _Eda;
	bool _Evolving;
	short CurrentGeneration;
	int _superstition;

public:
	Population();
	virtual ~Population();

	Entity* randomSelectTheFittest();
	Entity* randomSelectTheFittestMother();
	Entity* randomSelectTheFittestFather();
	float calculateFitnessTo(Entity* pEntity);
	void DoGeneration();
	void DEATH();
	void EverybodyBirthday();
	LinkedList<Entity*>* getIndividuals();
	bool getEvolvingState();
	float desviacionEstandart(LinkedList<Entity*>* pList);
	static pthread_mutex_t mutex;
	short getCurrentGeneration();
	int getCantidadDeIndividuos();
	float getWorstFitness();
	float getBestFitness();
	int getBestAttribute();
	LinkedList<Entity*>* getBestEntities(LinkedList<Entity*>* indList);
	LinkedList<Entity*>* getArmy();

};

#endif /* COM_MIDGARD_VILLAGES_POPULATION_H_ */
