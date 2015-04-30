/*
 * Dwarves.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "../com.Midgard.Villages/Dwarves.h"

Dwarves::Dwarves() {
	bool newGender = true;
	Genome* newGenome = new Genome(10,10,10,10,10,10,10,10);


	for(int i = 0; i < Constants::MAX_POBLACION_INICIAL; i++){


		Dwarve* newDwarve = new Dwarve(newGender,0,0,0,newGenome,0);
	}
}

Dwarves::~Dwarves() {

}

