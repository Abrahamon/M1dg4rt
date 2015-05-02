/*
 * Pupolation.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "Population.h"

Population::Population() {
	this->_random = new Random();
	this->_individuos = new LinkedList<Entity*>();
	this->_Fitness = new Fitness();
}

Population::~Population() {}

Entity* Population::randomSelectTheFittest(){

	//obtener un numero aleatorio, desde 0 hasta la suma de todos los fitnes multiplicado por la cantidad de genes
	int randomObtained= _random->getRandomNumber(_Fitness->getSumOfAll()*Constants::CANTIDAD_DE_GENES);
	cout<<"maximo :"<<_Fitness->getSumOfAll()*Constants::CANTIDAD_DE_GENES<<" .  Random : "<<randomObtained<<endl;

	int cantidadElementos = this->_individuos->getLength();
	Node<Entity*>* tmpNode = this->_individuos->getHead();


	for(int i = 0; i<cantidadElementos; i++){
		cout<<_Fitness->getSumOfAll()<<endl;
		cout<<"fitnes de :"<<i<<" es de: "<<_Fitness->caculateFitness(tmpNode->getData())<<endl;
		cout<<"fitnes de :"<<i<<" es de: "<<_Fitness->caculateFitness(tmpNode->getNext()->getData())<<endl;
		cout<<"fitnes de :"<<i<<" es de: "<<_Fitness->caculateFitness(tmpNode->getNext()->getNext()->getData())<<endl;
		//cout<<"random obtained: "<<randomObtained<<endl;
		//cout<<"multiplicado : "<<_Fitness->caculateFitness(tmpNode->getData()) *(_Fitness->getSumOfAll())<<endl;

		if(  _Fitness->caculateFitness(tmpNode->getData()) * (_Fitness->getSumOfAll()) > randomObtained ){
			//cout<<"seleccione al random mas apto, con ataque = "<<tmpNode->getData()->getGenome()->getAttack()<<endl;
			break;
		}
		tmpNode = tmpNode->getNext();
	}
	return tmpNode->getData();
}

Entity* Population::randomSelectTheFittestFather(){
	Entity* pResp = this->randomSelectTheFittest();
	if(pResp->getGender() == true)
		return pResp;
	else
		return this->randomSelectTheFittestFather();
}

Entity* Population::randomSelectTheFittestMother(){
	Entity* pResp = this->randomSelectTheFittest();
	if(pResp->getGender() == false)
		return pResp;
	else
		return this->randomSelectTheFittestFather();

}



