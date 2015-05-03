/*
 * MapLoader.h
 *
 *  Created on: Apr 29, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_DATAACCESS_MAPLOADER_H_
#define SRC_COM_MIDGARD_DATAACCESS_MAPLOADER_H_
#include "../com.Midgard.Logic/World.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

class MapLoader {
private:
	std::ifstream CurrentMap;
public:
	MapLoader();
	virtual ~MapLoader();
	void loadMap();
	void readMapMatrix();
};

#endif /* SRC_COM_MIDGARD_DATAACCESS_MAPLOADER_H_ */
