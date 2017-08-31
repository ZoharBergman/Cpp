#ifndef __BUTHCERY_H
#define __BUTHCERY_H

#include "Employee.h"

class Buthcery : public Employee
{

public:	
	// Methods
	void makeDish(const Dish& dish) const;
};

#endif // __BUTHCERY_H
