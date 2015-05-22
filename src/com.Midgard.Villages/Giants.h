/*
 * Giants.h
 *
 *  Created on: Apr 25, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_VILLAGES_GIANTS_H_
#define COM_MIDGARD_VILLAGES_GIANTS_H_

#include "Population.h"

class Giants : public Population {
private:
	Random* _random;
public:
	Giants();
	virtual ~Giants();
};

#endif /* COM_MIDGARD_VILLAGES_GIANTS_H_ */
