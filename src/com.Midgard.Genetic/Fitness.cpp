/*
 * Fitness.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "Fitness.h"

Fitness::Fitness(){

}

Fitness::~Fitness(){}


void Fitness::setBase(LinkedList<Entity*>* pListEntities){

	Node<Entity*>* tmp = pListEntities->getHead();
	for(int j = 0 ; j < pListEntities->getLength(); j++){

		_IniAttack =  _IniAttack + tmp->getData()->getGenome()->getCromosome(0);
		_IniSpeed = _IniSpeed + tmp->getData()->getGenome()->getCromosome(1);
		_IniDefense = _IniDefense + tmp->getData()->getGenome()->getCromosome(2);
		_IniIntelligence = _IniIntelligence + tmp->getData()->getGenome()->getCromosome(3);
		_IniMagic = _IniMagic + tmp->getData()->getGenome()->getCromosome(4);
		_IniEnergy = _IniEnergy + tmp->getData()->getGenome()->getCromosome(5);
		_IniBloot = _IniBloot + tmp->getData()->getGenome()->getCromosome(6);
		_IniRunesPower = _IniRunesPower + tmp->getData()->getGenome()->getCromosome(7);
		tmp = tmp->getNext();
	}

}

int Fitness::calculateFitness(Dwarve* pDwarve){
	Genome* pGen = pDwarve->getGenome();

	int Thefitness = (pGen->getAttack()/_IniAttack)+(pGen->getSpeed()/_IniSpeed)+(pGen->getDefense()/_IniDefense)+
			(pGen->getIntelligence()/_IniIntelligence)+(pGen->getMagic()/_IniMagic)+(pGen->getEnergy()/_IniEnergy)+
			(pGen->getBlot()/_IniBloot)+(pGen->getRunesPower()/_IniRunesPower);
	return Thefitness;
}


