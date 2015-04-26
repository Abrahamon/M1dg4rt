/*
 * Genome.h
 *
 *  Created on: Apr 25, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_GENETIC_GENOME_H_
#define SRC_COM_MIDGARD_GENETIC_GENOME_H_

#include "../com.Midgard.DataStructures/linkedList.h"
#include "../com.Midgard.DataStructures/linkedNode.h"

#include "stdint.h"

class Genome : public LinkedList<uint16_t>{

private:

public:
	Genome(uint16_t Attack,uint16_t Speed, uint16_t Defense, uint16_t Intelligence,
			uint16_t Magic, uint16_t Energy, uint16_t Blot, uint16_t RunesPower);
	virtual ~Genome();
	void deleteData(short);

	uint16_t getCromosome(int pCromID);
	void setCromosome(int pCromID, uint16_t pData);
	uint16_t getAttack();
	uint16_t getSpeed();
	uint16_t getDefense();
	uint16_t getIntelligence();
	uint16_t getMagic();
	uint16_t getEnergy();
	uint16_t getBlot();
	uint16_t getRunesPower();
};

#endif /* SRC_COM_MIDGARD_GENETIC_GENOME_H_ */
