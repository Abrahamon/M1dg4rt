/*
 * nodoGenealogico.h
 *
 *  Created on: Apr 22, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_DATASTRUCTURES_NODOGENEALOGICO_H_
#define COM_MIDGARD_DATASTRUCTURES_NODOGENEALOGICO_H_

#include "linkedList.h"

class nodoGenealogico {

private:
	//individuo
	nodoGenealogico* _madre;
	nodoGenealogico* _padre;
	nodoGenealogico* _pareja;
	LinkedList<nodoGenealogico*>* _hijos;

public:
	nodoGenealogico();
	virtual ~nodoGenealogico();

	nodoGenealogico* getMadre();
	nodoGenealogico* getPadre();
	nodoGenealogico* getPareja();
	LinkedList<nodoGenealogico*>* getHijos();

};

#endif /* COM_MIDGARD_DATASTRUCTURES_NODOGENEALOGICO_H_ */
