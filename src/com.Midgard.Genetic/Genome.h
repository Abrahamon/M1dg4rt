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

class Genome : public LinkedList<short>{

private:

public:
	Genome(short Attack,short Speed, short Defense, short Intelligence,
		   short Magic, short Energy,short Blot, short RunesPower);
	virtual ~Genome();
	void deleteData(short);

	short getCromosome(int pCromID);
	void setCromosome(int pCromID, short pData);
	short getAttack();
	short getSpeed();
	short getDefense();
	short getIntelligence();
	short getMagic();
	short getEnergy();
	short getBlot();
	short getRunesPower();
};

#endif /* SRC_COM_MIDGARD_GENETIC_GENOME_H_ */
