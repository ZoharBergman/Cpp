#ifndef __Restaurant_H
#define __Restaurant_H

#include "Table.h"
#include "Chef.h"
#include "Menu.h"
#include "Stock.h"
#include "Table.h"
#include "Ingredient.h"
#include "Order.h"
#include "Waiter.h"

class Restaurant
{
public:
	const static int MAX_NUM_TABLES = 30;
private:
	char* name;
	Chef theChef;
	Menu menu;
	Stock stock;
	Table tables[MAX_NUM_TABLES];
	Ingredient* ingredients;

public:
	Restaurant(const char* name, const Chef& chef, const Menu& menu, const Stock& stock, const Table* tables, const Ingredient* ingredients);
	~Restaurant(){delete []tables; delete []ingredients; delete []name;};
	Restaurant(const Restaurant& other) = delete;

	// Getters
	const char* getName() const {return name;}
	const Chef& getChef() const {return theChef;}
	const Menu& getMenu() const {return menu;}
	const Stock& getStock() const {return stock;}
	const Table* getTables() const {return tables;}
	const Ingredient* getIngredients() {return ingredients;}

	// Setters
	void setTheChef(const Chef& chef){this->theChef = chef;}

	// Operators


	// Methods
	const Table* sitCustomers(int size);
	void takeOrder(const Order& order, const Waiter& waiter);
	void addDishToMenu(const Dish* dish);
	void prepareOrder(const Order& order, const Buthcery& butchery);
	void stocktaking() const {stock.print();}
	void fillStock(const sIngredientAndQuantity* ingredientsAndQuantities);
	void printOrderToTable(const Table& table, const Waiter& waiter) const;
};

#endif // __Restaurant_H