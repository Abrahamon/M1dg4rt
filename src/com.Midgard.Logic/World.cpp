/*
 * World.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: abrahamon
 */

#include "World.h"

Dwarves* World::_Dwarves = 0;
Dark_Elves* World::_Dark_Elves = 0;
Elves* World::_Elves = 0;
Giants* World::_Giants = 0;
pthread_mutex_t World::mutex = PTHREAD_MUTEX_INITIALIZER;
bool World::_Reproduce = true;
Random* World::_random = 0;
JsonWriter * World::JWriter = 0;
/**
 * Constructor
 */
World::World() {


	_Goods = new LinkedList<Good*>();	//Creamos
	_matrix = new PyArray<char>(30,30); //Se inicializa la matriz de 30x30 en 0's por voluntad de los dioses
	_random = new Random();
	JWriter = new JsonWriter();
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


/**
 * Metodo repetitivo, consiste en el ciclo del genetico,
 * selecciona, reproduce, aumenta de edad, probabilidad de morir.
 * Hasta que el material genetico no cambie notablemente
 */
void World::start(){
	pthread_t HiloDwarves;
	pthread_create(&HiloDwarves,0,World::DwarvesGeneration,(void*)this); //Se crea el pthread

	//pthread_t HiloDarkElves;
	//pthread_create(&HiloDarkElves,0,World::DarkElvesGeneration,(void*)this); //Se crea el pthread

	//pthread_t HiloElves;
	//pthread_create(&HiloElves,0,World::ElvesGeneration,(void*)this); //Se crea el pthread

	//pthread_t HiloGiants;
	//pthread_create(&HiloGiants,0,World::GiantsGeneration,(void*)this); //Se crea el pthread
}

void* World::consoleLog(std::string pPopulation,short pGeneration){
	pthread_mutex_lock(&mutex);

	string s = boost::lexical_cast<string>(pGeneration);
	cout<<pPopulation<<s<<endl;

	pthread_mutex_unlock(&mutex);
}
void* World::DwarvesGeneration(void* pPop){
	while(true){
		if(_Reproduce == true){
			if(((_Dwarves->getCurrentGeneration() % Constants::FIGHT_FRECUENCY) == 0) &&
				 _Dwarves->getCurrentGeneration() > 0){
				_Reproduce = false;
			}
			consoleLog("Dwar Gen: ",World::_Dwarves->getCurrentGeneration());

			World::_Dwarves->DoGeneration();
			usleep(200000);
		}
		else if(!_Reproduce){
			for(int i = 0; i <5; i++){
				cout << "Current Fight" << endl;
				sleep(1);
			}
			_Reproduce = true;
		}
	}
	pthread_exit(NULL);
}
void* World::DarkElvesGeneration(void* pPop){
	while(true){
		consoleLog("Dark Gen: ",World::_Dark_Elves->getCurrentGeneration());
		World::_Dark_Elves->DoGeneration();
		usleep(200000);
	}
	pthread_exit(NULL);
}
void* World::ElvesGeneration(void* pPop){
	while(World::_Elves->getCurrentGeneration() < Constants::CANTIDAD_MAX_GENERACIONES){
		consoleLog("Elve Gen: ",World::_Elves->getCurrentGeneration());
		World::_Elves->DoGeneration();
		usleep(200000);
	}
	pthread_exit(NULL);
}
void* World::GiantsGeneration(void* pPop){
	while(World::_Giants->getCurrentGeneration() < Constants::CANTIDAD_MAX_GENERACIONES){
		consoleLog("Gian Gen: ",World::_Giants->getCurrentGeneration());
		World::_Giants->DoGeneration();
		usleep(200000);
	}
	pthread_exit(NULL);
}
Population* World::getFighter(){

}
void* World::Fight(){
	LinkedList<Population*>* pPopulations = new LinkedList<Population*>();
	pPopulations->insertTail(_Dwarves);
	pPopulations->insertTail(_Giants);
	pPopulations->insertTail(_Dark_Elves);
	pPopulations->insertTail(_Elves);

	int randomNumber = _random->getRandomNumber(4);
	Node<Population*>* tmp = pPopulations->getHead();
	for(int i = 0; i<randomNumber; i++){
		tmp = tmp->getNext();
	}
	Population* FighterA = tmp->getData();

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
