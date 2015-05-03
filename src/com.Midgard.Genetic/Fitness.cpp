/*
 * Fitness.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "Fitness.h"

Fitness::Fitness(){

}

Fitness::~Fitness(){
	_IniAttack = 0;
	_IniSpeed = 0;
	_IniDefense = 0;
	_IniIntelligence = 0;
	_IniMagic =0;
	_IniEnergy = 0;
	_IniBloot = 0;
	_IniRunesPower = 0;
	_sumAll = 0;
}


void Fitness::setBase(LinkedList<Entity*>* pListEntities){
	this->~Fitness();
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
		_sumAll = _sumAll + _IniAttack + _IniSpeed + _IniDefense + _IniIntelligence + _IniMagic + _IniEnergy + _IniBloot + _IniRunesPower;
		tmp = tmp->getNext();
	}
}

int Fitness::getSumOfAll(){
	return _sumAll;
}

double Fitness::caculateFitness(Entity* pEntity){
	Genome* pGen = pEntity->getGenome();

	/*cout<<"calculando fitness \n";
	cout<<"ataque:"<<pGen->getAttack()<<endl;
	cout<<"speed:"<<pGen->getSpeed()<<endl;
	cout<<"defense:"<<pGen->getDefense()<<endl;
	cout<<"intelligence:"<<pGen->getIntelligence()<<endl;
	cout<<"magic:"<<pGen->getMagic()<<endl;_sumAll + _IniAttack + _IniSpeed + _IniDefense + _IniIntelligence + _IniMagic + _IniEnergy + _IniBloot + _IniRunesPower
	cout<<"energy:"<<pGen->getEnergy()<<endl;
	cout<<"bloot:"<<pGen->getBlot()<<endl;
	cout<<"runes powa:"<<pGen->getRunesPower()<<endl;*/

	double Thefitness = (pGen->getAttack()/_IniAttack)+(pGen->getSpeed()/_IniSpeed)+(pGen->getDefense()/_IniDefense)+
			(pGen->getIntelligence()/_IniIntelligence)+(pGen->getMagic()/_IniMagic)+(pGen->getEnergy()/_IniEnergy)+
			(pGen->getBlot()/_IniBloot)+(pGen->getRunesPower()/_IniRunesPower);
	return Thefitness;
}



