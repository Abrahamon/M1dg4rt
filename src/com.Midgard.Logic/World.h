/*
 * World.h
 *
 *  Created on: Apr 29, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_LOGIC_WORLD_H_
#define COM_MIDGARD_LOGIC_WORLD_H_


#include "../com.Midgard.DataAccess/Constants.h"
#include "../com.Midgard.Villages/DarkElves.h"
#include "../com.Midgard.Villages/Dwarves.h"
#include "../com.Midgard.Villages/Elves.h"
#include "../com.Midgard.Villages/Giants.h"
#include "../com.Midgard.DataStructures/PyArray.h"
#include "../com.Midgard.Entities/God.h"
#include <fstream>
#include "../com.Midgard.DataAccess/JsonWriter.h"
#include <boost/lexical_cast.hpp>

using namespace std;
using boost::lexical_cast;

class World {

private:
	PyArray<char>* _matrix; //Matriz para la lógica del movimiento
	static LinkedList<God*>* _GodsList;
	static bool _ReproduceDwarves;
	static bool _ReproduceDarkElves;
	static bool _ReproduceElves;
	static bool _ReproduceGiants;
	static bool _RunningSimulation;
	static bool _FightIsAvailable;
	static int _FightTimer;
	static Random* _random;
	static JsonWriter* _DwarvesWriter;
	static JsonWriter* _DarkElvesWriter;
	static JsonWriter* _ElvesWriter;
	static JsonWriter* _GiantsWriter;
	static JsonWriter* _TimeWriter;
	static JsonWriter* _GodsWriter;
	static int timeSleep;
	static int reportFrecuency;
	static int timeInSeconds;
	static int timeSinceLastWar;

	static bool fightTheGods();
	static int getBestFighterOption(Population* popA, Population* popB);
	static void resetJSONs();


public:
	World();

	virtual ~World();

	void onsetOfGoods();
	void start();
	bool loadMap(std::string pathToFile);
	static void* DoGeneration(void* pPop);
	static void* DwarvesGeneration(void* pPop);
	static void* DarkElvesGeneration(void* pPop);
	static void* ElvesGeneration(void* pPop);
	static void* GiantsGeneration(void* pPop);
	static void* consoleLog(std::string pPopulation,short pGeneration);
	static void* Fight();
	static void* TimeController(void* pPop);


	//static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	static pthread_mutex_t mutex;
	static Dwarves* _Dwarves;
	static Dark_Elves* _Dark_Elves;
	static Elves* _Elves;
	static Giants* _Giants;


};

#endif /* COM_MIDGARD_LOGIC_WORLD_H_ */
