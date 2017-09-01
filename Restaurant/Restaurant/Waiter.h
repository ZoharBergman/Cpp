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

public:
	Waiter(const Employee& Employee);

	// Getters
	const Order* getAllOrders() const { return orders; }
	const Order& getOrderByOrderId(long orderId) const;
	Order& getOrderByOrderId(long orderId);

	// Methods
	void takeOrder(const Order &order);
	int serveBill(const Order &order);
	void cleanTable(const Table &table) const;
};

#endif // __WAITER_H
