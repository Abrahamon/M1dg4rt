/*
 * grafoGenealogico.h
 *
 *  Created on: Apr 22, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_DATASTRUCTURES_GRAFOGENEALOGICO_H_
#define COM_MIDGARD_DATASTRUCTURES_GRAFOGENEALOGICO_H_

#include "nodoGenealogico.h"

class grafoGenealogico {

private:
	nodoGenealogico* _rootGood;

public:
	grafoGenealogico();
	virtual ~grafoGenealogico();
	nodoGenealogico* getRootGood();
};

#endif /* COM_MIDGARD_DATASTRUCTURES_GRAFOGENEALOGICO_H_ */
