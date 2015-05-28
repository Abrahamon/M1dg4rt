/*
 * Random.h
 *
 *  Created on: May 1, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_RESOURCES_RANDOM_H_
#define COM_MIDGARD_RESOURCES_RANDOM_H_

#include <SerialStream.h>
#include <math.h>
#include <random>
#include "../../com.Midgard.DataAccess/Constants.h"


using namespace std;
using namespace LibSerial;

class Random {

private:

	static SerialStream ardu;
	static Random* _SlaveRandom;
	static int get(char pData);
	char getChar(int pData);
//	char _Dictionary[18]={'0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?'};
	void initConnection();

public:
	Random();
	virtual ~Random();
	static int getRandomNumber(int pMax);
	bool getRandomBool();
	Random* getInstance();
	static int getNumber(int MaxType);
	static int randomNumber(int numArray[],int ind,int resultado,int maxType);
};

#endif /* COM_MIDGARD_RESOURCES_RANDOM_H_ */
