#ifndef __DISH_H
#define __DISH_H

#include "IngredientAndQuantity.h"

class Dish
{
public:
	const static enum eDishType
	{
		FIRST,
		MAIN_COURSE,
		DESSERT
	};

private:
	int price;
	char* description;
	char* name;
	sIngredientAndQuantity* ingredientsAndQuantities;
	eDishType type;

public:
	Dish(int price, const char* description, const char* name, const sIngredientAndQuantity* ingredientsAndQuantities, eDishType type);
	Dish(const Dish& other){ *this = other; }
	~Dish() {delete []description; delete []name; delete []ingredientsAndQuantities;}

	// Getters
	int getPrice() const {return price;}
	const char* getDescription() const {return description;}
	const char* getName() const {return name;}
	const sIngredientAndQuantity* getIngredientsAndQuantities() const {return ingredientsAndQuantities;}

	// Setters
	void setPrice(int price) {this->price = price; }
	void setDescription (const char* description) {this->description = strdup(description);}

	// Operators
	const Dish& operator=(const Dish& other);
	friend int operator+(const Dish& dish, int price);
	friend int operator+(int price, const Dish& dish);
	bool operator<(const Dish& other){ return this->calcCalories() < other.calcCalories();}

	// Methods
	double calcCalories() const;
	void print() const;
};

#endif // __DISH_H