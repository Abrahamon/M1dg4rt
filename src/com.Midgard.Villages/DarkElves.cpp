/*
 * DarkElves.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: abrahamon
 */

#include "DarkElves.h"

Dark_Elves::Dark_Elves() {
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
		Human* newHuman = new Human(newGender,0,0,0,newGenome,_random->getRandomNumber(10));

		this->_individuos->insertTail(newHuman);
//		if(newGender)
//			cout<<"creo un hombre ";
//		else
//			cout<<"creo una mujer ";
//		cout<<"con ataque :"<<newGenome->getAttack()<<". Speed: "<<newGenome->getDefense()<<". Defense: "<<newGenome->getDefense()<<
//				". Int: "<<newGenome->getIntelligence()<<". Magic: "<<newGenome->getMagic()<<". Energy: "<<newGenome->getEnergy()<<
//				" Bloot: "<<newGenome->getBlot()<<". Runes powa: "<<newGenome->getRunesPower()<<endl;
	}

	_Fitness->setBase(this->_individuos);

}

Dark_Elves::~Dark_Elves() {
	// TODO Auto-generated destructor stub
}

