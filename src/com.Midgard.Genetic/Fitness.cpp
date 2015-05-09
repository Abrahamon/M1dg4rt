/*
 * Fitness.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "Fitness.h"

/**
 * Constructor
 * Cada una de las siguientes variables, almacena la sumatoria de todos los respectivos
 * genes de la poblacion inicial, para el calculo de fitness en el futuro.
 */
Fitness::Fitness(){
	_IniAttack = 0;
	_IniSpeed = 0;
	_IniDefense = 0;
	_IniIntelligence = 0;
	_IniMagic =0;
	_IniEnergy = 0;
	_IniBloot = 0;
	_IniRunesPower = 0;
}

/**
 * Destructor
 */
Fitness::~Fitness(){}

/**
 * Reiniciar todas las sumas
 */
void Fitness::restarData(){
	_IniAttack = 0;
	_IniSpeed = 0;
	_IniDefense = 0;
	_IniIntelligence = 0;
	_IniMagic =0;
	_IniEnergy = 0;
	_IniBloot = 0;
	_IniRunesPower = 0;
}

/**
 * Calcular de nuevo la suma de todos los respectivos genes en la poblacion
 */
void Fitness::setBase(LinkedList<Entity*>* pListEntities){
	this->restarData();
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

	return;
}

/**
 * Retorna la suma de todos los atributos en conjunto
 */
int Fitness::getSumOfAll(){
	return _IniAttack + _IniSpeed + _IniDefense + _IniIntelligence + _IniMagic + _IniEnergy + _IniBloot + _IniRunesPower;;
}

/**
 * Con la suma de todos tenemos el denominador
 * el numerador es el gen respectivo del pEntity argumento.
 * La suma de cada una de las diviciones es el fitness total.
 */
float Fitness::caculateFitness(Entity* pEntity){
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

	float Thefitness = (pGen->getAttack()/_IniAttack)+(pGen->getSpeed()/_IniSpeed)+(pGen->getDefense()/_IniDefense)+
			(pGen->getIntelligence()/_IniIntelligence)+(pGen->getMagic()/_IniMagic)+(pGen->getEnergy()/_IniEnergy)+
			(pGen->getBlot()/_IniBloot)+(pGen->getRunesPower()/_IniRunesPower);
	return Thefitness;

}





