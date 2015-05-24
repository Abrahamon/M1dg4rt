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
bool World::_ReproduceDwarves = true;
bool World::_ReproduceDarkElves = true;
bool World::_ReproduceElves = true;
bool World::_ReproduceGiants = true;
bool World::_RunningSimulation = true;
bool World::_FightIsAvailable = false;
int World::_FightTimer = 0;
Random* World::_random = 0;
JsonWriter* World::_DwarvesWriter = 0;
JsonWriter* World::_DarkElvesWriter = 0;
JsonWriter* World::_ElvesWriter = 0;
JsonWriter* World::_GiantsWriter = 0;
JsonWriter* World::_TimeWriter = 0;
int World::timeSleep = 0;
int World::timeInSeconds =0;
int World::timeSinceLastWar=0;
int World::reportFrecuency = 0;

/**
 * Constructor
 */
World::World() {


	_Goods = new LinkedList<God*>();	//Creamos
	_matrix = new PyArray<char>(30,30); //Se inicializa la matriz de 30x30 en 0's por voluntad de los dioses
	_random = new Random();

	_DwarvesWriter = new JsonWriter();
	_DarkElvesWriter = new JsonWriter();
	_ElvesWriter = new JsonWriter();
	_GiantsWriter = new JsonWriter();
	_TimeWriter = new JsonWriter();

	timeSleep = Constants::GENERATION_SLEEP_uSeconds;
	reportFrecuency = Constants::FRECUENCY_REPORT_Gens;

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
 * Método que permite la instanciación de los Dioses. Almacenados en
 * una lista para acceso fácil a los mismos.
 */
void World::onsetOfGoods(){
	God* newGod;
	for(int i = 0; i < Constants::CANTIDAD_DE_DIOSES; i++){
		newGod = new God("zeus");
		_Goods->insertTail(newGod);
	}
}

/**
 * Método de inicio, de la simulación. Se crean todos los threads
 * necesarios, uno correspondiente a cada población.
 */
void World::start(){
	resetJSONs();
	/*for(int i = 5; i > 0; i--){
		cout<<"Starting simulation in "<<i<<"..."<<endl;
		sleep(1);
	}*/
	cout<<endl;
	if(Constants::DWARVES=="true"){
		pthread_t HiloDwarves;
		pthread_create(&HiloDwarves,0,World::DwarvesGeneration,(void*)this);
	}
	if(Constants::DARK_ELVES=="true"){
		pthread_t HiloDarkElves;
		pthread_create(&HiloDarkElves,0,World::DarkElvesGeneration,(void*)this);
	}
	if(Constants::ELVES=="true"){
		pthread_t HiloElves;
		pthread_create(&HiloElves,0,World::ElvesGeneration,(void*)this);
	}
	if(Constants::GIANTS=="true"){
		pthread_t HiloGiants;
		pthread_create(&HiloGiants,0,World::GiantsGeneration,(void*)this);
	}
	pthread_t Controller;
	pthread_create(&Controller,0,World::TimeController,(void*)this);
}

void* World::consoleLog(std::string pPopulation,short pGeneration){
	pthread_mutex_lock(&mutex);

	string s = boost::lexical_cast<string>(pGeneration);
	cout<<pPopulation<<s<<endl;

	pthread_mutex_unlock(&mutex);
	return 0;
}
void* World::DwarvesGeneration(void* pPop){
	while(true){
		if(_ReproduceDwarves == true){
			if(_Dwarves->getCurrentGeneration() == Constants::CANTIDAD_MAX_GENERACIONES){
				break;
			}
			if(Constants::HARD_DEBUG == "true")
				consoleLog("Dwar Gen: ",World::_Dwarves->getCurrentGeneration());

			string quantity = lexical_cast<string>(World::_Dwarves->getIndividuals()->getLength());
			string message = "Dwarves:2:"+ quantity + ":0:0:#";
			_DwarvesWriter->updateVillageInfo(message,"Dwarves");

			World::_Dwarves->DoGeneration();
			usleep(timeSleep);
		}
	}
	Constants::VillageFinishedLinage(); //Notificar que ya se termino el linage de esta especie
	pthread_exit(NULL);
}
void* World::DarkElvesGeneration(void* pPop){
	while(true){
		if(_ReproduceDarkElves == true){
			if(_Dark_Elves->getCurrentGeneration() == Constants::CANTIDAD_MAX_GENERACIONES){
				break;
			}
			if(Constants::HARD_DEBUG == "true")
				consoleLog("Dark Gen: ",World::_Dark_Elves->getCurrentGeneration());

			string quantity = lexical_cast<string>(World::_Dark_Elves->getIndividuals()->getLength());
			string message = "DarkElves:2:"+ quantity + ":0:0:#";
			_DarkElvesWriter->updateVillageInfo(message,"DarkElves");

			World::_Dark_Elves->DoGeneration();
			usleep(timeSleep);
		}
	}
	Constants::VillageFinishedLinage(); //Notificar que ya se termino el linage de esta especie
	pthread_exit(NULL);
}
void* World::ElvesGeneration(void* pPop){
	while(true){
		if(_ReproduceElves == true){
			if(_Elves->getCurrentGeneration() == Constants::CANTIDAD_MAX_GENERACIONES){
				break;
			}
			if(Constants::HARD_DEBUG == "true")
				consoleLog("Elve Gen: ",World::_Elves->getCurrentGeneration());

			string quantity = lexical_cast<string>(World::_Elves->getIndividuals()->getLength());
			string message = "Elves:2:"+ quantity + ":0:0:#";
			_ElvesWriter->updateVillageInfo(message,"Elves");

			World::_Elves->DoGeneration();
			usleep(timeSleep);
		}
	}
	Constants::VillageFinishedLinage(); //Notificar que ya se termino el linage de esta especie
	pthread_exit(NULL);
}
void* World::GiantsGeneration(void* pPop){
	while(true){
		if(_ReproduceGiants == true){
			if(_Giants->getCurrentGeneration() == Constants::CANTIDAD_MAX_GENERACIONES){
				break;
			}
			if(Constants::HARD_DEBUG == "true")
				consoleLog("Gian Gen: ",World::_Giants->getCurrentGeneration());

			string quantity = lexical_cast<string>(World::_Giants->getIndividuals()->getLength());
			string message = "Giants:2:"+ quantity + ":0:0:#";
			_GiantsWriter->updateVillageInfo(message,"Giants");

			World::_Giants->DoGeneration();
			usleep(timeSleep);
		}
	}
	Constants::VillageFinishedLinage(); //Notificar que ya se termino el linage de esta especie
	pthread_exit(NULL);
}


int World::getBestFighterOption(Population* popA, Population* popB){
	if(popA->getBestFitness() > popB->getBestFitness()){
		return 1;
	}
	else{
		return 2;
	}
}
void* World::TimeController(void* pPop){
	while(_RunningSimulation){
		if(timeInSeconds % reportFrecuency == 0){
			if(Constants::DEBUG == "true"){
				cout<<"-- Simulación en Curso "<< "Reporte: "<< timeInSeconds / reportFrecuency<< endl;

				cout << "Dwarves:   "<< _Dwarves->getIndividuals()->getLength()
					 <<"   Generacion: "<< _Dwarves->getCurrentGeneration()<<endl;

				cout << "Giants:    "<< _Giants->getIndividuals()->getLength()
					 <<"   Generacion: "<< _Giants->getCurrentGeneration()<<endl;

				cout << "Elves:     "<< _Elves->getIndividuals()->getLength()
					 <<"   Generacion: "<< _Elves->getCurrentGeneration()<<endl;

				cout << "DarkElves: "<< _Dark_Elves->getIndividuals()->getLength()
					 <<"   Generacion: "<< _Dark_Elves->getCurrentGeneration()<<endl;
				cout<<"-------------------------------------------"<< endl;
				cout<<endl;
			}

		}
		if(_Dwarves->getCurrentGeneration() > 15 && _FightIsAvailable == false){
				pthread_mutex_lock(&mutex);
				int A = getBestFighterOption(_Dwarves,_Elves);
				int B = getBestFighterOption(_Dark_Elves,_Giants)+2;

				if(A== 1 || B == 1){
					_ReproduceDwarves = false;
					_DwarvesWriter->updateVillageEntitiesList("Dwarves",_Dwarves->getArmy());
					//_DwarvesWriter->updateVillageEntitiesList("Dwarves",_Dwarves->getBestEntities(_Dwarves->getIndividuals()));
				}
				if(A== 2 || B == 2){
					_ReproduceElves = false;
					_ElvesWriter->updateVillageEntitiesList("Elves",_Elves->getArmy());
					//_ElvesWriter->updateVillageEntitiesList("Elves",_Elves->getBestEntities(_Elves->getIndividuals()));
				}
				if(A== 3 || B == 3){
					_ReproduceDarkElves = false;
					_DarkElvesWriter->updateVillageEntitiesList("DarkElves",_Dark_Elves->getArmy());
					//_DarkElvesWriter->updateVillageEntitiesList("DarkElves",_Dark_Elves->getBestEntities(_Dark_Elves->getIndividuals()));
				}
				if(A== 4 || B == 4){
					_ReproduceGiants = false;
					_GiantsWriter->updateVillageEntitiesList("Giants",_Giants->getArmy());
					//_GiantsWriter->updateVillageEntitiesList("Giants",_Giants->getBestEntities(_Giants->getIndividuals()));
				}
				_FightIsAvailable = true;
				_DarkElvesWriter->startFight("true",A,B);

				if(Constants::DEBUG == "true"){
					cout<<endl;
					cout<<"##########################"<<endl;
					cout<<"   A war is in progrss    "<<endl;
					cout<<"     "+lexical_cast<string>(A)+"  vs  "+lexical_cast<string>(B)+"     "<<endl;
					cout<<"##########################"<<endl;
					cout<<endl;
				}
				pthread_mutex_unlock(&mutex);
		}
		if(_FightIsAvailable == true){
			if(_FightTimer >= 35){ //Cuando se acabe la batalla, se debe correr este código.
				_ReproduceDwarves = true;
				_ReproduceElves = true;
				_ReproduceDarkElves = true;
				_ReproduceGiants = true;
				_FightIsAvailable = false;
				_FightTimer=0;

				if(Constants::DEBUG == "true"){
					cout<<endl;
					cout<<"##########################"<<endl;
					cout<< "BATALLA TERMINADA"<<endl;
					cout<<"##########################"<<endl;
				}
				_DwarvesWriter->resetVillageArmy("Dwarves");
				_ElvesWriter->resetVillageArmy("Elves");
				_DarkElvesWriter->resetVillageArmy("DarkElves");
				_GiantsWriter->resetVillageArmy("Giants");
				_DarkElvesWriter->startFight("false",0,0);
			}
			_FightTimer++;
		}

		if(Constants::getVillagesWhoFinishedItsLinage() >= 4){
			cout<<" "<<endl;
			cout<<"## La simulación ha finalizado ##"<< endl;
			int endDwarves = World::_Dwarves->getIndividuals()->getLength();
			int endGiants = World::_Giants->getIndividuals()->getLength();
			int endElves = World::_Elves->getIndividuals()->getLength();
			int endDarkElves = World::_Dark_Elves->getIndividuals()->getLength();

			string msgD  = "Dwarves:2:"+ lexical_cast<string>(endDwarves) + ":0:0:#";
			string msgG  = "Giants:2:"+ lexical_cast<string>(endGiants) + ":0:0:#";
			string msgE  = "Elves:2:"+ lexical_cast<string>(endElves) + ":0:0:#";
			string msgDE = "DarkElves:2:"+ lexical_cast<string>(endDarkElves) + ":0:0:#";

			_DwarvesWriter->updateVillageInfo(msgD,"Dwarves");
			_GiantsWriter->updateVillageInfo(msgG,"Giants");
			_ElvesWriter->updateVillageInfo(msgE,"Elves");
			_DarkElvesWriter->updateVillageInfo(msgDE,"DarkElves");

			cout << "Total de Inviduos: "<<Constants::IDCounter << endl;
			cout << "Cantidad de Dwarves: "<< endDwarves << endl;
			cout << "Cantidad de Elves: " << endElves<< endl;
			cout << "Cantidad de Giants: "<< endGiants << endl;
			cout << "Cantidad de DarkElves: "<< endDarkElves << endl;
			cout<<"################################"<< endl;
			Constants::resetVillagesLinageCounter();
			_RunningSimulation=false;
			cout<<" "<<endl;
		}
		sleep(1);
		_TimeWriter->updateTime(timeInSeconds);
		timeInSeconds++;


	}
	for(int i = 5; i > 0; i--){
		cout<<"Ending simulation in "<<i<<"..."<<endl;
		sleep(1);
	}
	resetJSONs();
	exit(0);
	pthread_exit(NULL);
}
void World::resetJSONs(){
	_DwarvesWriter->updateVillageInfo("Dwarves:2:0:0:0:#","Dwarves");
	_DwarvesWriter->resetVillageArmy("Dwarves");
	_GiantsWriter->updateVillageInfo("Giants:2:0:0:0:#","Giants");
	_GiantsWriter->resetVillageArmy("Giants");
	_ElvesWriter->updateVillageInfo("Elves:2:0:0:0:#","Elves");
	_ElvesWriter->resetVillageArmy("Elves");
	_DarkElvesWriter->updateVillageInfo("DarkElves:2:0:0:0:#","DarkElves");
	_DarkElvesWriter->resetVillageArmy("DarkElves");

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
	std::string ruta = "src/com.Midgard.Resources/MapEditor/MapFiles/";
	ruta+=pathToFile;
	//ifstream MapFile ("src/com.Midgard.Resources/MapEditor/MapFiles/prueba1.map");
	ifstream MapFile (ruta);

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

/**
 * Método para pruebas del rendimiento del algoritmos genético.
 * Permite testear la cantidad de personas creadas, fitness
 * y características en general de la población a través del
 * tiempo.
 */
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
