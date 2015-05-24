/*
 * God.cpp
 *
 *  Created on: May 24, 2015
 *      Author: fabian
 */

#include "God.h"

God::God(std::string pName) {
	_Name = pName;
	_isAlive = true;
	_random = new Random();
	_Life = Constants::GODS_MIN_LIFE + _random->getRandomNumber(Constants::GODS_MAX_LIFE-Constants::GODS_MIN_LIFE);
	_Defense = Constants::GODS_DEFENSE;
}

God::~God() {}

void God::receiveAttack(int pAttack){
	if(_Life > 0){
		pAttack = pAttack * _Defense;
		_Life-=pAttack;
		if(_Life <= 0){
			_Life = 0;
			_isAlive = false;
		}
	}

}

bool God::isGodAlive(){
	if(_isAlive == true){
		return true;
	}
	else{
		return false;
	}
}

int God::getLife(){ return _Life; }
