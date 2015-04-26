/*
 * Reproduction.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: abrahamon
 */

#include "Reproduction.h"

Reproduction* Reproduction::_Reproduction = 0;


Reproduction::Reproduction() {
	// TODO Auto-generated constructor stub

}

Reproduction::~Reproduction() {
	// TODO Auto-generated destructor stub
}

Reproduction* Reproduction::getInstance(){
	if(_Reproduction == 0){
		_Reproduction = new Reproduction();
	}
	return _Reproduction;
}

Entity* Reproduction::reproducir(Entity* pFather, Entity* pMother){
	std::cout<<"reproduciendo \n";

	Genome* pFatherGenome = pFather->getGenome();
	Genome* pMotherGenome = pMother->getGenome();
	short pGenFather = 0;
	short pGenMother = 0;
	short pNewGen = 0;
	Genome* newGenome = new Genome(0,0,0,0,0,0,0,0);

	for(int i = 0; i<Constants::CANTIDAD_DE_GENES;i++){
		pGenFather = pFatherGenome->getCromosome(i);
		pGenMother = pMotherGenome->getCromosome(i);

		cout<<pGenFather<<endl;
		newGenome->setCromosome(i,pNewGen);
	}

	short a = 187;
	short b = (a& 14) >> 1;


	Entity* newEntity = new Entity(true,pFather,pMother,0,newGenome);
	std::cout<<"termine de reproducir \n";
	return newEntity;
}



















