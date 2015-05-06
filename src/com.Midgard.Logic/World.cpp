/*
 * World.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: abrahamon
 */

#include "World.h"

World::World() {
	if(Constants::DWARVES=="true"){
		cout<<"World() 		creo unos enanitos verdes\n"<<endl;
		_Dwarves = new Dwarves();}
	if(Constants::ELVES=="true")
		_Elves = new Elves();
	if(Constants::DARK_ELVES=="true")
		_Dark_Elves = new Dark_Elves();
	if(Constants::GIANTS=="true")
		_Giants = new Giants();
}

World::~World() {}

void World::start(){

	cout<<"edad del primero: "<<_Dwarves->getIndividuals()->getHead()->getData()->getAge()<<". Fitness: "<<_Dwarves->calculateFitnessTo(_Dwarves->getIndividuals()->getHead()->getData())<<endl;
	cout<<"edad del segunda: "<<_Dwarves->getIndividuals()->getHead()->getPrevious()->getData()->getAge()<<". Fitness: "<<_Dwarves->calculateFitnessTo(_Dwarves->getIndividuals()->getHead()->getPrevious()->getData())<<endl<<endl;

	for(int i =0; i<1; i++){
		this->_Dwarves->DoGeneration();
	//	cout<<"termino ------------------------------------------- generacion: "<<i<<endl;
	}
	cout<<"edad del primero: "<<_Dwarves->getIndividuals()->getHead()->getData()->getAge()<<". Fitness: "<<_Dwarves->calculateFitnessTo(_Dwarves->getIndividuals()->getHead()->getData())<<endl;
	cout<<"edad del segundo: "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getAge()<<". Fitness: "<<_Dwarves->calculateFitnessTo(_Dwarves->getIndividuals()->getHead()->getPrevious()->getData())<<endl;
	cout<<"edad del tercero: "<<_Dwarves->getIndividuals()->getHead()->getNext()->getNext()->getData()->getAge()<<". Fitness: "<<_Dwarves->calculateFitnessTo(_Dwarves->getIndividuals()->getHead()->getPrevious()->getData())<<endl;
}

