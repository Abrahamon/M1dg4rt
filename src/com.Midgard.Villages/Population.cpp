/*
 * Pupolation.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "Population.h"

Population::Population() {
	this->_random = new Random();
	this->_individuos = new LinkedList<Entity*>();
	this->_Fitness = new Fitness();
}

Population::~Population() {}

void Population::generacionCero(){

}



