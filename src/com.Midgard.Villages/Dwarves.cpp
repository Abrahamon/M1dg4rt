/*
 * Dwarves.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "../com.Midgard.Villages/Dwarves.h"

Dwarves::Dwarves() {
	bool newGender;
	Genome* newGenome ;
	for(int i = 0; i < Constants::MAX_POBLACION_INICIAL; i++){
		newGender = this->_random->getRandomBool();
		newGenome = new Genome(_random->getRandomNumber(10),
				_random->getRandomNumber(10),
				_random->getRandomNumber(10),
				_random->getRandomNumber(10),
				_random->getRandomNumber(10),
				_random->getRandomNumber(10),
				_random->getRandomNumber(10),
				_random->getRandomNumber(10));
		Dwarve* newDwarve = new Dwarve(newGender,0,0,0,newGenome,_random->getRandomNumber(10));

		this->_individuos->insertTail(newDwarve);
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

Dwarves::~Dwarves() {

}




