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
	int get(char pData);
	char getChar(int pData);
	static char _Dictionary[18];
	void initConnection();

public:
	Random();
	virtual ~Random();
	static int getRandomNumber(int pMax);
	bool getRandomBool();
	Random* getInstance();
};

#endif /* COM_MIDGARD_RESOURCES_RANDOM_H_ */
