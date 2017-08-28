#ifndef __WAITER_H
#define __WAITER_H

#include "Order.h"

class Waiter : public Empolyee
{
public:
	Order **orders;

public:
	// Getters
	const order* getOrder() const { return order; }

	// Methods
	void takeOrder(const Order &order);
	const int serveBill(const Order &order);
	void cleanTable(const Table &table) const;
	void print() const;
};

#endif // __WAITER_H
