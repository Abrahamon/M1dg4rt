/*
 * Random.cpp
 *
 *  Created on: May 1, 2015
 *      Author: abrahamon
 */

#include "Random.h"
Random* Random::_SlaveRandom = 0;
Random::Random() {}

Random::~Random() {}

Random* Random::getInstance(){
	if(_SlaveRandom == 0){
		_SlaveRandom = new Random();

		initConnection();
	}
	return _SlaveRandom;
}

void Random::initConnection(){
	cout<<"11"<<endl;
	ardu.Open("/dev/ttyACM0");
	cout<<"22"<<endl;
	ardu.SetBaudRate(SerialStreamBuf::BAUD_9600);
	ardu.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
	cout<<"33"<<endl;
}
int Random::getRandomNumber(int pMax){
	if(pMax == 0){
		return 0;
	}
	if(Constants::HARDWARE_CONFIG == "true"){
		int exp = log2(pMax)+1;
		int answer = get(_Dictionary[exp]);
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

int Random::get(char pData){
    int RandomData;
    char buffer[1024];
    ardu << pData;
    ardu >> buffer;
    sscanf(buffer,"%d",&RandomData);
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

