#ifndef __WAITER_H
#define __WAITER_H

#include "Order.h"
#include "Employee.h"

class Waiter : public Employee
{
public:
	const static int MAX_NUM_ORDERS = 10;

private:
	Order orders[MAX_NUM_ORDERS];

	Waiter(const Waiter& other);
	const Waiter& operator=(const Waiter& other);

public:
	Waiter(const char* name, int seniority, long bankAccountID, int salary);

	// Getters
	const Order* getAllOrders() const { return orders; }
	const Order& getOrderByOrderId(long orderId) const;
	Order& getOrderByOrderId(long orderId);

	// Methods
	void takeOrder(const Order& order);
	int serveBill(const Order& order);
};

#endif // __WAITER_H
