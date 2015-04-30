/*
 * Constants.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: fabian
 */

#include "Constants.h"
#include "XMLReader.h"

Constants* Constants::_Constants = 0;
float Constants::PROBABILIDAD_DE_MUTACION = 0;
int Constants::CANTIDAD_DE_GENES = 0;
int Constants::MAX_POBLACION_INICIAL = 0;

Constants* Constants::getInstance(){
	if(_Constants == 0){
		_Constants = new Constants();
	}
	return _Constants;
}

Constants::Constants(){
	//XML Reader
	srand(time(0));
	XMLReader* reader = new XMLReader();
	reader->loadXMLFile("src/configs.xml");

	//General Constants
	PROBABILIDAD_DE_MUTACION = atof(reader->getParameter("PROBABILIDAD"))/100;
	CANTIDAD_DE_GENES =  atof(reader->getParameter("CANTIDAD_GENES"));
	MAX_POBLACION_INICIAL = atoi(reader->getParameter("MAX_POBLACION_INICIAL"));
}
