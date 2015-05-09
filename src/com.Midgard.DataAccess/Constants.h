/*
 * Constants.h
 *
 *  Created on: Mar 17, 2015
 *      Author: fabian
 */

/*
 * Constants.h
 *
 *  Created on: Mar 17, 2015
 *      Author: fabian
 */

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Constants{
public:
	static Constants* _Constants;
	static int PROBABILIDAD_DE_MUTACION;
	static int CANTIDAD_DE_GENES;
	static int MAX_POBLACION_INICIAL;
	static string HARDWARE_CONFIG;
	static string DEBUG;
	static int NUMBER_CHILDS_PER_PARENTS;
	static float REPRODUCTION_PER_GENERATION;
	static string HUMANS;
	static string DARK_ELVES;
	static string DWARVES;
	static string ELVES;
	static string GIANTS;

	Constants* getInstance();

private:
	Constants();
};

#endif /* SRC_CONSTANTS_H_ */
