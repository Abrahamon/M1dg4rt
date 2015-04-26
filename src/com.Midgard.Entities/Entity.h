/*
 * Entity.h
 *
 *  Created on: Apr 25, 2015
 *      Author: fabian
 */

#ifndef COM_MIDGARD_ENTITIES_ENTITY_H_
#define COM_MIDGARD_ENTITIES_ENTITY_H_
#include "../com.Midgard.DataStructures/linkedList.h"
#include "../com.Midgard.Genetic/Genome.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

/**
 * Clase Entity, es el individuo base del cual heredan todos los
 * demás individuos de las correspondientes civilizaciones. Humanos,
 * gigantes, elfos y enanos.
 */
class Entity {



public:
	Entity();
	virtual ~Entity();
	std::string getRandomName();

	std::string _Name;
	int _Age;					//Entity's age
	int _Experience;			//Entity's experience
	int _Life;					//Entity's life
	bool _Gender; 				//True for men, false for women
	int _Superstition;
	Genome* _Genome; //Entity's genome, made out of 8 cromosomes.
	Entity* _Father;			//Entity's father
	Entity* _Mother;			//Entity's mother
	Entity* _Brother;			//Entity's brother

	//Entity's Getters
	std::string getName();
	int getAge();
	int getExp();
	int getLife();
	bool getGender();
	int getSuperstition();
	Genome* getGenome();
	Entity* getFather();
	Entity* getMother();
	Entity* getBrother();

	//Entity's Setters
	void Birthday();
	void gainExperience(int pExp);
	void gainSuperstition(int pSupr);
	void gainLife(int pLife);

	//Fight Methods
	void Attack(Entity* pDefender);
	void Defend(int pDamage);
	void Blot();
	void invokeGod();
};

#endif /* COM_MIDGARD_ENTITIES_ENTITY_H_ */
