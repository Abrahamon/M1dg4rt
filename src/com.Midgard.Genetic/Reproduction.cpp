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

/**
 * Reproduccion entre dos Entidades, la primera es el padre, la segunda es la madre
 * retorna el nuevo individuo, creado
 */
Entity* Reproduction::reproducir(Entity* pFather, Entity* pMother){

	if(pFather->getGender() == pMother->getGender()){
		cout<<"Reproduction.reproducir() 	No se reproducen individuos del mismo sexo"<<endl;
		return 0;
	}
	Genome* pFatherGenome = pFather->getGenome();
	Genome* pMotherGenome = pMother->getGenome();
	Genome* newGenome = new Genome(0,0,0,0,0,0,0,0);
	uint16_t pGenFather = 0;
	uint16_t pGenMother = 0;
	uint16_t pNewGen1 = 0;
	uint16_t pNewGen2 = 0;
	uint16_t pMask1 = 1;
	uint16_t pMask2 = 1;

	for(int i = 0; i<9;i++){
		pGenFather = pFatherGenome->getCromosome(i);
		pGenMother = pMotherGenome->getCromosome(i);
		pMask1 = pMask1<<8;
		pMask1 = pMask1 -1;
		pMask2 = ~pMask1;

	//	cout<<"Gen del padre : "<<bitset<16>(pGenFather).to_string()<<" equivale: "<<pGenFather<<endl;
	//	cout<<"Gen de la madre: "<<bitset<16>(pGenMother).to_string()<<" equivale: "<<pGenMother<<endl;

		pNewGen1 = pGenFather & pMask1;
		pNewGen2 = pGenMother & pMask2;
		pNewGen1 = pNewGen1 | pNewGen2;
		newGenome->setCromosome(i,pNewGen1);
	//	cout<<"nuevo Gen Id "<<i<<". Es: "<<bitset<16>(pNewGen1).to_string()<<" equivale: "<<pNewGen1<<endl;
	}
	//La mutacion ocurre dentro de la reproduccion
	newGenome = mutate(newGenome);
	Entity* newEntity = new Entity(true,pFather,pMother,0,newGenome);
	return newEntity;
}

/**
 * Mutacion para un genoma entero
 * De manera iterativa y impredecible
 * modifica gen por gen del genoma
 */
Genome* Reproduction::mutate(Genome* pGenoma){

	for(int i=0; i<8; i++){

	}
	return pGenoma;
}

int Reproduction::Fitness(Dwarve* pDwarve){
	for(int i = 0; i<9; i++){
		uint16_t value = pDwarve->getGenome()->getCromosome(i);
		cout<<value<<endl;
	}
}

int Reproduction::Fitness(Elve* pElve){

}

int Reproduction::Fitness(Giant* pGiant){

}

int Reproduction::Fitness(Human* pHuman){

}

















