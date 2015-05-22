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
	_Age = 1;
	_Name = "";
	_Experience = 0;
	_Life = 0;
	_Superstition = 0;
	_CurrX = 0;
	_CurrY = 0;
	_ID = 0;
}

Entity::Entity(bool pGender, Entity* pFather, Entity* pMother,Entity* pBrother,
			   Genome* pGenome, int pLife){
	this->_Age = 1;
	this->_Name = "";
	this->_Experience = 0;
	this->_Superstition = 0;
	_CurrX = 0;
	_CurrY = 0;
	this->_Gender = pGender;
	this->_Brother = pBrother;
	this->_Father = pFather;
	this->_Mother = pMother;
	this->_Brother = pBrother;
	this->_Genome = pGenome;
	this->_Life = pLife;
	this->_ID = Constants::getIDCounter();
}

Entity::~Entity() {}
std::string Entity::getRandomName(){
	std::ifstream file("src/com.Midgard.Resources/names/humans.names");
	std::string str;
	std::string file_contents;
	//sleep(1);
	int random = rand() % 4945 + 1;
	for(int i = 0; i < random; i++){
	  std::getline(file, str);
	  //file_contents += str;
	  file_contents = str;
	  //file_contents.push_back('\n');
	}
	return file_contents;
}

//Entity's Setters
void Entity::setGender(bool pGender){
	this->_Gender = pGender;
}

//Entity's Getters
std::string Entity::getName(){ return _Name; }
int Entity::getAge(){ return _Age; }
int Entity::getExp(){ return _Experience; }
int Entity::getLife(){ return _Life; }
bool Entity::getGender(){ return _Gender; }
int Entity::getSuperstition(){ return _Superstition; }
Genome* Entity::getGenome(){ return _Genome;}
Entity* Entity::getFather(){ return _Father; }
Entity* Entity::getMother(){ return _Mother; }
Entity* Entity::getBrother(){ return _Brother; }
uint8_t Entity::getX(){ return _CurrX; }
uint8_t Entity::getY(){ return _CurrY; }
int Entity::getID(){return _ID;}

//Entity's Setters

void Entity::Birthday(){_Age += 1;}
void Entity::gainExperience(int pExp){ _Experience+=pExp; }
void Entity::gainSuperstition(int pSupr){ _Superstition+=pSupr; }
void Entity::gainLife(int pLife){ _Life+=pLife; }
void Entity::setX(uint8_t pX){ _CurrX = pX; }
void Entity::setY(uint8_t pY){ _CurrY = pY; }
void Entity::setID(int pID){ _ID = pID; }

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
