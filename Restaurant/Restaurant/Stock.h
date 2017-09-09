#ifndef __STOCK_H
#define __STOCK_H

#include "IngredientAndQuantity.h"
#include "Ingredient.h"

class Stock
{
private:
	sIngredientAndQuantity* ingredientsAndQuantities;
	int logicalSizeIngredientsAndQuantities;
	int physicalSizeIngredientsAndQuantities;
	Stock(const Stock& other);

public:
	Stock(const sIngredientAndQuantity* ingredientsAndQuantities = NULL, int sizeIngredientsAndQuantities = 0);	
	~Stock(){delete []ingredientsAndQuantities;}

	//Getters
	const sIngredientAndQuantity* getAllIngredientsAndtQuantities() const { return ingredientsAndQuantities; }
	const sIngredientAndQuantity& getIngredientAndQuantityByIngredientName(const char* ingredientName) const;
	sIngredientAndQuantity& getIngredientAndQuantityByIngredientName(const char* ingredientName);
	const Ingredient*& getIngredientByIngredientName(const char* ingredientName) const;
	int getSizeIngredientsAndQuantities() const { return logicalSizeIngredientsAndQuantities; }

	// Operators
	const Stock& operator++(); // For case of stock++
	const Stock& operator++(int); // For case of ++stock

	//Methods
	void addIngredient(const Ingredient* ingredient);
	void removeIngredient(const Ingredient* ingredient);
	bool isIngredientAboutToEnd(const Ingredient* ingredient) const;
	const Ingredient** getEndedIngredients() const;
	void print() const;
};

#endif // __STOCK_H

