/*
 * Random.cpp
 *
 *  Created on: May 1, 2015
 *      Author: abrahamon
 */

#include "Random.h"

Random::Random() {

	if(Constants::HARDWARE_CONFIG=="true"){
		PORT = "/dev/ttyACM0";
		ardu.Open(PORT);
		ardu.SetBaudRate(SerialStreamBuf::BAUD_9600);
		ardu.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
	}
	else{
		return;
	}
}

Random::~Random() {}

int Random::getRandomNumber(int pMax){

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

