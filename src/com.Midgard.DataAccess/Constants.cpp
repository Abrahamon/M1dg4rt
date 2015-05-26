/*
 /*
 * Constants.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: fabian
 */

#include "Constants.h"
#include "XMLReader.h"


Constants* Constants::_Constants = 0;
int Constants::PROBABILIDAD_DE_MUTACION = 0;
int Constants::CANTIDAD_MAX_GENERACIONES = 0;
int Constants::CANTIDAD_DE_GENES = 0;
int Constants::MAX_POBLACION_INICIAL = 0;
int Constants::FIGHT_FRECUENCY = 0;
int Constants::GENERATION_SLEEP_uSeconds = 0;
string Constants::HARDWARE_CONFIG;
string Constants::DEBUG;
string Constants::HARD_DEBUG;
float Constants::REPRODUCTION_PER_GENERATION = 0;
float Constants::GODS_DEFENSE;
int Constants::NUMBER_CHILDS_PER_PARENTS =0;
string Constants::HUMANS;
string Constants::DARK_ELVES;
string Constants::DWARVES;
string Constants::ELVES;
string Constants::GIANTS;
string Constants::JSONS_PATH;
int Constants::CANTIDAD_DE_DIOSES =0;
int Constants::IDCounter = 0;
int Constants::VillagesWhoFinishedItsLinage=0;
int Constants::FRECUENCY_REPORT_Gens;
int Constants::GODS_MAX_LIFE;
int Constants::GODS_MIN_LIFE;
pthread_mutex_t Constants::mutex = PTHREAD_MUTEX_INITIALIZER;

Constants* Constants::getInstance(){
	if(_Constants == 0){
		_Constants = new Constants();
	}
	return _Constants;
}

Constants::Constants(){
	//XML Reader
	srand(time(0));
	XMLReader* reader = new XMLReader();
	reader->loadXMLFile("src/configs.xml");

	//General Constants
	PROBABILIDAD_DE_MUTACION = atoi(reader->getParameter("PROBABILIDAD_DE_MUTAR"));
	CANTIDAD_MAX_GENERACIONES= atoi(reader->getParameter("CANTIDAD_MAX_GENERACIONES"));
	CANTIDAD_DE_GENES =  atoi(reader->getParameter("CANTIDAD_GENES"));
	MAX_POBLACION_INICIAL = atoi(reader->getParameter("MAX_POBLACION_INICIAL"));
	GENERATION_SLEEP_uSeconds = atoi(reader->getParameter("GENERATION_SLEEP_uSeconds"));
	FIGHT_FRECUENCY = atoi(reader->getParameter("FIGHT_FRECUENCY"));
	HARDWARE_CONFIG = reader->getParameter("HARDWARE_CONFIG");
	DEBUG = reader->getParameter("DEBUG");
	HARD_DEBUG = reader->getParameter("HARD_DEBUG");
	NUMBER_CHILDS_PER_PARENTS = atoi(reader->getParameter("NUMBER_CHILDS_PER_PARENTS"));
	REPRODUCTION_PER_GENERATION = atof(reader->getParameter("REPRODUCTION_PER_GENERATION"));
	CANTIDAD_DE_DIOSES = atoi(reader->getParameter("CANTIDAD_DE_DIOSES"));
	HUMANS = reader->getParameter("HUMANS");
	DARK_ELVES = reader->getParameter("DARK_ELVES");
	DWARVES = reader->getParameter("DWARVES");
	ELVES = reader->getParameter("ELVES");
	GIANTS = reader->getParameter("GIANTS");
	JSONS_PATH = reader->getParameter("JSONS_PATH");
	IDCounter = 0;
	VillagesWhoFinishedItsLinage = 0;
	FRECUENCY_REPORT_Gens = atoi(reader->getParameter("FRECUENCY_REPORT_SECONDS"));
	GODS_MAX_LIFE = atoi(reader->getParameter("GODS_MAX_LIFE"));
	GODS_MIN_LIFE = atoi(reader->getParameter("GODS_MIN_LIFE"));
	GODS_DEFENSE = atof(reader->getParameter("GODS_DEFENSE"));
}

int Constants::getIDCounter(){
	pthread_mutex_lock(&mutex);
	IDCounter++;
	pthread_mutex_unlock(&mutex);
	return IDCounter;
}

void Constants::VillageFinishedLinage(){
	pthread_mutex_lock(&mutex);
	VillagesWhoFinishedItsLinage++;
	pthread_mutex_unlock(&mutex);
}

int Constants::getVillagesWhoFinishedItsLinage(){
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
	return VillagesWhoFinishedItsLinage;
}

void Constants::resetVillagesLinageCounter(){
	VillagesWhoFinishedItsLinage = 0;
}
