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
//#include "../src/com.LDMM.DataAccess/XMLReader.h"
#include <string>
using namespace std;
#include <stdlib.h>

class Constants{
public:
	static Constants* _Constants;
	static float PROBABILIDAD_DE_MUTACION;

	Constants* getInstance();

private:
	Constants();
};

#endif /* SRC_CONSTANTS_H_ */
