/*
 * Entity.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: fabian
 */

#include "Entity.h"

Entity::Entity() {
	_Gender = 0;
	_Father = 0;
	_Mother = 0;
	_Brother = 0;
	_Genome = 0;
	_Age = 0;
	_Name = "";
	_Experience = 0;
	_Life = 0;
	_Superstition = 0;
}

Entity::~Entity() {}
std::string Entity::getRandomName(){
	std::ifstream file("src/com.Midgard.EntitiesNames/names.txt");
	std::string str;
	std::string file_contents;
	//sleep(1);
	int random = rand() % 4966 + 1;
	for(int i = 0; i < random; i++){
	  std::getline(file, str);
	  //file_contents += str;
	  file_contents = str;
	  //file_contents.push_back('\n');
	}
	return file_contents;
}

//Entity's Getters
std::string Entity::getName(){ return _Name; }
int Entity::getAge(){ return _Life; }
int Entity::getExp(){ return _Experience; }
int Entity::getLife(){ return _Life; }
bool Entity::getGender(){ return _Gender; }
int Entity::getSuperstition(){ return _Superstition; }
Genome* Entity::getGenome(){ return _Genome;}
Entity* Entity::getFather(){ return _Father; }
Entity* Entity::getMother(){ return _Mother; }
Entity* Entity::getBrother(){ return _Brother; }

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
