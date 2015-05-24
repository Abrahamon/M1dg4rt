/*
 * Dwarve.cpp
 *
 *  Created on: Apr 25, 2015
<<<<<<< HEAD
 *      Author: fabian
=======
 *      Author: abrahamon
>>>>>>> 83b1030698c0a32531eb61314e5e162eb862e297
 */

#include "Dwarve.h"

Dwarve::Dwarve(bool pGender, Entity* pFather, Entity* pMother,Entity* pBrother,
	       Genome* pGenome, int pLife) {
	_Gender = pGender;
	_Father = pFather;
	_Mother = pMother;
	_Brother = pBrother;
	_Genome = pGenome;
	_Age = 0;
	_Name = getRandomName();
	_Experience = 0;
	_Life = pLife;
	_Superstition = 0 ;//La supersticion debería heredarla de la madre/padre.
	_ID = Constants::getIDCounter();
}

Dwarve::~Dwarve() {
	// TODO Auto-generated destructor stub
}

