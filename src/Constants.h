/*
 * Constants.h
 *
 *  Created on: Apr 24, 2015
 *      Author: Fabian
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

using namespace std;

class Constants {

public:
	static Constants* _Constants;

	static int SIZE_GENERACION_0;

	Constants* getInstance();

private:
	Constants();
};

#endif /* CONSTANTS_H_ */
