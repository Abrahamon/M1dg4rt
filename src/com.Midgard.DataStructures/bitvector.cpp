/*
 * bitvector.cpp
 *
 *  Created on: May 01, 2015
 *      Author: Mauricio
 */
#include "bitvector.h"

bitvector::bitvector(){};

uint16_t tomar(uint16_t numero,int posicion){
	uint16_t bit=0;
	int mascara=1;
	mascara=mascara<<(posicion-1);
	if ((numero|mascara)==numero){
		uint16_t bit=1;
		return bit;
	}
	return bit;
}
