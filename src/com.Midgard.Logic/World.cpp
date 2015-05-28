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
JsonWriter* World::_GodsWriter =0;
int World::timeSleep = 0;
int World::timeInSeconds =0;
int World::timeSinceLastWar=0;
int World::reportFrecuency = 0;
int World::MaxGenerations = 0;
int World::_finalDwarvesPopulation;
int World::_finalDarkElvesPopulation;
int World::_finalElvesPopulation;
int World::_finalGiantsPopulation;
LinkedList<God*>* World::_GodsList;

/**
 * Constructor
 */
World::World() {


	_GodsList = new LinkedList<God*>();	//Creamos
	_matrix = new PyArray<char>(30,30); //Se inicializa la matriz de 30x30 en 0's por voluntad de los dioses
	_random = new Random();

	_DwarvesWriter = new JsonWriter();
	_DarkElvesWriter = new JsonWriter();
	_ElvesWriter = new JsonWriter();
	_GiantsWriter = new JsonWriter();
	_TimeWriter = new JsonWriter();
	_GodsWriter = new JsonWriter();

	timeSleep = Constants::GENERATION_SLEEP_uSeconds;
	reportFrecuency = Constants::FRECUENCY_REPORT_Gens;
	MaxGenerations = Constants::CANTIDAD_MAX_GENERACIONES;

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
	God* Dios1 = new God("ZEUS");
	God* Dios2 = new God("HADES");
	God* Dios3 = new God("POSEIDON");
	God* Dios4 = new God("THOR");

	_GodsList->insertTail(Dios1);
	_GodsList->insertTail(Dios2);
	_GodsList->insertTail(Dios3);
	_GodsList->insertTail(Dios4);
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
			string quantity = lexical_cast<string>(World::_Dwarves->getIndividuals()->getLength());
			string gene = lexical_cast<string>(World::_Dwarves->getCurrentGeneration());
			string message = "Dwarves:"+gene+":"+ quantity +":0:0:#";
			_DwarvesWriter->updateVillageInfo(message,"Dwarves");

			if(_Dwarves->getCurrentGeneration() == MaxGenerations || _Dwarves->getEvolvingState()==false){
				break;
			}
			if(Constants::HARD_DEBUG == "true")
				consoleLog("Dwar Gen: ",World::_Dwarves->getCurrentGeneration());



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
			string quantity = lexical_cast<string>(World::_Dark_Elves->getIndividuals()->getLength());
			string gene = lexical_cast<string>(World::_Dark_Elves->getCurrentGeneration());
			string message = "DarkElves:"+gene+":"+ quantity +":0:0:#";
			_DarkElvesWriter->updateVillageInfo(message,"DarkElves");

			if(_Dark_Elves->getCurrentGeneration() == MaxGenerations || _Dark_Elves->getEvolvingState()==false){
				break;
			}
			if(Constants::HARD_DEBUG == "true")
				consoleLog("Dark Gen: ",World::_Dark_Elves->getCurrentGeneration());

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
			string quantity = lexical_cast<string>(World::_Elves->getIndividuals()->getLength());
			string gene = lexical_cast<string>(World::_Elves->getCurrentGeneration());
			string message = "Elves:"+gene+":"+ quantity +":0:0:#";
			_ElvesWriter->updateVillageInfo(message,"Elves");
			if(_Elves->getCurrentGeneration() == MaxGenerations || _Elves->getEvolvingState()==false){
				break;
			}
			if(Constants::HARD_DEBUG == "true")
				consoleLog("Elve Gen: ",World::_Elves->getCurrentGeneration());

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
			string quantity = lexical_cast<string>(World::_Giants->getIndividuals()->getLength());
			string gene = lexical_cast<string>(World::_Giants->getCurrentGeneration());
			string message = "Giants:"+gene+":"+ quantity +":0:0:#";
			_GiantsWriter->updateVillageInfo(message,"Giants");

			if(_Giants->getCurrentGeneration() == MaxGenerations || _Giants->getEvolvingState()==false){
				break;
			}
			if(Constants::HARD_DEBUG == "true")
				consoleLog("Gian Gen: ",World::_Giants->getCurrentGeneration());

			World::_Giants->DoGeneration();
			usleep(timeSleep);
		}
	}
	Constants::VillageFinishedLinage(); //Notificar que ya se termino el linage de esta especie
	pthread_exit(NULL);
}

