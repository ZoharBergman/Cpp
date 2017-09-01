#ifndef __STOCK_H
#define __STOCK_H

#include "IngredientAndQuantity.h"
#include "Ingredient.h"

class Stock
{
private:
	sIngredientAndQuantity* ingredientsAndQuantities;
	int sizeIngredientsAndQuantities;
	
public:
	Stock(const sIngredientAndQuantity* ingredientsAndQuantities, int sizeIngredientsAndQuantities);
	Stock(const Stock& other) = delete;
	~Stock(){delete []ingredientsAndQuantities;}

	//Getters
	const sIngredientAndQuantity* getAllIngredientsAndtQuantities() const { return ingredientsAndQuantities; }
	const sIngredientAndQuantity& getIngredientAndQuantityByIngredientName(const char* ingredientName) const;
	sIngredientAndQuantity& getIngredientAndQuantityByIngredientName(const char* ingredientName);
	int getSizeIngredientsAndQuantities() const { return sizeIngredientsAndQuantities; }

	// Operators
	const Stock& operator++();

	//Methods
	void addIngredient(const Ingredient& ingredient);
	void removeIngredient(const Ingredient& ingredient);
	bool isIngredientAboutToEnd(const Ingredient& ingredient) const;
	const Ingredient* getEndedIngredients() const;
	void print() const;
};

#endif // __STOCK_H

