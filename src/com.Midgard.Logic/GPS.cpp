/*
 * GPS.cpp
 *
 *  Created on: May 8, 2015
 *      Author: fabian
 */

#include "GPS.h"

GPS::GPS(Entity* pOwner) {
	_Owner = pOwner;
	_map = new PyArray<char>(30,30);
	_closedList = new LinkedList<Cell*>();
	_openList = new LinkedList<Cell*>();
	_pathList = new LinkedList<Cell*>();
}

GPS::~GPS() {}

int GPS::getHeuristicInOpenListOf(int pX, int pY){
	Node<Cell*>* tmp = _openList->getHead();
	for(int i = 0; i< _openList->getLength(); i++){
		if( tmp->getData()->getX() == pX  &&  tmp->getData()->getY() == pY ){
			return tmp->getData()->getF();
		};
		tmp = tmp->getNext();
	}
	return 0;
}

Cell* GPS::getCellPosInOpenList(int pX, int pY){
	Node<Cell*>* tmp = _openList->getHead();
	for(int i = 0; i< _openList->getLength(); i++){
		if( tmp->getData()->getX() == pX  &&  tmp->getData()->getY() == pY ){
			return tmp->getData();
		};
		tmp = tmp->getNext();
	}
	return 0;
}

void GPS::metodoDeAbraham(uint8_t pX, uint8_t pY,uint8_t endX, uint8_t endY){

	if(_map->getDataID(pX,pY) != 49){//solo se permite comenzar desde una posicion con zacate(transitable)
		return;
	}

	int pG = 0; // coste desde la posicion pX,pY.

	bool finished = false;

	Cell* currentCell = new Cell();
	currentCell->setData(pX,pY,NULL,0);

	_openList = new LinkedList<Cell*>(); // nuestra lista de compra
	_closedList = new LinkedList<Cell*>();
	_closedList->insertTail(currentCell);

	while(!finished){
		if(pX == endX && pY == endY){
			finished = true;
			return;
		}
		//---------------------Derecha-----------------------
		if(_map->getDataID(pX+1,pY) == 49){
			int Heuristic = getH(pX+1,pY,endX,endY);
			Cell* newCell = new Cell();
			newCell->setData(pX+1,pY,currentCell,pG+Heuristic);
			if(isOnClosedList(newCell) == false){		//si no esta en la lista cerrada. Hacer->
				if(isOnOpendList(newCell) == false){			//si no esta en la lista abierta. Hacer->
					_openList->insertTail(newCell);
				}else{										//ya estaba en la lista abierta,comparar la posible nueva ruta
					//Check if the F score is lower when we use the current generated path to get there. If it is,
					//update its score and update its parent as well.
					if( this->getHeuristicInOpenListOf(pX+1,pY) > newCell->getF()){
						//actualizar
						Cell* newOne = getCellPosInOpenList(pX+1,pY);
						newOne->setData(pX+1,pY,currentCell,pG+Heuristic);
					}// de otra forma ignorar
				}
			}
		}
		//---------------------Izquierda-----------------------
		if(_map->getDataID(pX-1,pY) == 49){
			int Heuristic = getH(pX-1,pY,endX,endY);
			Cell* newCell = new Cell();
			newCell->setData(pX-1,pY,currentCell,pG+Heuristic);
			if(isOnClosedList(newCell) == false){		//si no esta en la lista cerrada. Hacer->
				if(isOnOpendList(newCell) == false){			//si no esta en la lista abierta. Hacer->
					_openList->insertTail(newCell);
				}else{										//ya estaba en la lista abierta,comparar la posible nueva ruta
					//Check if the F score is lower when we use the current generated path to get there. If it is,
					//update its score and update its parent as well.
					if( this->getHeuristicInOpenListOf(pX-1,pY) > newCell->getF()){
						//actualizar
						Cell* newOne = getCellPosInOpenList(pX-1,pY);
						newOne->setData(pX-1,pY,currentCell,pG+Heuristic);
					}// de otra forma ignorar
				}
			}
		}

		//---------------------Abajo-----------------------
		if(_map->getDataID(pX,pY+1) == 49){
			int Heuristic = getH(pX,pY+1,endX,endY);
			Cell* newCell = new Cell();
			newCell->setData(pX,pY+1,currentCell,pG+Heuristic);
			if(isOnClosedList(newCell) == false){		//si no esta en la lista cerrada. Hacer->
				if(isOnOpendList(newCell) == false){			//si no esta en la lista abierta. Hacer->
					_openList->insertTail(newCell);
				}else{										//ya estaba en la lista abierta,comparar la posible nueva ruta
					//Check if the F score is lower when we use the current generated path to get there. If it is,
					//update its score and update its parent as well.
					if( this->getHeuristicInOpenListOf(pX,pY+1) > newCell->getF()){
						//actualizar
						Cell* newOne = getCellPosInOpenList(pX,pY+1);
						newOne->setData(pX,pY+1,currentCell,pG+Heuristic);
					}// de otra forma ignorar
				}
			}
		}

		//---------------------------Arriba------------
		if(_map->getDataID(pX,pY-1) == 49){
			int Heuristic = getH(pX,pY-1,endX,endY);
			Cell* newCell = new Cell();
			newCell->setData(pX,pY-1,currentCell,pG+Heuristic);
			if(isOnClosedList(newCell) == false){		//si no esta en la lista cerrada. Hacer->
				if(isOnOpendList(newCell) == false){			//si no esta en la lista abierta. Hacer->
					_openList->insertTail(newCell);
				}else{										//ya estaba en la lista abierta,comparar la posible nueva ruta
					//Check if the F score is lower when we use the current generated path to get there. If it is,
					//update its score and update its parent as well.
					if( this->getHeuristicInOpenListOf(pX,pY-1) > newCell->getF()){
						//actualizar
						Cell* newOne = getCellPosInOpenList(pX,pY-1);
						newOne->setData(pX,pY-1,currentCell,pG+Heuristic);
					}// de otra forma ignorar
				}
			}
		}


		_closedList->insertTail(currentCell);
		_openList->deleteData(currentCell);

		currentCell = getBestCellAbraham(_openList);
		Cell* newBestCell = new Cell();
		newBestCell->setData(currentCell->getX(),currentCell->getY(),currentCell->getPrevious(),currentCell->getF());
		_pathList->insertTail(newBestCell);
		pG++;	//Aumentar el G actual en 1, pues se avanzó una celda.
		pX = newBestCell->getX();
		pY = newBestCell->getY();
	}
}

