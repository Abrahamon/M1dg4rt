/*
 * Random.cpp
 *
 *  Created on: May 1, 2015
 *      Author: abrahamon
 */

#include "Random.h"
Random* Random::_SlaveRandom = 0;
SerialStream Random::ardu;
Random::Random() {
	initConnection();
}

Random::~Random() {}

Random* Random::getInstance(){
	if(_SlaveRandom == 0){
		_SlaveRandom = new Random();

	}
	return _SlaveRandom;
}

void Random::initConnection(){
	ardu.Open("/dev/ttyACM0");
	ardu.SetBaudRate(SerialStreamBuf::BAUD_9600);
	ardu.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
}
int Random::getRandomNumber(int pMax){
	if(pMax == 0){
		return 0;
	}
	if(Constants::HARDWARE_CONFIG == "true"){
		int exp = log2(pMax)+1;
		int answer = get(exp);	//Para crear numeros en el arduino
		//int answer = getNumber(exp);			//Para crear bits en el arduino
		if(answer>pMax){
			return getRandomNumber(pMax);
		}
		else{
			return answer;
		}
	}else{
		return rand()%pMax;
	}
	return 0;
}
/*
 * Usleep cuando creamos bits en el arduino
 */
int Random::get(char pData){
	int RandomData;
    char buffer[1024];
    ardu << pData;
    ardu >> buffer;
	sscanf(buffer,"%d",&RandomData);
	//usleep(100000);
    return RandomData;
}


bool Random::getRandomBool(){
	int pAnswer = getRandomNumber(1000);
	if(pAnswer > 500){
		return false;
	}else{
		return true;
	}
}


int Random::getNumber(int maxType){
  int numArray[maxType];

  for(int i = 0; i < maxType ; i++){
	  int a = get('1');
	  numArray[i]=a;
  }
  int num = randomNumber(numArray,0,0,maxType);
  return num;
}

int Random::randomNumber(int numArray[],int ind,int resultado,int maxType){
  if(ind == maxType){
    return resultado;
  }
  else if(numArray[ind] == 1){
    resultado+= pow(2,ind);
    randomNumber(numArray,ind+=1,resultado,maxType);
  }
  else{
    randomNumber(numArray,ind+=1,resultado,maxType);

  }
}
