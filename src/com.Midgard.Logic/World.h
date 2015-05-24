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
#include "../com.Midgard.Entities/Good.h"
#include <pthread.h>
#include <fstream>
#include "../com.Midgard.DataAccess/JsonWriter.h"
#include <boost/lexical_cast.hpp>

using namespace std;
using boost::lexical_cast;

class World {

private:
	PyArray<char>* _matrix; //Matriz para la lógica del movimiento
	LinkedList<Good*>* _Goods;
<<<<<<< HEAD
	Elves* _Elves;

=======
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
	static int timeSleep;
	static int reportFrecuency;
	static int timeInSeconds;
	static int timeSinceLastWar;

	static int getBestFighterOption(Population* popA, Population* popB);
	static void resetJSONs();
>>>>>>> d8149d842bd1e0144583886dccec55c2af72bc5e


public:
	World();

<<<<<<< HEAD
	static void* DoGeneration(void* pPop);
	static void* metodo1(void* threadID);
	static void* metodo2(void* threadID);
	static void* metodo3(void* threadID);
	static void* metodo4(void* threadID);
=======
	virtual ~World();
>>>>>>> d8149d842bd1e0144583886dccec55c2af72bc5e

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
<<<<<<< HEAD
	static Giants* _Giants;
	static Dark_Elves* _Dark_Elves;
=======
	static Dark_Elves* _Dark_Elves;
	static Elves* _Elves;
	static Giants* _Giants;

>>>>>>> d8149d842bd1e0144583886dccec55c2af72bc5e

};

#endif /* COM_MIDGARD_LOGIC_WORLD_H_ */
