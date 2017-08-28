#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

class Employee
{
public:
	const static int MAX_NAME_LENGTH = 40;
	static long idCounter;

protected:
	char name[MAX_NAME_LENGTH];
	int seniority;
	int bankAccountID;
	int salary;
	long employeeID;

public:
	Employee(const char* name, int seniority, int bankAccountID, int salary) { employeeID = idCounter++; };
	~Employee();

	// Getters
	const char* getName() const { return name; }
	const int getSeniority() const { return seniority; }
	const int getBankAccountID() const { return bankAccountID; }
	const int getSalary() const { return salary; }
	const long getEmployeeID() const { return employeeID; }

	// Methods
	const long quit() const;
	void print() const;
};
long Employee::idCounter = 0;

#endif // __EMPLOYEE_H

