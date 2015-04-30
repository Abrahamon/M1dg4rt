/*
 * PyArray.h
 *
 *  Created on: Apr 30, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_DATASTRUCTURES_PYARRAY_H_
#define SRC_COM_MIDGARD_DATASTRUCTURES_PYARRAY_H_
#include "linkedList.h"
#include "linkedNode.h"

template<class k>
class PyArray {
private:
	LinkedList<LinkedList<k>*>* _Array;
	int _MaxX;
	int _MaxY;

public:
	PyArray(int NumberOfRows, int NumberOfColumns);
	virtual ~PyArray();
	int getDataID(int x, int y);
	void setDataID(int x, int y, k pData);
	void printRow(int y);
	void printMatrix();
};

#endif /* SRC_COM_MIDGARD_DATASTRUCTURES_PYARRAY_H_ */

template<typename k>
PyArray<k>::PyArray(int NumberOfRows, int NumberOfColumns) {
	_Array = new LinkedList< LinkedList<k>* >();

	_MaxX = NumberOfRows;
	_MaxY = NumberOfColumns;

	/*LinkedList<int>* tmp = new LinkedList<int>();
	for(int j = 0; j < NumberOfColumns; j++){
		tmp->insertTail(0);
	}
	for(int i = 0; i < NumberOfRows; i++){
		_Array->insertTail(tmp);
	}*/
	for(int i = 0; i < NumberOfRows; i++){
		LinkedList<k>* tmp = new LinkedList<k>();
		int x = i;
		for(int j = 0; j < NumberOfColumns; j++){
			tmp->insertTail(0);
		}
		_Array->insertTail(tmp);
	}
}
template<class k>
PyArray<k>::~PyArray() {}

template<class k>
void PyArray<k>::setDataID(int x, int y, k pData){
	if(x > _MaxX){
		std::cout << "**PyArray: x outside Array **" << std::endl;
		return;
	}
	if(y > _MaxY){
		std::cout << "**PyArray: y outside Array **" << std::endl;
		return;
	}
	Node<LinkedList<k>*>* tmpNode = _Array->getHead();
	for(int j = 0; j < x; j++){
		tmpNode = tmpNode->getNext();
	}
	Node<k>* tmpData = tmpNode->getData()->getHead();
	for(int i = 0; i < y; i++){
		tmpData = tmpData->getNext();
	}
	tmpData->setData(pData);
}

template<class k>
int PyArray<k>::getDataID(int x, int y){
	if(x > _MaxX){
		std::cout << "**PyArray: x outside Array **" << std::endl;
		return 0;
	}
	if(y > _MaxY){
		std::cout << "**PyArray: y outside Array **" << std::endl;
		return 0;
	}
	Node<LinkedList<k>*>* tmpNode = _Array->getHead();
	for(int j = 0; j < x; j++){
		tmpNode = tmpNode->getNext();
	}
	Node<int>* tmpData = tmpNode->getData()->getHead();
	for(int i = 0; i < y; i++){
		tmpData = tmpData->getNext();
	}
	return tmpData->getData();
}

template<class k>
void PyArray<k>::printRow(int y){

	Node<LinkedList<k>*>* tmpNode = _Array->getHead();

	for(int j = 0; j < y; j++){
		tmpNode = tmpNode->getNext();
	}

	Node<k>* tmpData = tmpNode->getData()->getHead();
	for(int i = 0; i < _MaxX; i++){
		std::cout << tmpData->getData();
		tmpData = tmpData->getNext();
	}
	std::cout<< std::endl;

}

template<class k>
void PyArray<k>::printMatrix(){
	for(int i = 0; i < _MaxY; i++){
		printRow(i);
	}
}
