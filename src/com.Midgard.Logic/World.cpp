/*
 * World.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: abrahamon
 */

#include "World.h"

World::World() {
	_matrix = new PyArray<char>(30,30); //Se inicializa la matriz de 30x30 en 0's

	if(Constants::DWARVES=="true"){
		_Dwarves = new Dwarves();
	}
	if(Constants::ELVES=="true")
		_Elves = new Elves();
	if(Constants::DARK_ELVES=="true")
		_Dark_Elves = new Dark_Elves();
	if(Constants::GIANTS=="true")
		_Giants = new Giants();
}

World::~World() {}

void World::start(){

//	cout<<"fitness ultimo: "<< _Dwarves->calculateFitnessTo(_Dwarves->getIndividuals()->getHead()->getData())<<endl;
//	cout<<"entities inicio : "<<_Dwarves->getIndividuals()->getLength()<<endl;
	cout<<"edad del primero: "<<_Dwarves->getIndividuals()->getHead()->getData()->getAge()<<". Ataque: "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getAttack()<<endl<<endl;
	cout<<"inteligencia: "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getIntelligence()<<endl;
	cout<<"defensa: "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getDefense()<<endl;
	for(int i =0; i<25; i++){
		this->_Dwarves->DoGeneration();
	//	cout<<"Nueva generacion terminada: "<<i<<endl;
	}
//	cout<<"TERMINO\n";
//	cout<<"fitness ultimo: "<< _Dwarves->calculateFitnessTo(_Dwarves->getIndividuals()->getHead()->getData())<<endl;
//	cout<<"edad del ultimo: "<<_Dwarves->getIndividuals()->getTail()->getData()->getAge()<<". Ataque: "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getAttack()<<endl<<endl;
//	cout<<"edad del primero: "<<_Dwarves->getIndividuals()->getHead()->getData()->getAge()<<". Fitness: "<<_Dwarves->calculateFitnessTo(_Dwarves->getIndividuals()->getHead()->getData())<<endl;
//	cout<<"edad del segundo: "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getAge()<<". Fitness: "<<_Dwarves->calculateFitnessTo(_Dwarves->getIndividuals()->getHead()->getPrevious()->getData())<<endl;
//	cout<<"ataque del segundo: "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getGenome()->getAttack()<<endl;
//	cout<<"edad del tercero: "<<_Dwarves->getIndividuals()->getHead()->getNext()->getNext()->getData()->getAge()<<". Fitness: "<<_Dwarves->calculateFitnessTo(_Dwarves->getIndividuals()->getHead()->getPrevious()->getData())<<endl;
//	cout<<"entities final : "<<_Dwarves->getIndividuals()->getLength()<<endl;
//	cout<<"TERMINO\n";
}

bool World::loadMap(std::string pathToFile){

	//ifstream MapFile ("src/com.Midgard.Resources/MapEditor/MapFiles/prueba1.map");
	ifstream MapFile (pathToFile);

	int mat = 0;
		if (MapFile.is_open()){
			for(int i = 0; i < 30; i ++){
				for(int j = 0; j < 30; j++){
					if(mat == 0){
						char x = MapFile.get();
						_matrix->setDataID(i,j,(char)x);
						if(j == 29){
							MapFile.get();
						}

					}
					else{
						char x = MapFile.get();
						_matrix->setDataID(i,j,(char)x);
						if(j==29){
							MapFile.get();
						}
					}
				}
				mat++;
			}
			MapFile.close();
			//_matrix->printMatrix();
			return true;
		}

		else {
			cout << "**World/LoadMatrix ** - Unable to open file";
			return false;
		}
}
