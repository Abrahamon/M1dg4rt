/*
 * Elves.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: abrahamon
 */

#include "Elves.h"

Elves::Elves() {
	_random = new Random();
	bool newGender;
	Genome* newGenome ;
	for(int i = 0; i < Constants::MAX_POBLACION_INICIAL; i++){
		newGender = _random->getRandomBool();
		newGenome = new Genome(_random->getRandomNumber(100),
				_random->getRandomNumber(100),
				_random->getRandomNumber(100),
				_random->getRandomNumber(100),
				_random->getRandomNumber(100),
				_random->getRandomNumber(100),
				_random->getRandomNumber(100),
				_random->getRandomNumber(100));
		Elve* newElve = new Elve(newGender,0,0,0,newGenome,_random->getRandomNumber(10));

		this->_individuos->insertTail(newElve);
	}

	_Fitness->setBase(this->_individuos);

}

Elves::~Elves() {
	// TODO Auto-generated destructor stub
}

