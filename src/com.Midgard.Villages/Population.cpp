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
//	cout<<"maximo :"<<_Fitness->getSumOfAll()*Constants::CANTIDAD_DE_GENES<<" .  Random : "<<randomObtained<<endl;

	int cantidadElementos = this->_individuos->getLength();
	Node<Entity*>* tmpNode = this->_individuos->getHead();


	for(int i = 0; i<cantidadElementos; i++){
//		cout<<"es la suma de todos : "<<_Fitness->getSumOfAll()<<endl;
//		cout<<"fitnes de :"<<i<<" es de: "<<_Fitness->caculateFitness(tmpNode->getData())<<endl;
//		cout<<"fitnes de :"<<i<<" es de: "<<_Fitness->caculateFitness(tmpNode->getNext()->getData())<<endl;
//		cout<<"fitnes de :"<<i<<" es de: "<<_Fitness->caculateFitness(tmpNode->getNext()->getNext()->getData())<<endl;
		//cout<<"random obtained: "<<randomObtained<<endl;
	//	cout<<"multiplicado : "<<_Fitness->caculateFitness(tmpNode->getData()) *(_Fitness->getSumOfAll())<<endl;
	//	cout<<"multiplicado : "<<_Fitness->caculateFitness(tmpNode->getNext()->getData()) *(_Fitness->getSumOfAll())<<endl;

		if(  (_Fitness->caculateFitness(tmpNode->getData()) *_Fitness->getSumOfAll()) > randomObtained ){
			//cout<<"seleccione al random mas apto, con ataque = "<<tmpNode->getData()->getGenome()->getAttack()<<endl;
			break;
		}
		randomObtained = randomObtained - (_Fitness->caculateFitness(tmpNode->getData())*_Fitness->getSumOfAll());
		tmpNode = tmpNode->getNext();
	}
	return tmpNode->getData();
}

Entity* Population::randomSelectTheFittestFather(){
	Entity* pResp = this->randomSelectTheFittest();
	if(pResp->getGender() == true){
		return pResp;
	}else{
		pResp->setGender(true);
		return pResp;
	}
}

Entity* Population::randomSelectTheFittestMother(){
	Entity* pResp = this->randomSelectTheFittest();
	if(pResp->getGender() == false){
		return pResp;
	}else{
		pResp->setGender(false);
		return pResp;
	}
}

void Population::DoGeneration(){

	int newBorns = _random->getRandomNumber(1+(Constants::REPRODUCTION_PER_GENERATION*_individuos->getLength()*0.5));
	for(int i=0; i < newBorns;i++){
		//La seleccion natural ocurre en las dos siguiente lineas.
		Entity* NewFather = randomSelectTheFittestFather();
		Entity* NewMother = randomSelectTheFittestMother();

		Entity* NewSon = Reproduction::getInstance()->reproducir(NewFather, NewMother);
		_individuos->insertTail(NewSon);
	}
	EverybodyBirthday();
	DEATH();
	_Fitness->setBase(_individuos);	//de nuevo fitness
}

void Population::EverybodyBirthday(){
	Node<Entity*>* tmp = _individuos->getHead();
	for(int i = 0 ; i < (_individuos->getLength()); i++){
		tmp->getData()->Birthday();
		tmp = tmp->getNext();
	}
}

void Population::DEATH(){
	Node<Entity*>* tmp = _individuos->getHead();
	int edad;
	for(int i =0; i<_individuos->getLength();i++){
		edad = tmp->getData()->getAge();
		if(edad <10){
			//se salva
		}
		else if(edad <15){
			if(_random->getRandomNumber(100)>30){
				cout<<"mate a alguien \n";
				_individuos->deleteData(tmp->getData());
				//30% probabilidades de morir entre 50 y 70
			}
		}
		else if(edad<25){
			if(_random->getRandomNumber(100)>50){
				cout<<"mate a alguien \n";
				//50% probabilidades de morir entre 50 y 70
				_individuos->deleteData(tmp->getData());
			}
		}
		else{
			_individuos->deleteData(tmp->getData());
			cout<<"mate a alguien \n";
			//100% probabilidades de morir, aqui si muere el cabron
		}
	}
	return;
}

float Population::calculateFitnessTo(Entity* pEntity){
	return _Fitness->caculateFitness(pEntity);
}

LinkedList<Entity*>* Population::getIndividuals(){ return _individuos; }


