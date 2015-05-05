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
