/*
 * World.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: abrahamon
 */

#include "World.h"

World::World() {
	if(Constants::DWARVES=="true"){
		cout<<"World() 		creo unos enanitos verdes\n";
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

	cout<<"ataque del primero "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getAttack()<<endl;

	for(int i =0; i<51; i++){
		this->_Dwarves->DoGeneration();
	//	cout<<"termino ------------------------------------------- generacion: "<<i<<endl;
	}
	cout<<"numero de individuos: "<<_Dwarves->getIndividuals()->getLength()<<endl;
	cout<<"ataque del ultimo nacido : "<<_Dwarves->getIndividuals()->getHead()->getPrevious()->getData()->getGenome()->getAttack()<<endl;
}

