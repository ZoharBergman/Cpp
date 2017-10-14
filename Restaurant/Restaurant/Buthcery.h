#ifndef __BUTHCERY_H
#define __BUTHCERY_H

#include "Employee.h"
class Dish;

class Buthcery : public Employee
{
private:
	Buthcery(const Buthcery& other);
	const Buthcery& operator=(const Buthcery& other);

public:
	Buthcery(const char* name, int seniority, long bankAccountID, int salary);
	virtual ~Buthcery();

	// Methods
	void makeDish(const Dish& dish) const;
};

#endif // __BUTHCERY_H
