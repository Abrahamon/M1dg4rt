/*
 * GPS.cpp
 *
 *  Created on: May 8, 2015
 *      Author: fabian
 */

#include "GPS.h"

GPS::GPS() {
	_map = new PyArray<char>(30,30);
	_closedList = new LinkedList<Cell*>();
	_pathList = new LinkedList<Cell*>();
}

GPS::~GPS() {}


bool GPS::getWalkableCells(uint8_t pX, uint8_t pY,uint8_t endX, uint8_t endY,bool retry){

	int pG = 0;
	bool finished = false;

	Cell* currentCell = new Cell();
	currentCell->setData(pX,pY,NULL,0);

	if(retry == false)
		_closedList->insertTail(currentCell);
	else
		_pathList->insertTail(currentCell);

	while(!finished){
		LinkedList<Cell*>* _openList = new LinkedList<Cell*>();
		if(pX == endX && pY == endY){

			finished = true;
			return true;
		}
		else{
			Cell* topCell = new Cell();
			Cell* bottomCell = new Cell();
			Cell* leftCell = new Cell();
			Cell* rightCell = new Cell();

			char topCoords = _map->getDataID(pX,pY-1);	//Obtener coord de arriba
			char bottomCoords = _map->getDataID(pX,pY+1);//Obtener coord de abajo
			char leftCoords = _map->getDataID(pX-1,pY);//Obtener coord de la izquierda
			char rightCoords = _map->getDataID(pX+1,pY);//Obtener coord de la derecha

			if(topCoords == 49){
				int pHeuristic = getH(pX,pY-1,endX,endY);
				topCell->setData(pX,pY-1,currentCell,pG+pHeuristic);
				if(isOnClosedList(topCell) == false){
					_openList->insertTail(topCell);
				}

			}
			if(bottomCoords == 49){
				int pHeuristic = getH(pX,pY+1,endX,endY);
				bottomCell->setData(pX,pY+1,currentCell,pG+pHeuristic);
				if(isOnClosedList(bottomCell) == false){
					_openList->insertTail(bottomCell);
				}
			}
			if(leftCoords == 49){
				int pHeuristic = getH(pX-1,pY,endX,endY);
				leftCell->setData(pX-1,pY,currentCell,pG+pHeuristic);
				if(isOnClosedList(leftCell) == false){
					_openList->insertTail(leftCell);
				}
			}
			if(rightCoords == 49){
				int pHeuristic = getH(pX+1,pY,endX,endY);
				rightCell->setData(pX+1,pY,currentCell,pG+pHeuristic);
				if(isOnClosedList(rightCell) == false){
					_openList->insertTail(rightCell);
				}
			}
			if(_openList->getLength() == 0){
				//_closedList->vaciar();
				break;
			}

			Cell* tmpCell = getBestCell(_openList,retry);
			Cell* newCell = new Cell();

			newCell->setData(tmpCell->getX(),tmpCell->getY(),tmpCell->getPrevious(),tmpCell->getF());


			if(retry == false)
				_closedList->insertTail(newCell);
			else
				_pathList->insertTail(newCell);


			//currentCell = newCell;

			pG++;	//Aumentar el G actual en 1, pues se avanzó una celda.
			pX = newCell->getX();
			pY = newCell->getY();
			//sleep(2);
		}
	}

	return false;

}

int GPS::getH(uint8_t pX, uint8_t pY,uint8_t endX, uint8_t endY){
	int H = 0;
	H+= abs((endX-pX));
	H+= abs((endY-pY));
	return abs(H);
}

Cell* GPS::getBestCell(LinkedList<Cell*>* openList,bool retry){
	Cell* currentCell = openList->getHead()->getData();
	Node<Cell*>* currentNode = openList->getHead();
	if(openList->getLength() == 1){
		return currentNode->getData();
	}
	else{
		for(int i = 0; i < openList->getLength(); i++){
			currentCell = getBestBetween(currentCell,currentNode->getNext()->getData(),retry);
			currentNode = currentNode->getNext();
		}
	}

	return currentCell;
}

Cell* GPS::getBestBetween(Cell* A, Cell* B,bool retry){
	if(A->getF() < B->getF()){ //Si A es menor que B, retorna A
		return A;
	}
	else if(B->getF() < A->getF()){ //Si B es menor que A, retorna B
		return B;
	}
	else{//Si son iguales, retorna A
		return A;
	}
}

void GPS::printBestPath(){
	if(_pathList->getHead() != 0){
		Node<Cell*>* tmp = _pathList->getHead();
		for(int i = 0; i < _pathList->getLength(); i++){
			std::cout << tmp->getData()->getX() << " " << tmp->getData()->getY() << std::endl;
			tmp=tmp->getNext();
		}
	}
	else{
		Node<Cell*>* tmp = _closedList->getHead();
		for(int i = 0; i < _closedList->getLength(); i++){
			std::cout << tmp->getData()->getX() << " " << tmp->getData()->getY() << std::endl;
			tmp=tmp->getNext();
		}
	}

}

bool GPS::isOnClosedList(Cell* pCell){
	Node<Cell*>* tmp = _closedList->getHead();
	for(int i = 0; i < _closedList->getLength(); i++){
		if((tmp->getData()->getX() == pCell->getX()) && (tmp->getData()->getY() == pCell->getY())){
			return true;
		}
		tmp = tmp->getNext();
	}
	return false;
}

void GPS::loadMap(){
	ifstream MapFile ("src/com.Midgard.Resources/MapEditor/MapFiles/prueba1.map");

	int mat = 0;
		if (MapFile.is_open()){
			for(int i = 0; i < 30; i ++){
				for(int j = 0; j < 30; j++){
					if(mat == 0){
						char x = MapFile.get();
						_map->setDataID(i,j,(char)x);
						if(j == 29){
							MapFile.get();
						}

					}
					else{
						char x = MapFile.get();
						_map->setDataID(i,j,(char)x);
						if(j==29){
							MapFile.get();
						}
					}
				}
				mat++;
			}
			MapFile.close();
			//_map->printMatrix();
		}

		else {
			cout << "**World/LoadMatrix ** - Unable to open file";
		}
}
