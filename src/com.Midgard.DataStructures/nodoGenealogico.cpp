/*
 * nodoGenealogico.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: abrahamon
 */

#include "../com.Midgard.DataStructures/nodoGenealogico.h"

nodoGenealogico::nodoGenealogico() {
	// TODO Auto-generated constructor stub

}

nodoGenealogico::~nodoGenealogico() {
	// TODO Auto-generated destructor stub
}

nodoGenealogico* nodoGenealogico::getPadre()
{
	return this->_padre;
}

nodoGenealogico* nodoGenealogico::getMadre()
{
	return this->_madre;
}

nodoGenealogico* nodoGenealogico::getPareja(){
	return this->_pareja;
}

LinkedList<nodoGenealogico*>* nodoGenealogico::getHijos(){
	this->_hijos;
}
