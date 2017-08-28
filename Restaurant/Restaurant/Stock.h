#ifndef __STOCK_H
#define __STOCK_H

#include "IngredientAndQuantity.h"

class Stock
{
public:
	IngredientAndQuantity **ingredientsAndQuantities;

public:

	//Getters
	const int* getQuantity(Ingredient &ingredient) const { return quantity; }

	//Methods
	void addIngredient(const Ingredient &ingredient) const;
	void removeIngredient(Ingredient &ingredient) const;
	bool isIngredientAboutToEnd(const Ingredient &ingredient);
	const Ingredient* getEndedIngredients() const;
	void print() const;
};

#endif // __STOCK_H

