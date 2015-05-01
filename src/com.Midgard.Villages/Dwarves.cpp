/*
 * Dwarves.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "../com.Midgard.Villages/Dwarves.h"

Dwarves::Dwarves() {
	bool newGender = true;
	Genome* newGenome ;
	for(int i = 0; i < Constants::MAX_POBLACION_INICIAL; i++){
		newGenome = new Genome(_random->getRandomNumber(50),
				_random->getRandomNumber(50),
				_random->getRandomNumber(50),
				_random->getRandomNumber(50),
				_random->getRandomNumber(50),
				_random->getRandomNumber(50),
				_random->getRandomNumber(50),
				_random->getRandomNumber(50));
		Dwarve* newDwarve = new Dwarve(newGender,0,0,0,newGenome,0);
		this->_individuos->insertTail(newDwarve);
	}
	cout<<"termine \n";
	_Fitness->setBase(this->_individuos);

}

Dwarves::~Dwarves() {

}

