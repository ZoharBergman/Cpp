#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>

class Employee
{
public:
	static long idCounter;

protected:
	char* name;
	int seniority;
	long bankAccountID;
	int salary;
	long employeeID;

public:
	Employee(const char* name, int seniority, long bankAccountID, int salary);
	~Employee(){delete []name;}
	Employee(const Employee& other) = delete;

	// Getters
	const char* getName() const { return name; }
	int getSeniority() const { return seniority; }
	long getBankAccountID() const { return bankAccountID; }
	int getSalary() const { return salary; }
	long getEmployeeID() const { return employeeID; }

	// Setters
	void setName(const char* name) { this->name = strdup(name); }
	void setSeniority(int seniority) { this->seniority = seniority; }
	void setBankAccountID(int bankAccountID) { this->bankAccountID = bankAccountID; }
	void setSalary(int salary) { this->salary = salary; }

	// Methods
	void quit() const;
	void print() const;
};
long Employee::idCounter = 0;

#endif // __EMPLOYEE_H

