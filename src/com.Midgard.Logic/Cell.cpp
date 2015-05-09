/*
 * Cell.cpp
 *
 *  Created on: May 8, 2015
 *      Author: fabian
 */

#include "Cell.h"

Cell::Cell(){
	_Xcoord = 0;
	_Ycoord = 0;
	_Previous = 0;
	_F = 0;
	_Null = true;
}

Cell::~Cell() {}

void Cell::setData(int pX, int pY, Cell* pPrevious,int pF){
	_Xcoord = pX;
	_Ycoord = pY;
	_Previous = pPrevious;
	_F = pF;
	_Null = false;

}

int Cell::getX(){ return _Xcoord; }
int Cell::getY(){ return _Ycoord; }
int Cell::getF(){ return _F; }
bool Cell::isNull(){ return _Null; }
Cell* Cell::getPrevious(){ return _Previous; }
