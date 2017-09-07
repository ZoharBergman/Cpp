#ifndef __BUTHCERY_H
#define __BUTHCERY_H

#include "Employee.h"
class Dish;

class Buthcery : public Employee
{
public:
	Buthcery(const Employee& employee);
	virtual ~Buthcery();

	// Methods
	void makeDish(const Dish& dish) const;
};

#endif // __BUTHCERY_H
