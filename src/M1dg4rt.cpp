//============================================================================
// Name        : M1dg4rt.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../src/com.Midgard.DataStructures/bitvector.h"
#include "../src/com.Midgard.Genetic/largo.h"
#include "../src/com.Midgard.DataAccess/Constants.h"
#include "../src/com.Midgard.Entities/Dwarve.h"
#include "../src/com.Midgard.Entities/Entity.h"
#include "../src/com.Midgard.Entities/Human.h"
#include "../src/com.Midgard.Genetic/Genome.h"
#include "../src/com.Midgard.Villages/Dwarves.h"
#include "../src/com.Midgard.Villages/Population.h"
#include "../src/com.Midgard.Genetic/Reproduction.h"
#include "com.Midgard.Resources/RandomNumberGenerator/Random.h"
#include "../src/com.Midgard.Logic/World.h"

#include <math.h>
#include <SerialStream.h>
#include <fstream>

using namespace std;
//#define PORT "/dev/ttyACM0" //This is system-specific
//using namespace LibSerial;

SerialStream ardu;

/*
void open(){
    //The arduino must be setup to use the same baud rate/
    ardu.Open(PORT);
    ardu.SetBaudRate(SerialStreamBuf::BAUD_9600);
    ardu.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
}

int get(char out){
    int res;
    char str[1024];
    ardu << out;
    ardu >> str;
    sscanf(str,"%d",&res);
    return res;
}
*/

int main(){

	Constants* c;
	c->getInstance();
	Reproduction* r;
	r->getInstance();

//---------------------------------------------------------------Prueba de individuos-------------------------------
//	Genome* genomaPadre = new Genome(1000,2,3,4,5,6,7,8);
//	Genome* genomaMadre = new Genome(11,20,30,40,50,60,70,80);
//
//	Dwarve* enanoPadre = new Dwarve(true,0,0,0,genomaPadre,200);
//	Dwarve* enanaMadre = new Dwarve(false,0,0,0,genomaMadre,400);
//
//	Dwarve* enano3 = Reproduction::getInstance()->reproducir(enanoPadre,enanaMadre);








	//---------------------------------------------Prueba de los numeros random--------------------------------------
	/*int numeros = 2;
	int arrayResultados[numeros];
	for(int i =0; i<numeros;i++){
		arrayResultados[i]=0;
	}
	Random* random = new Random();
	ofstream myfile;
	int cantidadDePeticiones = 3;
	int resultado;

	for(int i =0; i<cantidadDePeticiones;i++){
		resultado =  random->getRandomNumber(numeros);
		arrayResultados[resultado]++;
	}

	myfile.open ("example.csv");
	myfile<< "2 numeros pedidos 3 veces \n";
	myfile<<"Numeros, Cantidad de Apariciones \n";
	for(int i =0; i<numeros;i++){
			myfile<<i<<","<<arrayResultados[i]<<"\n";
	}
		     myfile.close();
*/


	//-----------------------------------------------------Prueba de poblacion individual--------------------------------

//	Population* enanitosVerdes = new Dwarves();
//	enanitosVerdes->DoGeneration();


	//-----------------------------------------------------Prueba del mundo --------------------------------
	World* hyrule = new World();
	hyrule->loadMap("src/com.Midgard.Resources/MapEditor/MapFiles/prueba1.map");

	hyrule->start();

	cout<<"FIN \n";

//	Random* a = new Random();
//	cout<<a->getRandomNumber(32)<<endl;
//	cout<<a->getRandomNumber(32)<<endl;
//	cout<<a->getRandomNumber(32)<<endl;
//	cout<<a->getRandomNumber(32)<<endl;;
//	cout<<a->getRandomNumber(32)<<endl;;

//	cout<<"AQUI \n"<<endl;


	//-----------------------------------------------------Prueba de la lista --------------------------------
//
//	Entity* a1 = new Entity(true,0,0,0,0,0);
//	Entity* a2 = new Entity(false,0,0,0,0,0);
//	Entity* a3 = new Entity(false,0,0,0,0,0);
//	Entity* a4 = new Entity(false,0,0,0,0,0);
//	Entity* a5 = new Entity(false,0,0,0,0,0);
//
//	LinkedList<Entity*>* l = new LinkedList<Entity*>();
//	l->insertTail(a1);
//	l->insertTail(a2);
//	l->insertTail(a3);
//	l->insertTail(a4);
//	l->insertTail(a5);
//
//	l->deleteData(a1);
//
//	Node<Entity*>* tmp = l->getHead();
//	for(int i =0; i<l->getLength(); i++){
//		if(tmp->getData()==0){
//			cout<<"ERROR ERROR run "<<endl;
//		}else{
//			cout<<tmp->getData()->getGender()<<endl;
//		}
//		tmp=tmp->getNext();
//	}

	return 0;
}
