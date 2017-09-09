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

	const static int MAX_DESCRIPTION_SIZE = 100;
	const static int MAX_NAME_SIZE = 30;

private:
	int price;
	char description[MAX_DESCRIPTION_SIZE];
	char name[MAX_NAME_SIZE];
	sIngredientAndQuantity* ingredientsAndQuantities;
	int physicalSizeIngredientsAndQuantities;
	int logicalSizeIngredientsAndQuantities;
	eDishType type;

public:
	Dish(int price = 0, const char* description = "", const char* name = "", const sIngredientAndQuantity* ingredientsAndQuantities = NULL, int sizeIngredientsAndQuantities = 0, eDishType type = MAIN_COURSE);
	Dish(const Dish& other){ *this = other; }
	~Dish() {delete []ingredientsAndQuantities;}

	// Getters
	int getPrice() const {return price;}
	const char* getDescription() const {return description;}
	const char* getName() const {return name;}
	const sIngredientAndQuantity* getIngredientsAndQuantities() const {return ingredientsAndQuantities;}
	int getSizeIngredientsAndQuantities() const { return logicalSizeIngredientsAndQuantities; }

	// Setters
	void setPrice(int price) {this->price = price; }
	void setDescription (const char* description);

	// Operators
	const Dish& operator=(const Dish& other);
	bool operator<(const Dish& other) const { return this->calcCalories() < other.calcCalories();}
	const int operator+(const Dish& other) const;
	friend int operator+(const Dish& dish, int price);
	friend int operator+(int price, const Dish& dish);	

	// Methods
	void addIngredients(const sIngredientAndQuantity* ingredientsAndQuantities, int sizeIngredientsAndQuantities);
	double calcCalories() const;
	void print() const;
};

#endif // __DISH_H