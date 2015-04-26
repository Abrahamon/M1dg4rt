/*
 * Fitness.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "Fitness.h"

Fitness* Fitness::_Fitness =0;

Fitness::Fitness(){

}

Fitness::~Fitness(){}

Fitness* Fitness::getInstance(){
	if(_Fitness == 0){
		_Fitness = new Fitness();
	}
	return _Fitness;
}
