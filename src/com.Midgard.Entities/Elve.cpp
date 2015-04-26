/*
 * Elve.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: fabian
 */

#include "Elve.h"

Elve::Elve(bool pGender, Entity* pFather, Entity* pMother,Entity* pBrother,
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

}

Elve::~Elve() {
	// TODO Auto-generated destructor stub
}

