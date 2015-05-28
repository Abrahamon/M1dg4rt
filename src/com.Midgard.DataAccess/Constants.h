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
#include <pthread.h>

using namespace std;

class Constants{
public:
	static Constants* _Constants;
	static int PROBABILIDAD_DE_MUTACION;
	static int CANTIDAD_MAX_GENERACIONES;
	static int CANTIDAD_DE_GENES;
	static int MAX_POBLACION_INICIAL;
	static string HARDWARE_CONFIG;
	static string DEBUG;
	static string HARD_DEBUG;
	static float REPRODUCTION_PER_GENERATION;
	static string DARK_ELVES;
	static string DWARVES;
	static string ELVES;
	static string GIANTS;
	static string JSONS_PATH;
	static pthread_mutex_t mutex;
	static int IDCounter;
	static int VillagesWhoFinishedItsLinage;
	static int GENERATION_SLEEP_uSeconds;
	static int FRECUENCY_REPORT_Gens;
	static int GODS_MIN_LIFE;
	static int GODS_MAX_LIFE;
	static float STANDARD_DESV;
	static float GODS_DEFENSE;

	Constants* getInstance();
	static int getIDCounter();
	static void VillageFinishedLinage();
	static int getVillagesWhoFinishedItsLinage();
	static void resetVillagesLinageCounter();

private:
	Constants();
};

#endif /* SRC_CONSTANTS_H_ */
