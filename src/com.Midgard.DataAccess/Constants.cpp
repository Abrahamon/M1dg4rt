/*
 * Constants.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: fabian
 */

#include "Constants.h"
#include "XMLReader.h"

Constants* Constants::_Constants = 0;
float Constants::PROBABILIDAD_DE_MUTACION;

Constants* Constants::getInstance(){
	if(_Constants == 0){
		_Constants = new Constants();
	}
	return _Constants;
}

Constants::Constants(){
	//XML Reader
	XMLReader* reader = new XMLReader();
	reader->loadXMLFile("src/configs.xml");

	//General Constants
	PROBABILIDAD_DE_MUTACION = atof(reader->getParameter("PROBABILIDAD"))/100;
}
