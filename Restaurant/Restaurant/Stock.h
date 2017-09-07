#ifndef __STOCK_H
#define __STOCK_H

#include "IngredientAndQuantity.h"
#include "Ingredient.h"

class Stock
{
private:
	sIngredientAndQuantity* ingredientsAndQuantities;
	int sizeIngredientsAndQuantities;
	Stock(const Stock& other);

public:
	Stock(const sIngredientAndQuantity* ingredientsAndQuantities = nullptr, int sizeIngredientsAndQuantities = 0);	
	~Stock(){delete []ingredientsAndQuantities;}

	//Getters
	const sIngredientAndQuantity* getAllIngredientsAndtQuantities() const { return ingredientsAndQuantities; }
	const sIngredientAndQuantity& getIngredientAndQuantityByIngredientName(const char* ingredientName) const;
	const Ingredient& getIngredientByIngredientName(const char* ingredientName) const;
	sIngredientAndQuantity& getIngredientAndQuantityByIngredientName(const char* ingredientName);
	int getSizeIngredientsAndQuantities() const { return sizeIngredientsAndQuantities; }

	// Operators
	const Stock& operator++();

	//Methods
	void addIngredient(const Ingredient*& ingredient);
	void addIngredient(Ingredient*& ingredient);
	void removeIngredient(const Ingredient*& ingredient);
	bool isIngredientAboutToEnd(const Ingredient*& ingredient) const;
	const Ingredient** getEndedIngredients() const;
	void print() const;
};

#endif // __STOCK_H

