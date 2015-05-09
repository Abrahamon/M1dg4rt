/*
 * bitvector.cpp
 *
 *  Created on: May 01, 2015
 *      Author: Mauricio
 */
#include "bitvector.h"


bitvector::bitvector(){};

//metodo que se encarga de obtener un bit de una posicion especifica
uint16_t bitvector::tomar(uint16_t numero,int posicion){
	uint16_t bit=0;
	int mascara=1;
	mascara=mascara<<(posicion-1); //mascara para aplicar el or
	if ((numero|mascara)==numero){ //si el numero no cambia con el or con la mascara es que en esa posicion habia un uno
		uint16_t bit=1;
		return bit;
	}
	return bit; //como el numero cambio es que habia un 0 en la posicion
}

//metodo encargado de poner un valor a un bit en una posicion especifica del numero
uint16_t bitvector::cambiar(uint16_t numero,int posicion,int valor){
	uint16_t resultado=0;
	if (valor==1){
		int mascara=1<<(posicion-1);// se crea una mascara de puros 0s con un 1 en la posicion que se quiere cambiar
		resultado= numero|mascara;
	}
	if (valor==0){
		largo* tamanotot = new largo();
		int tamadenum=tamanotot->tamano(numero);
		int mascaraand=(pow(2,tamadenum)-1)-pow(2,posicion-1);// formula que da una mascar de 1s con un 0 en la posicion que se quiere cambiar
		resultado=numero&mascaraand;
	}
	return resultado;
}
