#ifndef __WAITER_H
#define __WAITER_H

#include "Order.h"
#include "Employee.h"

class Waiter : public Employee
{
public:
	Order* orders;

public:
	// Getters
	const Order* getAllOrders() const { return orders; }
	const Order getOrderByOrderId(long orderId) const;

	// Methods
	void takeOrder(const Order &order);
	int serveBill(const Order &order);
	void cleanTable(const Table &table) const;
	void print() const;
};

#endif // __WAITER_H
