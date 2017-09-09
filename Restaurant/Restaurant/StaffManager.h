#ifndef __STAFF_MAMAGER_H
#define __STAFF_MAMAGER_H

#include "Employee.h"

class StaffManager
{
private:
	Employee* employees;
	int logicalSizeEmployees;
	int physicalSizeEmployees;
	StaffManager(const StaffManager& other);

public:	
	StaffManager(const Employee* employees = NULL, int sizeEmployees = 0);	
	virtual ~StaffManager() { delete []employees; }

	// Getters
	const Employee* getAllEmployees() const { return employees; }
	int getSizeEmployees() const { return logicalSizeEmployees; }
	const Employee& getEmployeeByEmployeeId(long employeeId) const;
	Employee& getEmployeeByEmployeeId(long employeeId);

	// Methods
	void employ(const Employee& employee);
	void fire(const Employee& employee);
	void ShoutOnEmployees() const;
};

#endif // __STAFF_MAMAGER_H

