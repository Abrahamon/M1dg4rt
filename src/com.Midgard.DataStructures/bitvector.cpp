/*
 * bitvector.cpp
 *
 *  Created on: May 01, 2015
 *      Author: Mauricio
 */
#include "bitvector.h"


bitvector::bitvector(){};

uint16_t bitvector::tomar(uint16_t numero,int posicion){
	uint16_t bit=0;
	int mascara=1;
	mascara=mascara<<(posicion-1);
	if ((numero|mascara)==numero){
		uint16_t bit=1;
		return bit;
	}
	return bit;
}

uint16_t bitvector::cambiar(uint16_t numero,int posicion,int valor){
	uint16_t resultado=0;
	if (valor==1){
		int mascara=1<<(posicion-1);
		resultado= numero|mascara;
	}
	if (valor==0){
		largo* tamanotot = new largo();
		int tamadenum=tamanotot->tamano(numero);
		int mascaraand=(pow(2,tamadenum)-1)-pow(2,posicion-1);
		resultado=numero&mascaraand;
	}
	return resultado;
}
