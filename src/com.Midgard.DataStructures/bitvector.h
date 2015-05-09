/*
 * bitvector.h

 *
 *  Created on: May 01, 2015
 *      Author: Mauricio
 */
#ifndef COM_MIDGARD_DATASTRUCTURES_BITVECTOR_H_
#define COM_MIDGARD_DATASTRUCTURES_BITVECTOR_H_
#include <math.h>
#include "stdint.h"
#include <math.h>
#include <iostream>
#include "../com.Midgard.Genetic/largo.h"

using namespace std;
class bitvector{

private:

public:
	bitvector();
	uint16_t tomar(uint16_t numero,int posicion);
	uint16_t cambiar(uint16_t numero,int posicion,int valor);

};

#endif /* COM_MIDGARD_DATASTRUCTURES_BITVECTOR_H_ */
