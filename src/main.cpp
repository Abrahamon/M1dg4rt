//============================================================================
// Name        : Midgard.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "com.Midgard.DataStructures/grafoGenealogico.h"
#include "com.Midgard.DataStructures/nodoGenealogico.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;

	grafoGenealogico* polacion = new grafoGenealogico();
	polacion->getRootGood();

}
