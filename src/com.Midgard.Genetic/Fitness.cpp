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

	for(Node<Entity*>* i = pListEntities->getHead();i !=0; i = i->getNext()){

		_IniAttack =  _IniAttack + i->getData()->getGenome()->getCromosome(0);
		_IniSpeed = _IniSpeed + i->getData()->getGenome()->getCromosome(1);
		_IniDefense = _IniDefense + i->getData()->getGenome()->getCromosome(2);
		_IniIntelligence = _IniIntelligence + i->getData()->getGenome()->getCromosome(3);
		_IniMagic = _IniMagic + i->getData()->getGenome()->getCromosome(4);
		_IniEnergy = _IniEnergy + i->getData()->getGenome()->getCromosome(5);
		_IniBloot = _IniBloot + i->getData()->getGenome()->getCromosome(6);
		_IniRunesPower = _IniRunesPower + i->getData()->getGenome()->getCromosome(7);

	}

	cout<<"atributo ataque total:"<<_IniAttack<<endl;

}

int Fitness::calculateFitness(Dwarve* pDwarve){

}


