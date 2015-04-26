/*
 * Fitness.h
 *
 *  Created on: Apr 23, 2015
 *      Author: abrahamon
 */

#ifndef COM_MIDGARD_GENETICSMANAGER_FITNESS_H_
#define COM_MIDGARD_GENETICSMANAGER_FITNESS_H_

class Fitness {

private:
	static Fitness* _Fitness;

public:
	Fitness();
	virtual ~Fitness();

	static Fitness* getInstance();

};

#endif /* COM_MIDGARD_GENETICSMANAGER_FITNESS_H_ */
