/*
 * GPS.h
 *
 *  Created on: May 8, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_LOGIC_GPS_H_
#define SRC_COM_MIDGARD_LOGIC_GPS_H_
#include <stdint.h>
#include "../com.Midgard.DataStructures/PyArray.h"
#include "../com.Midgard.DataStructures/linkedList.h"
#include "../com.Midgard.Entities/Entity.h"
#include "Cell.h"


class GPS {
private:
	PyArray<char>* _map;
	LinkedList<Cell*>* _visitedList;
	LinkedList<Cell*>*_openList;
	LinkedList<Cell*>* _pathList;


	int getH(uint8_t pX, uint8_t pY,uint8_t endX, uint8_t endY);
	Cell* getBestCell(LinkedList<Cell*>* openList,bool retry);
	Cell* getBestCellAbraham(LinkedList<Cell*>* openList);
	Cell* getBestBetween(Cell* A, Cell* B,bool retry);
	Cell* getBestBetweenAbraham(Cell* A, Cell* B);
	int getHeuristicInOpenListOf(int pX, int pY);
	Cell* getCellPosInOpenList(int pX, int pY);
	bool isOnClosedList(Cell* pCell);
	bool isOnOpendList(Cell* pCell);


	void setStartGoal(Cell* start, Cell* goal);
	void pathOpen(int pX, int pY, float newCost, Cell* pParent);
	Cell* getNextCell();
	void continuePath();
	Cell* c_StartCell;
	Cell* c_GoalCell;

public:
	GPS();
	virtual ~GPS();
	void findPath(Entity* pEnd);
	bool getWalkableCells(uint8_t pX, uint8_t pY,uint8_t endX, uint8_t endY,bool retry);
	void metodoDeAbraham(uint8_t pX, uint8_t pY,uint8_t endX, uint8_t endY);
	void printBestPath();
	void loadMap();


	void FindPath(uint8_t pX, uint8_t pY,uint8_t endX, uint8_t endY);
	Cell* NextPathPos();
	void clearOpenList();
	void clearVisitedList();
	void clearPathGoal();
	bool  b_intializadStartGaol;
	bool b_foundGoal;

};

#endif /* SRC_COM_MIDGARD_LOGIC_GPS_H_ */
