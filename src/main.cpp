//============================================================================
// Name        : M1dg4r.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bitset>
#include <iostream>
#include "../src/com.Midgard.Entities/Entity.h"
#include "../src/com.Midgard.Entities/Dwarve.h"
#include "../src/com.Midgard.Villages/Dwarves.h"
#include "../src/com.Midgard.DataStructures/linkedList.h"
#include "../src/com.Midgard.Genetics/Fitness.h"
#include "../src/com.Midgard.Genetic/Genome.h"

using namespace std;

int main() {


	Dwarve* enano1 = new Dwarve(true,0,0,0,0,100);

	std::bitset<4> b(20);
   std::cout << "in binary is "<<  b << std::endl;


   return 0;
}
