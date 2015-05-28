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
	_Parent = 0;
	_G = 0;
	_H = 0;
}

Cell::Cell(int pX, int pY,Cell* pParent){
	_Xcoord = pX;
	_Ycoord = pY;
	_Parent = pParent;
	_H = 0;
	_G = 0;
}

Cell::~Cell() {}

void Cell::setData(int pX, int pY, Cell* pPrevious,int pF){
	_Xcoord = pX;
	_Ycoord = pY;
	_Parent = pPrevious;
	_G = pF;
}

int Cell::getX(){ return _Xcoord; }
int Cell::getY(){ return _Ycoord; }
int Cell::getF(){ return _G+_H; }
int Cell::getH(){ return _H; }
int Cell::getG(){ return _G; }
Cell* Cell::getPrevious(){ return _Parent; }
void Cell::setG(int pG){_G= pG;}
void Cell::setH(int pH){ _H = pH;}
void Cell::setParent(Cell* pParent){this->_Parent = pParent;}

float Cell::ManHattanDistance(Cell* nodeEnd){
	float mx = (float)(fabs(float(this->_Xcoord - nodeEnd->getX())));
	float my = (float)(fabs(float(this->_Ycoord - nodeEnd->getY())));
	return mx+my;
}

