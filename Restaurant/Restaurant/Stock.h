#ifndef __STOCK_H
#define __STOCK_H

#include "IngredientAndQuantity.h"
#include "Ingredient.h"

class Stock
{
public:
	sIngredientAndQuantity* ingredientsAndQuantities;
	
public:
	Stock(const sIngredientAndQuantity* ingredientsAndQuantities);
	~Stock(){delete []ingredientsAndQuantities;}

	//Getters
	const sIngredientAndQuantity* getAllIngredientsAndtQuantities() const { return ingredientsAndQuantities; }
	const sIngredientAndQuantity getIngredientAndQuantityByIngredientName(const char* ingredientName) const;

	//Methods
	void addIngredient(const Ingredient& ingredient);
	void removeIngredient(const Ingredient& ingredient);
	bool isIngredientAboutToEnd(const Ingredient& ingredient) const;
	const Ingredient* getEndedIngredients() const;
	void print() const;
};

#endif // __STOCK_H

