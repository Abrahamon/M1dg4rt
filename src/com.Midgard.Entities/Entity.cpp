/*
 * Entity.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: fabian
 */

#include "Entity.h"

Entity::Entity(bool pGender, Entity* pFather, Entity* pMother,Entity* pBrother,
		       Genome* pGenome, int pLife) {
	_Gender = pGender;
	_Father = pFather;
	_Mother = pMother;
	_Brother = pBrother;
	_Genome = pGenome;
	_Age = 0;
	_Experience = 0;
	_Life = pLife;
	_Superstition = pMother->getSuperstition();

}

Entity::~Entity() {}

//Entity's Getters
int Entity::getAge(){ return _Life; }
int Entity::getExp(){ return _Experience; }
int Entity::getLife(){ return _Life; }
bool Entity::getGender(){ return _Gender; }
int Entity::getSuperstition(){ return _Superstition; }
Genome* Entity::getGenome(){ return _Genome;}

//Entity's Setters

void Entity::Birthday(){ _Age++; }
void Entity::gainExperience(int pExp){ _Experience+=pExp; }
void Entity::gainSuperstition(int pSupr){ _Superstition+=pSupr; }
void Entity::gainLife(int pLife){ _Life+=pLife; }

//Fight Methods
void Entity::Attack(Entity* pDefender){
	//Aplicar random aquí
	int pDamage = _Genome->getAttack();
	pDefender->Defend(pDamage);
}
void Entity::Defend(int pDamage){
	//Aplicar random aquí
	_Life-=pDamage;
}
void Entity::Blot(){}
void Entity::invokeGod(){}
