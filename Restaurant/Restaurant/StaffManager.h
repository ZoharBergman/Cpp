#ifndef __STAFF_MAMAGER_H
#define __STAFF_MAMAGER_H

#include "Employee.h"

class StaffManager
{
private:
	Employee **employees;

public:
	
	// Getters
	const char* getName() const { return name; }
	
	// Methods
	const Employee* employ() ;
	const long fire(Employee &emp);
	void distributeOrdersToEmployees() const;
	void  ShoutOnEmployees() const;
	void print() const;
};

#endif // __STAFF_MAMAGER_H

