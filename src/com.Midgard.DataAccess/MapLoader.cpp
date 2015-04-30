/*
 * MapLoader.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: fabian
 */

#include "MapLoader.h"

MapLoader::MapLoader() {}

MapLoader::~MapLoader() {}

void MapLoader::loadMap(){
	//CurrentMap("src/com.Midgard.Resources/MapEditor/MapFiles/prueba1.map");
}

void MapLoader::readMapMatrix(){
	/*int* matrix[30][30] = World::getMatrix();
	int mat = 0;
	if (CurrentMap.is_open()){
		for(int i = 0; i < 30; i ++){
			for(int j = 0; j < 30; j++){
				if(mat == 0){
					char x = CurrentMap.get();
					matrix[i][j] = x;
					if(j == 29) CurrentMap.get();
				}
				else{
					char x = CurrentMap.get();
					matrix[i][j] = x;
					if(j==29) CurrentMap.get();
				}
			}
			mat++;
		}
		CurrentMap.close();
	}

	else std::cout << "Unable to open file";
	for(int i = 0; i < 30; i ++){
		for(int j = 0; j < 30; j++){
			std::cout << (char)matrix[i][j];
		}
		std::cout << std::endl;
	}*/
}