int GPS::getH(uint8_t pX, uint8_t pY,uint8_t endX, uint8_t endY){
	int H = 0;
	H+= abs((endX-pX));
	H+= abs((endY-pY));
	return abs(H);
}

Cell* GPS::getBestCellAbraham(LinkedList<Cell*>* openList){
	Cell* currentCell = openList->getHead()->getData();
	Node<Cell*>* currentNode = openList->getHead();
	if(openList->getLength() == 1){
		return currentNode->getData();
	}
	else{
		for(int i = 0; i < openList->getLength(); i++){
			currentCell = getBestBetweenAbraham(currentCell,currentNode->getNext()->getData());
			currentNode = currentNode->getNext();
		}
	}

	return currentCell;
}

Cell* GPS::getBestBetweenAbraham(Cell* A, Cell* B){
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
		std::cout << "CLOSEEEEED LIST LENGHT: "<< _closedList->getLength() << std::endl;
		if(pX == endX && pY == endY){

			finished = true;
			return true;
		}
		else{

			std::cout << "currentX " << (int) pX << std::endl;
			std::cout << "currentY " << (int) pY << std::endl;

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

			std::cout << "=========" << std::endl;
			//sleep(2);
		}
	}

	return false;
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
	LinkedList<Cell*>* l = new LinkedList<Cell*>();

	for(Cell* i =_closedList->getTail()->getData(); i->getPrevious() != NULL; i = i->getPrevious() ){
		std::cout << i->getX() << " " << i->getY() << std::endl;
	}

//	Node<Cell*>* tmp = l->getHead();
//	for(int i = 0; i < _closedList->getLength(); i++){
//		std::cout << tmp->getData()->getX() << " " << tmp->getData()->getY() << std::endl;
//		tmp=tmp->getNext();
//	}

	//	if(_pathList->getHead() != 0){
//		Node<Cell*>* tmp = _pathList->getHead();
//		for(int i = 0; i < _pathList->getLength(); i++){
//			std::cout << tmp->getData()->getX() << " " << tmp->getData()->getY() << std::endl;
//			tmp=tmp->getNext();
//		}
//	}
//	else{
//		Node<Cell*>* tmp = _closedList->getHead();
//		for(int i = 0; i < _closedList->getLength(); i++){
//			std::cout << tmp->getData()->getX() << " " << tmp->getData()->getY() << std::endl;
//			tmp=tmp->getNext();
//		}
//	}

}

bool GPS::isOnOpendList(Cell* pCell){
	Node<Cell*>* tmp = _openList->getHead();
	for(int i = 0; i < _openList->getLength(); i++){
		if((tmp->getData()->getX() == pCell->getX()) && (tmp->getData()->getY() == pCell->getY())){
			return true;
		}
		tmp = tmp->getNext();
	}
	return false;
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
