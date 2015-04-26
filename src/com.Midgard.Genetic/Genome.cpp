/*
 * Genome.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: fabian
 */

#include "Genome.h"

Genome::Genome(short Attack,short Speed, short Defense, short Intelligence,
		   short Magic, short Energy,short Blot, short RunesPower){

	insertTail(Attack);
	insertTail(Speed);
	insertTail(Defense);
	insertTail(Intelligence);
	insertTail(Magic);
	insertTail(Energy);
	insertTail(Blot);
	insertTail(RunesPower);
}

Genome::~Genome() {}

void Genome::deleteData(short p){}

short Genome::getCromosome(int pCromID){
	Node<short>* tmp = getHead();
	for (int i=0; i < pCromID; i++){
		tmp = tmp->getNext();
	}
	return tmp->getData();
}

void Genome::setCromosome(int pCromID, short pData){
	Node<short>* tmp = getHead();
	for(int i = 0; i!=pCromID;i++){
		tmp = tmp->getNext();
	}
	tmp->setData(pData);
}

short Genome::getAttack(){ return getCromosome(0); }
short Genome::getSpeed(){ return getCromosome(1); }
short Genome::getDefense(){ return getCromosome(2); }
short Genome::getIntelligence(){ return getCromosome(3); }
short Genome::getMagic(){ return getCromosome(4); }
short Genome::getEnergy(){ return getCromosome(5); }
short Genome::getBlot(){ return getCromosome(6); }
short Genome::getRunesPower(){ return getCromosome(7); }

