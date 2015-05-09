/*
 * Reproduction.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: abrahamon
 */

#include "Reproduction.h"

Reproduction* Reproduction::_Reproduction = 0;

Reproduction::Reproduction() {
	_random = new Random();
}

Reproduction::~Reproduction() {
	// TODO Auto-generated destructor stub
}

Reproduction* Reproduction::getInstance(){
	if(_Reproduction == 0){
		_Reproduction = new Reproduction();
	}
	return _Reproduction;
}

/**
 * Reproduccion entre dos Entidades, la primera es el padre, la segunda es la madre
 * retorna el nuevo individuo, creado
 */
Entity* Reproduction::reproducir(Entity* pFather, Entity* pMother){
	/*
	 * Un error encontrado, se encuentra la siguiente cerificacion, ya que retorna 0 cuando son del mismo sexo,
	 * la funcion anterior nunca espera recibir un cero, siempre espera una entity bien creada.
	 * if(pFather->getGender() == pMother->getGender()){
		if(Constants::DEBUG == "true")
			cout<<"Reproduction.reproducir() 	No se reproducen individuos del mismo sexo"<<endl;
		return 0;
	}*/
	Genome* pFatherGenome = pFather->getGenome();
	Genome* pMotherGenome = pMother->getGenome();
	Genome* newGenome = new Genome(0,0,0,0,0,0,0,0);
	uint16_t pGenFather = 0;
	uint16_t pGenMother = 0;
	uint16_t pNewGen1 = 0;
	uint16_t temporal=0;
	bitvector* usobitv =new bitvector();
	int n=1;
	int size=4;

	for(int i = 0; i<8;i++){
		pGenFather = pFatherGenome->getCromosome(i);
		pGenMother = pMotherGenome->getCromosome(i);
		for(int l=0;l<=size;l++){
			if ((l%2)!=0){
				temporal=usobitv->tomar(pGenMother,n);
				pNewGen1=usobitv->cambiar(pNewGen1,n,temporal);
				temporal=usobitv->tomar(pGenMother,n+1);
				pNewGen1=usobitv->cambiar(pNewGen1,n+1,temporal);
				n=n+2;
			}
			if ((l%2)==0){
				temporal=usobitv->tomar(pGenFather,n);
				pNewGen1=usobitv->cambiar(pNewGen1,n,temporal);
				temporal=usobitv->tomar(pGenFather,n+1);
				pNewGen1=usobitv->cambiar(pNewGen1,n+1,temporal);
				n=n+2;
			}
		}
		newGenome->setCromosome(i,pNewGen1);
	//	cout<<"nuevo Gen Id "<<i<<". Es: "<<bitset<16>(pNewGen1).to_string()<<" equivale: "<<pNewGen1<<endl;
	}
	//La mutacion ocurre dentro de la reproduccion
	newGenome = mutate(newGenome);
	Entity* newEntity = new Entity(true,pFather,pMother,0,newGenome,((pFather->getLife()+pMother->getLife())/2));
	return newEntity;
}

/**
 * Mutacion para un genoma entero
 * De manera iterativa y impredecible
 * modifica gen por gen del genoma
 */
Genome* Reproduction::mutate(Genome* pGenoma){
	for(int i=0; i<8; i++){
		int valordemut = _random->getRandomNumber(Constants::PROBABILIDAD_DE_MUTACION);//porcentaje de mutacion y inversion
		//esta parte se encarga de hacer la mutacion
		if(valordemut<=100){
			uint16_t cromosoma=pGenoma->getCromosome(i);//cromosoma original
			largo* tamanoto = new largo();
			int cantidad=tamanoto->tamano(cromosoma);
			int posicion= _random->getRandomNumber(cantidad+2)+1;//posicion random donde se realiza mutacion
			bitvector* usobitv =new bitvector();
			uint16_t resultado=usobitv->cambiar(cromosoma,posicion,1);
			if(cromosoma==resultado){
				resultado=usobitv->cambiar(cromosoma,posicion,0);
			}
			pGenoma->setCromosome(i,resultado);
		}
		//esta parte se encarga de hacer la inversion
		if(valordemut==1){
			uint16_t cromosoma=pGenoma->getCromosome(i);
			uint16_t resultado2=cromosoma;
			int primerrango=_random->getRandomNumber(3)+1;//posicion inicial desde donde empieza la inversion
			int segundorango=_random->getRandomNumber(3)+5;//posicion final donde termina la inversion
			bitvector* usobitv =new bitvector();
			int posicion=segundorango;
			for(int i=primerrango;i<=segundorango;i++){//se encarga de ir cambiando los bits
				uint16_t primervalor= usobitv->tomar(cromosoma,i);
				resultado2=usobitv->cambiar(resultado2,posicion,primervalor);
				posicion=posicion-1;
			}
			pGenoma->setCromosome(i,resultado2);
		}

	}
	return pGenoma;
}
