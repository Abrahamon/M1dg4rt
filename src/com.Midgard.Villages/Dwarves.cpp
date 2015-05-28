/*
 * Dwarves.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "../com.Midgard.Villages/Dwarves.h"

/**
 * Constructor que inizializa la poblacion de acuerda a config.xml
 */
Dwarves::Dwarves() {

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




