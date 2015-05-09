/*
 * Cell.h
 *
 *  Created on: May 8, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_LOGIC_CELL_H_
#define SRC_COM_MIDGARD_LOGIC_CELL_H_

class Cell{
private:
	bool _Null;
	int _Xcoord;
	int _Ycoord;
	int _F;
	Cell* _Previous;
public:
	Cell();
	virtual ~Cell();

	int getX();
	int getY();
	int getF();
	bool isNull();
	Cell* getPrevious();

	void setData(int pX, int pY, Cell* pPrevious,int pF);
};



#endif /* SRC_COM_MIDGARD_LOGIC_CELL_H_ */
