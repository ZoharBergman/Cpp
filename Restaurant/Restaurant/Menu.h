#ifndef __MENU_H
#define __MENU_H

#include "Dish.h"

class Menu
{
private:
	Dish* dishes;
	int logicalSizeDishes;
	int physicalSizeDishes;
	Menu(const Menu& other);

public:
	Menu(const Dish* dishes = NULL, int sizeDishes = 0);
	~Menu(){delete []dishes;}	

	// Getters
	const Dish* getAllDishes() const { return dishes; }
	int getSizeDishes() const {return logicalSizeDishes; }
	const Dish*& getDishByName(const char* name);

	// Operators
	const Menu& operator+=(const Dish& dish){this->addDish(dish);}

	// Methods
	void addDish(const Dish& dish);
	void removeDish(const char* dishName);
	void print() const;	
};

#endif // __MENU_H