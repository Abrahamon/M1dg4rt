/*
 * World.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: abrahamon
 */

#include "World.h"

Dwarves* World::_Dwarves = 0;
/**
 * Constructor
 */
World::World() {



	_Goods = new LinkedList<Good*>();	//Creamos
	_matrix = new PyArray<char>(30,30); //Se inicializa la matriz de 30x30 en 0's por voluntad de los dioses

	if(Constants::DWARVES=="true"){
		_Dwarves = new Dwarves();
	}
	if(Constants::ELVES=="true")
		_Elves = new Elves();
	if(Constants::DARK_ELVES=="true")
		_Dark_Elves = new Dark_Elves();
	if(Constants::GIANTS=="true")
		_Giants = new Giants();
	this->onsetOfGoods();

}

/**
 * Destructor
 */
World::~World() {}

/**
 * Incluso los dioses van a tener un comienzo, aqui los instanciamos
 */
void World::onsetOfGoods(){
	Good* newGood;
	for(int i = 0; i < Constants::CANTIDAD_DE_DIOSES; i++){
		newGood = new Good();
		_Goods->insertTail(newGood);
	}
}

/**
 * Metodo repetitivo, consiste en el ciclo del genetico,
 * selecciona, reproduce, aumenta de edad, probabilidad de morir.
 * Hasta que el material genetico no cambie notablemente
 */
void World::start(){
	pthread_t HiloDwarves;
	pthread_create(&HiloDwarves,0,World::DoGeneration,(void*)this); //Se crea el pthread

/*	cout<<"individuo 1 con ataque: "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getAttack()<<
			" con defensa: "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getDefense()<<
			" con bloot: "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getBlot()<<
			" con energy : "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getEnergy()<<
			" con intelligence : "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getIntelligence()<<
			" con magic : "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getMagic()<<
			" con runes power : "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getRunesPower()<<
			" con speed : "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getSpeed()<<endl;
	cout<<"individuo 2 con ataque: "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getGenome()->getAttack()<<
				" con defensa: "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getGenome()->getDefense()<<
				" con bloot: "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getGenome()->getBlot()<<
				" con energy : "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getGenome()->getEnergy()<<
				" con intelligence : "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getGenome()->getIntelligence()<<
				" con magic : "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getGenome()->getMagic()<<
				" con runes power : "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getGenome()->getRunesPower()<<
				" con speed : "<<_Dwarves->getIndividuals()->getHead()->getNext()->getData()->getGenome()->getSpeed()<<endl<<endl;
//	cout<<"edad del ultimo: "<<_Dwarves->getIndividuals()->getTail()->getData()->getAge()<<". Ataque: "<<_Dwarves->getIndividuals()->getTail()->getData()->getGenome()->getAttack()<<endl<<endl;	cout<<"entities final : "<<_Dwarves->getIndividuals()->getLength()<<endl;
//	cout<<"individuo INICIAL con ataque: "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getAttack()<<
//			" con defensa: "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getDefense()<<
//			" con bloot: "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getBlot()<<
//			" con energy : "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getEnergy()<<
//			" con intelligence : "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getIntelligence()<<
//			" con magic : "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getMagic()<<
//			" con runes power : "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getRunesPower()<<
//			" con speed : "<<_Dwarves->getIndividuals()->getHead()->getData()->getGenome()->getSpeed()<<endl;
	//	cout<<"TERMINO\n";

	//for(int i =0; i<5; i++){

		//this->_Dwarves->DoGeneration();
		/if(i%10 == 0){
			if(!_Dwarves->getEvolvingState()){
				break;
				//Las poblaciones dejaron de evolucionar, pasemos a la siguiente etapa
				//cout<<"Termine de evolucionar a probar la solucion!"<<endl;
			}
		}
		if(i%20 ==0){
			cout<<"individuo hijo, con ataque: "<<_Dwarves->getIndividuals()->getTail()->getData()->getGenome()->getAttack()<<
					" con defensa: "<<_Dwarves->getIndividuals()->getTail()->getData()->getGenome()->getDefense()<<
					" con bloot: "<<_Dwarves->getIndividuals()->getTail()->getData()->getGenome()->getBlot()<<
					" con energy : "<<_Dwarves->getIndividuals()->getTail()->getData()->getGenome()->getEnergy()<<
					" con intelligence : "<<_Dwarves->getIndividuals()->getTail()->getData()->getGenome()->getIntelligence()<<
					" con magic : "<<_Dwarves->getIndividuals()->getTail()->getData()->getGenome()->getMagic()<<
					" con runes power : "<<_Dwarves->getIndividuals()->getTail()->getData()->getGenome()->getRunesPower()<<
					" con speed : "<<_Dwarves->getIndividuals()->getTail()->getData()->getGenome()->getSpeed()<<endl;
		}*/
	//}
}


void* World::DoGeneration(void* pPop){
	//Dwarves* pDwarves = new Dwarves();
	//pDwarves = (Dwarves*) pPop;
	ofstream file;
	file.open("Pruebas/Prueba20.ods");

	//file << "Generation"<<","<<"Cantidad"<<"\n";
	file << "Generation"<<","<<"Mejor"<<","<<"Fuerza"<<"\n";
	int MaxCorridas = 10;
	int MaxGeneraciones = 60;
	int CantidadDeIndividuos[MaxGeneraciones];

	float Mejores[MaxGeneraciones];
	float Peores[MaxGeneraciones];


	for(int i = 0; i < MaxGeneraciones; i++){
		CantidadDeIndividuos[i]=0;
		Mejores[i]=0;
		Peores[i]=0;
	}


	for(int i = 0; i < MaxCorridas; i++){
		for(int j = 0; j < MaxGeneraciones; j++){

			CantidadDeIndividuos[j] += World::_Dwarves->getCantidadDeIndividuos();
			Mejores[j]+= World::_Dwarves->getBestFitness();
			//Peores[j]+= World::_Dwarves->getWorstFitness();
			Peores[j]+= World::_Dwarves->getBestAttribute();

			World::_Dwarves->DoGeneration();
		}
		delete _Dwarves;
		_Dwarves = new Dwarves();
		cout << "GENERACION: " <<i << endl;

	}


	for(int i = 0; i < MaxGeneraciones; i++){
		//CantidadDeIndividuos[i] = CantidadDeIndividuos[i]/MaxCorridas;
		//file << i <<","<< CantidadDeIndividuos[i] <<"\n";

		Mejores[i] = Mejores[i]/MaxCorridas;
		Peores[i] = Peores[i]/MaxCorridas;

		file << i <<","<< Mejores[i]<<","<< Peores[i] <<"\n";
	}
	//file << World::_Dwarves->getCurrentGeneration()<<","<<World::_Dwarves->getCantidadDeIndividuos()<<"\n";
	file.close();
	cout << "Archivo Cerrado" << endl;
	system("mplayer -msglevel all=0 -msgmodule alarm.wav");

	pthread_exit(NULL);
}

/*
 * Cargamos el mapa en una matriz dada segun su ruta
 */
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
