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
	int logicalSizeDishes;
	int physicalSizeDishes;
	const Table* table;
	eOrderStatus status;

	Order(const Order& other);
	const Order& operator=(const Order& other);

public:
	Order(const Table* table);
	~Order();

	// Getters
	const Dish** getDishes() const { return dishes; }
	int getSizeDishes() const { return logicalSizeDishes; }
	const Table& getTable() const { return *table; }
	eOrderStatus getStatus() const { return status; }
	
	// Setters
	void setTable(const Table*& table) {this->table = table; }
	void setStatus(eOrderStatus status) { this->status = status; }

	// Operators
	const Order& operator+=(const Dish* dish){this->addDish(dish); return *this; }

	// Methods
	int calcPrice() const;
	void cancelDish(const char* dishName);
	void addDish(const Dish* dish);
	void print() const;

};
long Order::idCounter = 0;

#endif // __ORDER_H