#ifndef __MENU_H
#define __MENU_H

#include "Dish.h"

class Menu
{
private:
	Dish** dishes;
	int logicalSizeDishes;
	int physicalSizeDishes;

	Menu(const Menu& other);
	const Menu& operator=(const Menu& other);

public:
	Menu();
	~Menu();	

	// Getters
	const Dish*const* getAllDishes() const { return dishes; }
	int getSizeDishes() const {return logicalSizeDishes; }
	const Dish*& getDishByName(const char* name);

	// Operators
	const Menu& operator+=(const Dish* dish){this->addDish(dish); return *this;}

	// Methods
	void addDish(const Dish* dish);
	void removeDish(const char* dishName);
	void print() const;	
};

#endif // __MENU_H