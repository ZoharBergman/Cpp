#ifndef __STAFF_MAMAGER_H
#define __STAFF_MAMAGER_H

#include "Employee.h"

class StaffManager
{
private:
	Employee* employees;

public:	
	StaffManager(const Employee* employees);
	StaffManager(const StaffManager& other) = delete;
	~StaffManager() { delete []employees; }

	// Methods
	void employ(const Employee& employee) ;
	void fire(const Employee& employee);
	void ShoutOnEmployees() const;
	void print() const;
};

#endif // __STAFF_MAMAGER_H

