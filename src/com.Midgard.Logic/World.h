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

class World {

private:
	PyArray<char>* _matrix; //Matriz para la lógica del movimiento
	LinkedList<Good*>* _Goods;
	Dark_Elves* _Dark_Elves;
	Elves* _Elves;
	Giants* _Giants;


public:
	World();
	virtual ~World();

	static void* DoGeneration(void* pPop);

	void onsetOfGoods();
	void start();
	bool loadMap(std::string pathToFile);

	static Dwarves* _Dwarves;
};

#endif /* COM_MIDGARD_LOGIC_WORLD_H_ */
