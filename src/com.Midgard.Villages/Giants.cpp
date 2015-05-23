/*
 * Giants.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: abrahamon
 */

#include "Giants.h"

Giants::Giants() {
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
		Giant* newGiant = new Giant(newGender,0,0,0,newGenome,_random->getRandomNumber(10));

		this->_individuos->insertTail(newGiant);
	}

	_Fitness->setBase(this->_individuos);

}

Giants::~Giants() {
	// TODO Auto-generated destructor stub
}

