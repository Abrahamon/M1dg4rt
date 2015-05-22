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
#include <fstream>
#include "../com.Midgard.DataAccess/JsonWriter.h"
#include <boost/lexical_cast.hpp>

using namespace std;

class World {

private:
	PyArray<char>* _matrix; //Matriz para la lógica del movimiento
	LinkedList<Good*>* _Goods;
	static bool _Reproduce;
	static Random* _random;
	Population* getFighter();


public:
	World();

	virtual ~World();

	void onsetOfGoods();
	void start();
	bool loadMap(std::string pathToFile);
	static JsonWriter *JWriter;
	static void* DoGeneration(void* pPop);

	static void* DwarvesGeneration(void* pPop);
	static void* DarkElvesGeneration(void* pPop);
	static void* ElvesGeneration(void* pPop);
	static void* GiantsGeneration(void* pPop);
	static void* consoleLog(std::string pPopulation,short pGeneration);
	static void* Fight();


	//static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	static pthread_mutex_t mutex;
	static Dwarves* _Dwarves;
	static Dark_Elves* _Dark_Elves;
	static Elves* _Elves;
	static Giants* _Giants;
};

#endif /* COM_MIDGARD_LOGIC_WORLD_H_ */
