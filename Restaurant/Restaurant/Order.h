#ifndef __ORDER_H
#define __ORDER_H

#include "Dish.h"
#include "Table.h"

class Order
{
public: 
	const static enum eOrderStatus
	{
		BEING_TAKEN,
		IN_PREPARATION,
		SERVED
	};
	static long idCounter;
private:
	long id;
	const Dish** dishes;
	const Table* table;
	eOrderStatus status;
public:
	Order(const Dish**& dishes, const Table& table, eOrderStatus status);
	~Order();

	// Methods
	int calcPrice() const;
	void cancelDish(const char*& dishName);
	void addDish(const Dish*& dish);
	void print() const;

};
long Order::idCounter = 0;

#endif // __ORDER_H