bool World::ContinueFight(int PopMembers[4], God* Dioses[4]){
	if(PopMembers[0] <= 0 && PopMembers[1] <= 0 && PopMembers[2] <= 0 && PopMembers[3] <= 0) return false;
	else if(Dioses[0]->getLife() <= 0 && Dioses[1]->getLife() <= 0 &&
			Dioses[2]->getLife() <= 0 && Dioses[3]->getLife() <= 0) return false;
	else{
		return true;
	}
}
void World::fightTheGods(){
	Population* ListaPueblos[4] = {_Dwarves,_Dark_Elves,_Elves,_Giants};

	God* Dioses[4] = {_GodsList->getHead()->getData(),
					  _GodsList->getHead()->getNext()->getData(),
					  _GodsList->getHead()->getNext()->getNext()->getData(),
					  _GodsList->getHead()->getNext()->getNext()->getNext()->getData()};

	Node<God*>* DiosEnPeleaActual = _GodsList->getHead();
	int VidaDwarves = ListaPueblos[0]->getIndividuals()->getLength();
	int VidaDarkElves = ListaPueblos[1]->getIndividuals()->getLength();
	int VidaElves = ListaPueblos[2]->getIndividuals()->getLength();
	int VidaGiants = ListaPueblos[3]->getIndividuals()->getLength();

	int PopMembers[4] = {VidaDwarves,VidaDarkElves,VidaElves,VidaGiants};

	while(ContinueFight(PopMembers,Dioses) == true){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(PopMembers[j] > 0){
					Node<Entity*>* tmpEntity = ListaPueblos[j]->getIndividuals()->getHead();
					int AtaquePoblacion = 0;
					for(int k = 0; k < ListaPueblos[j]->getIndividuals()->getLength(); k++){
						AtaquePoblacion+= tmpEntity->getData()->getGenome()->getAttack();
						tmpEntity = tmpEntity->getNext();
					}
					cout<<endl;
					cout<<"ANTES DEL ATAQUE: "<<Dioses[i]->getName() <<" "<< Dioses[i]->getLife()<<endl;

					Dioses[i]->receiveAttack(AtaquePoblacion);

					cout<<"DESPUES DEL ATAQUE: "<<Dioses[i]->getName() <<" "<< Dioses[i]->getLife()<<endl;

					_GodsWriter->updateGodsLife("true",Dioses[0]->getLife(),
												 Dioses[1]->getLife(),
												 Dioses[2]->getLife(),
												 Dioses[3]->getLife(),1);

					//int Poblacion = ListaPueblos[i]->getIndividuals()->getLength();
					//int AtaqueDios = _random->getRandomNumber(Poblacion/4);

					int AtaqueDios;
					if(PopMembers[j] <= 20){
						AtaqueDios = PopMembers[j];
					}
					else{
						AtaqueDios = _random->getRandomNumber(PopMembers[j]/4);
					}

					//cout<<"PreATAQUE DIOS "<< Poblacion << endl;
					ListaPueblos[j]->receiveAttack(AtaqueDios);
					//cout<<"PostATAQUE DIOS "<< Poblacion << endl;

					cout<<"Ataque del dios: "<< AtaqueDios <<endl;

					string currentGeneration = lexical_cast<string>(MaxGenerations);
					int PoblacionRestante = PopMembers[j] - AtaqueDios;
					if(PoblacionRestante <= 0) PoblacionRestante = 1;

					PopMembers[j] = PoblacionRestante;
					if(j == 0){
						string quantity = lexical_cast<string>(PoblacionRestante);
						string message = "Dwarves:"+currentGeneration+":"+ quantity + ":0:0:#";
						_DwarvesWriter->updateVillageInfo(message,"Dwarves");
						_finalDwarvesPopulation = PoblacionRestante;
					}
					if(j == 1){
						string quantity = lexical_cast<string>(PoblacionRestante);
						string message = "DarkElves:"+currentGeneration+":"+ quantity + ":0:0:#";
						_DarkElvesWriter->updateVillageInfo(message,"DarkElves");
						_finalDarkElvesPopulation = PoblacionRestante;
					}
					if(j == 2){
						string quantity = lexical_cast<string>(PoblacionRestante);
						string message = "Elves:"+currentGeneration+":"+ quantity + ":0:0:#";
						_ElvesWriter->updateVillageInfo(message,"Elves");
						_finalElvesPopulation = PoblacionRestante;
					}
					if(j == 3){
						string quantity = lexical_cast<string>(PoblacionRestante);
						string message = "Giants:"+currentGeneration+":"+ quantity + ":0:0:#";
						_GiantsWriter->updateVillageInfo(message,"Giants");
						_finalGiantsPopulation = PoblacionRestante;
					}
				}
				sleep(1);
			}
			DiosEnPeleaActual = DiosEnPeleaActual->getNext();
		}
	}

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
				//int A = getBestFighterOption(_Dwarves,_Elves);
				//int B = getBestFighterOption(_Dark_Elves,_Giants)+2;
				int A;
				int B;
				A = _random->getRandomNumber(3)+1;
				B = _random->getRandomNumber(3)+1;
				while(A==B){
					B = _random->getRandomNumber(3)+1;
				}
				cout<<"A: "<<A<<" B: "<<B<<endl;
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


				if(Constants::DEBUG == "true"){
					cout<<endl;
					cout<<"##########################"<<endl;
					cout<<"   A war is in progrss    "<<endl;
					cout<<"     "+lexical_cast<string>(A)+"  vs  "+lexical_cast<string>(B)+"     "<<endl;
					cout<<"##########################"<<endl;
					cout<<endl;
				}
				_FightIsAvailable = true;
				_DarkElvesWriter->startFight("true",A,B);
				pthread_mutex_unlock(&mutex);
		}
		if(_FightIsAvailable == true){
			if(_FightTimer >= 30){ //Cuando se acabe la batalla, se debe correr este código.
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
			_GodsWriter->startFight("false",0,0);
			if(Constants::DEBUG == "true"){
				cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
				cout << "La guerra contra los dioses ha comenzado"<<endl;
				cout << endl;
			}

			_ReproduceDwarves = false;
			_ReproduceElves = false;
			_ReproduceDarkElves = false;
			_ReproduceGiants = false;
			fightTheGods();

			cout<<"## La simulación ha finalizado ##"<< endl;

			cout << "Total de Inviduos: "<<Constants::IDCounter << endl;
			cout << "Cantidad de Dwarves: "<< _finalDwarvesPopulation << endl;
			cout << "Cantidad de Elves: " << _finalElvesPopulation<< endl;
			cout << "Cantidad de Giants: "<< _finalDarkElvesPopulation << endl;
			cout << "Cantidad de DarkElves: "<< _finalDarkElvesPopulation << endl;
			cout<<"################################"<< endl;
			Constants::resetVillagesLinageCounter();
			_RunningSimulation=false;
			cout<<" "<<endl;
		}
		sleep(1);
		_TimeWriter->updateTime(timeInSeconds);
		timeInSeconds++;


	}
	for(int i = 10; i > 0; i--){
		cout<<"Ending simulation in "<<i<<"..."<<endl;
		sleep(1);
	}
	resetJSONs(); //Se formatean los valores de los archivos JSON
	exit(0);
	pthread_exit(NULL);
}
void World::resetJSONs(){
	_GodsWriter->startFight("false",0,0);
	_DwarvesWriter->updateVillageInfo("Dwarves:0:1:0:0:#","Dwarves");
	_DwarvesWriter->resetVillageArmy("Dwarves");
	_GiantsWriter->updateVillageInfo("Giants:0:1:0:0:#","Giants");
	_GiantsWriter->resetVillageArmy("Giants");
	_ElvesWriter->updateVillageInfo("Elves:0:1:0:0:#","Elves");
	_ElvesWriter->resetVillageArmy("Elves");
	_DarkElvesWriter->updateVillageInfo("DarkElves:0:1:0:0:#","DarkElves");
	_DarkElvesWriter->resetVillageArmy("DarkElves");
	_GodsWriter->updateGodsLife("false",0,0,0,0,1);
	_DarkElvesWriter->updateTime(0);

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
