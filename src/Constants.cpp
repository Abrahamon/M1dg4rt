/*
 * Constants.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: abrahamon
 */

#include "Constants.h"

Constants* Constants::_Constants = 0;
int Constants::SIZE_GENERACION_0 =0;

Constants::Constants() {
	this->SIZE_GENERACION_0 = 6;

}

Constants* Constants::getInstance(){
	if(this->_Constants== 0){
		_Constants = new Constants();
	}
	return _Constants;
}

