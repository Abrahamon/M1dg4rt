/*
 * Pupolation.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#include "Population.h"
pthread_mutex_t Population::mutex;
/**
 * Constructor
 */

Population::Population() {
	this->_Random = new Random();
	this->_superstition = 0;
	this->_Evolving = true;
	this->_reproduction = new Reproduction();
	this->_individuos = new LinkedList<Entity*>();
	this->_Fitness = new Fitness();
	this->CurrentGeneration=0;
}

/**
 * Destructor
 */
Population::~Population() {}

/**
 * Selecciona entre todos los individuos,
 * aletoriamente un invididuo, asigna probabilidades de exito
 * a los individuos con el fitness mas alto de la poblacion
 * Es un auxiliar
 */
Entity* Population::randomSelectTheFittest(){

	//obtener un numero aleatorio, desde 0 hasta la suma de todos los fitnes multiplicado por la cantidad de genes
	int randomObtained= _Random->getRandomNumber(_Fitness->getSumOfAll()*Constants::CANTIDAD_DE_GENES);
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

/**
 * Utiliza el metodo "randomSelectTheFittest"
 * pero retorna una entidad del genero deseado
 */
Entity* Population::randomSelectTheFittestFather(){
	Entity* pResp = this->randomSelectTheFittest();
	if(pResp->getGender() == true){
		return pResp;
	}else{
		pResp->setGender(true);
		return pResp;
	}
}

/**
 * Utiliza el metodo "randomSelectTheFittest"
 * pero retorna una entidad del genero deseado
 */
Entity* Population::randomSelectTheFittestMother(){
	Entity* pResp = this->randomSelectTheFittest();
	if(pResp->getGender() == false){
		return pResp;
	}else{
		pResp->setGender(false);
		return pResp;
	}
}

/**
 * Tiene la siguiente forma:
 * 1.Calcula aletoriamente un numero random que indica los nacimientos que se van a dar
 * 	en esta generacion, no es maximo a la mitdad de la poblacion, porque se requieren dos entities para reproducir
 * 2.selecciona aleatoriamente(con ventaja para los de fitness mas alto) a los padres del nuevo hijo, las veces que indique
 * 	el paso anterior
 * 3.Lo inserta en la poblacion
 * 4.Aumenta la edad de todos los individuos en 1.
 * 5.LLama a una verificacion de edad, donde los mayores a cierta edad tienen probabilidades cada vez mas altas de morir.
 */
void Population::DoGeneration(){
	//pthread_mutex_lock(&mutex);
	int newBorns = _Random->getRandomNumber(1+(Constants::REPRODUCTION_PER_GENERATION*_individuos->getLength()*0.5));

	for(int k=0; k < newBorns;k++){
		//La seleccion natural ocurre en las dos siguiente lineas.
		Entity* NewFather = randomSelectTheFittestFather();
		Entity* NewMother = randomSelectTheFittestMother();
		Entity* NewSon = _reproduction->reproducir(NewFather, NewMother);
		_individuos->insertTail(NewSon);
	}

	//cout << "GENERATION: " << CurrentGeneration <<"Population " << _individuos->getLength() <<endl;
	CurrentGeneration++;
	EverybodyBirthday();
	DEATH();

	//mejores(_individuos); //PRUEBA DE MEJORES INDIVIDUOS

	//_Fitness->setBase(_individuos);	//de nuevo fitness

	return;
}

/**
 * Aumenta la edad de todos en 1
 */
void Population::EverybodyBirthday(){
	Node<Entity*>* tmp = _individuos->getHead();
	for(int i = 0 ; i < (_individuos->getLength()); i++){
		tmp->getData()->Birthday();
		tmp = tmp->getNext();
	}
	return;
}

/**
 * Para todos los individuos mayores a una cierta edad comienza tirar dados para decidir si se mueren o continuan.
 * con forme se hacen viejos mas probabilidades tienen
 */
void Population::DEATH(){

	Node<Entity*>* tmp = _individuos->getHead();
	int edad;
	for(int j =0; j<_individuos->getLength();j++){
		if(tmp == 0)
			return;
		edad = tmp->getData()->getAge();
		tmp = tmp->getNext();
		if(edad < 5){
			//se salva
		}
		else if(edad <10){

			if(_Random->getRandomNumber(100)>30){
				_individuos->deleteData(tmp->getPrevious()->getData());
				//30% probabilidades de morir entre 50 y 70
			}
		}
		else if(edad < 15){

			if(_Random->getRandomNumber(100)>50){
				//5robabilidades de morir entre 50 y 70
				_individuos->deleteData(tmp->getPrevious()->getData());
			}
		}
		else{
			_individuos->deleteData(tmp->getPrevious()->getData());
			//100% probabilidades de morir, aqui si muere el cabron
		}
	}
	return;
}

/**
 * Metodo de prueba para poder calcular el fitness desde world
 * para cualquier individuo
 */
float Population::calculateFitnessTo(Entity* pEntity){
	return _Fitness->caculateFitness(pEntity);
}

/*
 * Retorna la lista de individuos
 */
LinkedList<Entity*>* Population::getIndividuals(){ return _individuos; }

/**
 * Llama al metodo "desviacionEstandart" si es mayor a una constante
 * decidimos que nuestro material genetico no esta cambiando
 * y detenemos la reproduccion
 */
bool Population::getEvolvingState(){
	float desviEst = desviacionEstandart(_individuos);
	cout<<"La desviacion estandart en el ataque es de: "<<desviEst<<endl;
	if( desviEst < 0.1 ){
		if(Constants::DEBUG == "true")
			cout<<"Population.getEvolvingState() 	La poblacion no cambia su material genetico"<<endl;
		_Evolving = false;
	}
	return this->_Evolving;
}

/**
 * Utiliza el mismo concepto de desviacion estandar utilizado
 * en probabilidad y estadistica, para el conjunto de genes de un cromosoma
 */
float Population::desviacionEstandart(LinkedList<Entity*>* pList){
	float ans;
	Node<Entity*>* tmp = pList->getHead();
	int attack = 0;
//	int speed = 0;
//	int defense = 0;
//	int intelligence = 0;
//	int magic =0;
//	int energy = 0;
//	int bloot = 0;
//	int runesPower = 0;

	for(int i =0; i< pList->getLength(); i++){
		attack += tmp->getData()->getGenome()->getAttack();
//		speed += tmp->getData()->getGenome()->getSpeed();
//		defense += tmp->getData()->getGenome()->getDefense();
//		intelligence += tmp->getData()->getGenome()->getIntelligence();
//		magic += tmp->getData()->getGenome()->getMagic();
//		energy += tmp->getData()->getGenome()->getEnergy();
//		bloot += tmp->getData()->getGenome()->getBlot();
//		runesPower += tmp->getData()->getGenome()->getRunesPower();
		tmp = tmp->getNext();
	}

	attack = attack/pList->getLength();
//	speed = speed/pList->getLength();
//	defense = defense/pList->getLength();
//	intelligence = intelligence/pList->getLength();
//	magic = magic/pList->getLength();
//	energy = energy/pList->getLength();
//	bloot = bloot/pList->getLength();

	tmp = pList->getHead();
	for(int i= 0; i<pList->getLength();i++){
		ans += exp2(attack-tmp->getData()->getGenome()->getAttack());
	}
	ans = sqrt(ans/pList->getLength());
	return ans;
}


short Population::getCurrentGeneration() { return CurrentGeneration; }
int Population::getCantidadDeIndividuos(){ return _individuos->getLength(); }
float Population::getBestFitness(){
	float best = 0;
	float current= 0;
	Node<Entity*>* tmp = _individuos->getHead();
	best = _Fitness->caculateFitness(tmp->getData());

	for(int i = 0; i < _individuos->getLength(); i++){
		current = _Fitness->caculateFitness(tmp->getData());

		if(current > best){
			best = current;
		}

		tmp = tmp->getNext();
	}

	return best;
}

float Population::getWorstFitness(){
	float worst = 0;
	float current= 0;
	Node<Entity*>* tmp = _individuos->getHead();
	worst = _Fitness->caculateFitness(tmp->getData());

	for(int i = 0; i < _individuos->getLength(); i++){
		current = _Fitness->caculateFitness(tmp->getData());

		if(current < worst){
			worst = current;
		}

		tmp = tmp->getNext();
	}

	return worst;
}

int Population::getBestAttribute(){
	int BestAttack = 0;
	int current= 0;

	Node<Entity*>* tmp = _individuos->getHead();
	BestAttack = tmp->getData()->getGenome()->getAttack();

	for(int i = 0; i < _individuos->getLength(); i++){
		current = tmp->getData()->getGenome()->getAttack();

		if(current > BestAttack){
			BestAttack = current;
		}

		tmp = tmp->getNext();
	}

	return BestAttack;

}


// Metodo encargardo de obtener los 20 mejores individuos de la poblacion

LinkedList<Entity*>* Population::getBestEntities(LinkedList<Entity*>* indList){
	LinkedList<Entity*>* bests=new LinkedList<Entity*>(); //Lista donde estaran los individuos
	Node <Entity*>* tmp= indList->getHead(); //Nodo temporal
	Node <Entity*>* mejorindividuo; //Nodo donde esta el mejor individuo
	float restriccion=2000; //Restriccion de que no se copie el mismo valor de fitness
	for (int i=0;i<=20*indList->getLength();i++){  //for para encontrar a 20 individuos
		float mejor =0;  //fitness mas alto
		float temporal =0;
		for (int l=0;l<=indList->getLength();l++){ // for encargado de encontrar un individuo con fitness alto
			temporal=_Fitness->caculateFitness(tmp->getData());
			//cout<<"posibles"<<temporal<<endl;
			if(temporal>mejor && temporal<restriccion){
				mejor=temporal;
				//cout<<"entro"<<mejor<<endl;
				mejorindividuo=tmp;
				tmp=tmp->getNext();
			}
			tmp=tmp->getNext();
		}
		restriccion=mejor;
		cout<<"final"<<restriccion<<endl;
		bests->insertTail(mejorindividuo->getData());
	}
	return bests;
}

LinkedList<Entity*>* Population::getArmy(){
	int randomIterator = _Random->getRandomNumber(_individuos->getLength());
	randomIterator-=20;
	LinkedList<Entity*>* PopulationArmy = new LinkedList<Entity*>();

	Node<Entity*>* tmp = _individuos->getHead();
	for(int i = 0; i < randomIterator; i++){
		tmp = tmp->getNext();
	}
	for(int j = 0; j < 20; j++){
		PopulationArmy->insertTail(tmp->getData());
		tmp = tmp->getNext();
	}
	return PopulationArmy;
}

void Population::receiveAttack(int pNumeroDeMuertes){

	Node<Entity*>* tmp = _individuos->getHead();
	for(int j =0; j<pNumeroDeMuertes;j++){
		if(tmp == 0)
			return;
		tmp = tmp->getNext();
		_individuos->deleteData(tmp->getPrevious()->getData());

	}
	return;
}




