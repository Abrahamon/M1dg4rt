/*
 * Cell.h
 *
 *  Created on: May 8, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_LOGIC_CELL_H_
#define SRC_COM_MIDGARD_LOGIC_CELL_H_

#include <math.h>

class Cell{
public:
	int _Xcoord;
	int _Ycoord;
	Cell* _Parent;
	int _G;
	int _H;

//public:
	Cell();
	Cell(int pX, int pY,Cell* pParent);
	virtual ~Cell();

	int getX();
	int getY();
	int getF();
	int getH();
	int getG();
	void setG(int pG);
	void setH(int pH);
	void setParent(Cell* pParent);
	bool isNull();
	Cell* getPrevious();

	void setData(int pX, int pY, Cell* pPrevious,int pF);
	float ManHattanDistance(Cell* nodeEnd);
};



#endif /* SRC_COM_MIDGARD_LOGIC_CELL_H_ */
