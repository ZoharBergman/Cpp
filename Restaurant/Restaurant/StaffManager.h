#ifndef __STAFF_MAMAGER_H
#define __STAFF_MAMAGER_H

#include "Employee.h"

class StaffManager
{
private:
	Employee* employees;
	int sizeEmployees;

public:	
	StaffManager(const Employee* employees, int sizeEmployees);
	StaffManager(const StaffManager& other) = delete;
	virtual ~StaffManager() { delete []employees; }

	// Getters
	const Employee* getAllEmployees() const { return employees; }
	int getSizeEmployees() const { return sizeEmployees; }
	const Employee& getEmployeeByEmployeeId(long employeeId) const;
	Employee& getEmployeeByEmployeeId(long employeeId);

	// Methods
	void employ(const Employee& employee);
	void fire(const Employee& employee);
	void ShoutOnEmployees() const;
};

#endif // __STAFF_MAMAGER_H

