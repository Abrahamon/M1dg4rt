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
	uint16_t pNewGen2 = 0;
	uint16_t pMask1 = 1;
	uint16_t pMask2 = 1;

	for(int i = 0; i<8;i++){
		pGenFather = pFatherGenome->getCromosome(i);
		pGenMother = pMotherGenome->getCromosome(i);
		pMask1 = pMask1<<8;
		pMask1 = pMask1 -1;
		pMask2 = ~pMask1;

		pNewGen1 = pGenFather & pMask1;
		pNewGen2 = pGenMother & pMask2;
		pNewGen1 = pNewGen1 | pNewGen2;
		newGenome->setCromosome(i,pNewGen1);
	//	cout<<"nuevo Gen Id "<<i<<". Es: "<<bitset<16>(pNewGen1).to_string()<<" equivale: "<<pNewGen1<<endl;
	}
	//La mutacion ocurre dentro de la reproduccion
	//newGenome = mutate(newGenome,probabilidad);
	Entity* newEntity = new Entity(true,pFather,pMother,0,newGenome,((pFather->getLife()+pMother->getLife())/2));
	return newEntity;
}

/**
 * Mutacion para un genoma entero
 * De manera iterativa y impredecible
 * modifica gen por gen del genoma
 */
Genome* Reproduction::mutate(Genome* pGenoma,LinkedList<int> *probabilimutacion){

	int a = _random->getRandomNumber(Constants::PROBABILIDAD_DE_MUTACION);

	Node<int> *tmp;
	int valordemut=probabilimutacion->getHead()->getData();
	tmp=probabilimutacion->getHead()->getNext();
	for(int i=0; i<8; i++){
		if(valordemut<=10){
			uint16_t cromosoma=pGenoma->getCromosome(i);
			largo* tamanoto = new largo();
			int cantidad=tamanoto->tamano(cromosoma);
			int posicion= rand()%cantidad;
			int elor=1<<posicion;
			int resultado=cromosoma|elor;
			if(cromosoma==resultado){
				int calculoand=pow(2,cantidad)-pow(2,posicion);
				resultado=cromosoma&calculoand;
			}
			pGenoma->setCromosome(i,resultado);
		}
		if(valordemut==1){
			uint16_t cromosoma=pGenoma->getCromosome(i);
		}
		valordemut=tmp->getData();
		tmp=tmp->getNext();
	}
	return pGenoma;
}
