#include <iostream>
using namespace std;

#include "Restaurant.h"

// Methods signatures
int initEmployees(Employee*& employees);
int initDishes(Dish*& dishes, Ingredient*& ingredients);
void initStock(Stock& stock, Ingredient*& ingredients, int numOfIngredients);
void initTables(Table* tables, const int numOfTables);
int initIngredients(Ingredient*& ingredients);
void setOrder(Order& order);

void main()
{
	Employee* employees; 
	Dish* dishes;
	Stock stock;
	//Table* tables;
	Ingredient* ingredients;

	// Initialize the parameters of the 'Maze' restaurant
	int numOfEmployees = initEmployees(employees);
	int numOfIngredients = initIngredients(ingredients);	
	initStock(stock, ingredients, numOfIngredients);		
	int numOfDishes = initDishes(dishes, ingredients);
	Chef chefRamsay(Buthcery(Employee("ramsay", 20, 852, 50000)), StaffManager(employees, numOfEmployees));
	Menu menu(dishes, numOfDishes);
	
	// Define 'Maze' restaurant
	Restaurant maze("Maze", chefRamsay, menu, stock, ingredients, numOfIngredients);

	// Init the tables
	initTables(maze.getTables(), maze.MAX_NUM_TABLES);

	//-----------------------------------------------First flow-----------------------------------------------//
	// Customers come to the 'Maze' restaturant and being seat, they take a look at the menu and one of the waiters take their order, 
	// the order is being prepared by one of the butcheries and at the end the order is being printed with the final price of it
	Order order = maze.sitCustomers(5);
	maze.getMenu().print();
	setOrder(order);
	maze.takeOrder(order, (Waiter&)(maze.getChef().getEmployeeByEmployeeId(3)));
	maze.prepareOrder(order, (Buthcery&)(maze.getChef().getEmployeeByEmployeeId(0)));
	maze.printOrderToTable(order.getTable(), (Waiter&)(maze.getChef().getEmployeeByEmployeeId(3)));
	

	//-----------------------------------------------Second flow-----------------------------------------------//
	// Take a look at the stock and fill the ended ingredients
	maze.stocktaking();
	//maze.fillStock(

	//-----------------------------------------------Third flow-----------------------------------------------//
	// Chef Ramsay invent new dish, that is being added to the menu
	maze.addDishToMenu(chefRamsay.inventNewDish());
}

int initEmployees(Employee*& employees)
{
	int numOfEmployees = 4;
	employees = new Employee[numOfEmployees];
	employees[0] = Buthcery(Employee("Ben", 2, 456, 1500));
	employees[1] = Buthcery(Employee("Maya", 4, 741, 4500));
	employees[2] = Waiter(Employee("Charlie", 1, 123, 1000));
	employees[3] = Waiter(Employee("Adam", 3, 789, 2000));

	return numOfEmployees;
}

int initDishes(Dish*& dishes, Ingredient*& ingredients)
{
	int numOfDishes = 5;
	//dishes = new Dish[numOfDishes];
	//sIngredientAndQuantity s;
	//s.ingredient = new Ingredient*[3];
	//s.ingredient[0] = &(stock.getIngredientByIngredientName("Potato"));
	////dishes[0] = Dish(30, "Excellent beef served with creamed potatoes", "The classic", , );
	return numOfDishes;
}

void initStock(Stock& stock, Ingredient*& ingredients, int numOfIngredients)
{
	for (int i = 0; i < numOfIngredients; i++)
	{
		Ingredient* pIngredient = &(ingredients[i]);
		stock.addIngredient(pIngredient);
		stock.addIngredient(pIngredient);
		stock.addIngredient(pIngredient);
		stock.addIngredient(pIngredient);
	}	
}

void initTables(Table* tables, const int numOfTables)
{
	for (int i = 0; i < numOfTables; i+=2)
	{
		tables[i].setMaxNumOfGuests(i + 2);
		tables[i + 1].setMaxNumOfGuests(i + 2);
	}
}

int initIngredients(Ingredient*& ingredients)
{
	int numOfIngredients = 10;
	ingredients = new Ingredient[numOfIngredients];
	ingredients[0] = Ingredient("Potato", 4, 20);
	ingredients[1] = Ingredient("Beef", 12, 50);
	ingredients[2] = Ingredient("Cheese", 3, 15);
	ingredients[3] = Ingredient("Milk", 2, 10);
	ingredients[4] = Ingredient("Egg", 1, 11);
	ingredients[5] = Ingredient("Tomato", 1, 10);
	ingredients[6] = Ingredient("Bread", 4, 30);
	ingredients[7] = Ingredient("Pasta", 5, 40);
	ingredients[8] = Ingredient("Cream", 6, 35);
	ingredients[9] = Ingredient("Chocolate", 7, 32);
	return numOfIngredients;
}

void setOrder(Order& order, Menu& menu)
{
	order.addDish(menu.getDishByName("The classic"));
	order.addDish(menu.getDishByName("The classic"));
	order.addDish(menu.getDishByName("The Italian"));
	order.addDish(menu.getDishByName("Amazing chocolate cake"));
}