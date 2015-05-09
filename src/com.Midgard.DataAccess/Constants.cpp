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
string Constants::HARDWARE_CONFIG;
string Constants::DEBUG;
float Constants::REPRODUCTION_PER_GENERATION = 0;
int Constants::NUMBER_CHILDS_PER_PARENTS =0;
string Constants::HUMANS;
string Constants::DARK_ELVES;
string Constants::DWARVES;
string Constants::ELVES;
string Constants::GIANTS;

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
	CANTIDAD_DE_GENES =  atoi(reader->getParameter("CANTIDAD_GENES"));
	MAX_POBLACION_INICIAL = atoi(reader->getParameter("MAX_POBLACION_INICIAL"));
	HARDWARE_CONFIG = reader->getParameter("HARDWARE_CONFIG");
	DEBUG = reader->getParameter("DEBUG");
	NUMBER_CHILDS_PER_PARENTS = atoi(reader->getParameter("NUMBER_CHILDS_PER_PARENTS"));
	REPRODUCTION_PER_GENERATION = atof(reader->getParameter("REPRODUCTION_PER_GENERATION"));
	HUMANS = reader->getParameter("HUMANS");
	DARK_ELVES = reader->getParameter("DARK_ELVES");
	DWARVES = reader->getParameter("DWARVES");
	ELVES = reader->getParameter("ELVES");
	GIANTS = reader->getParameter("GIANTS");}
