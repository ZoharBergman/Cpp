#include <iostream>
using namespace std;

#include "Restaurant.h"

void main()
{
	//Restaurant restaurant("Papa", Chef(
	Waiter charlie(Employee("Charlie", 1, 123, 1000));
	StaffManager staffManager(&charlie, 1);
	staffManager.getEmployeeByEmployeeId(1).setBankAccountID(10);
}