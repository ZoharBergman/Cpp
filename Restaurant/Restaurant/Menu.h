#ifndef __MENU_H
#define __MENU_H

#include "Dish.h"

class Menu
{
private:
	const Dish* dishes;
public:
	Menu(const Dish* dishes);
	~Menu(){delete []dishes;}
	Menu(const Menu& other) = delete;

	// Operators
	const Menu& operator+=(const Dish& dish){this->addDish(dish);}

	// Methods
	void addDish(const Dish& dish);
	void removeDish(const char* dishName);
	void print() const;
	const Dish* getDishByName(const char* name);
};

#endif // __MENU_H