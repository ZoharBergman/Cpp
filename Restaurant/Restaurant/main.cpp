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
int fillStock(Ingredient* ingredients, int numOfIngredients, sIngredientAndQuantity*& ingredientsAndQuantities);

void main()
{
	Employee* employees; 
	Dish* dishes;
	Stock stock;
	Ingredient* ingredients;

	// Initialize the parameters of the 'Maze' restaurant
	int numOfEmployees = initEmployees(employees);
	int numOfIngredients = initIngredients(ingredients);	
	initStock(stock, ingredients, numOfIngredients);		
	int numOfDishes = initDishes(dishes, ingredients);
	Chef chefRamsay(Buthcery(Employee("Ramsay", 20, 852, 50000)), StaffManager(employees, numOfEmployees));
	Menu menu(dishes, numOfDishes);
	
	// Define 'Maze' restaurant
	Restaurant maze("Maze", chefRamsay, menu, stock, ingredients, numOfIngredients);

	// Init the tables
	initTables(maze.getTables(), maze.MAX_NUM_TABLES);

	//-----------------------------------------------First flow-----------------------------------------------//
	// Customers come to the 'Maze' restaturant and being seat, they take a look at the menu and one of the waiters take their order, 
	// the order is being prepared by one of the butcheries and at the end the order is being printed with the final price of it
	Order order = maze.seatCustomers(5);
	maze.showMenu();
	setOrder(order);
	maze.takeOrder(order, (Waiter&)(maze.getChef().getEmployeeByEmployeeId(3)));
	maze.prepareOrder(order, (Buthcery&)(maze.getChef().getEmployeeByEmployeeId(0)));
	maze.printOrderToTable(order.getTable(), (Waiter&)(maze.getChef().getEmployeeByEmployeeId(3)));
	

	//-----------------------------------------------Second flow-----------------------------------------------//
	// Take a look at the stock and fill the ended ingredients
	maze.stocktaking();
	sIngredientAndQuantity* ingredientsAndQuantities;
	int numOfIngredientsAndQuantities = fillStock(maze.getAllIngredients(), maze.getSizeIngredients(), ingredientsAndQuantities);
	maze.fillStock(ingredientsAndQuantities, numOfIngredientsAndQuantities);
	maze.getStock()++;

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
	dishes = new Dish[numOfDishes];	

	// The classic dish
	dishes[0] = Dish(130, "Excellent beef served with creamed potatoes", "The classic");	
	sIngredientAndQuantity ingredientsAndQuantities0[3];
	ingredientsAndQuantities0[0].ingredient = &ingredients[1]; // Beef
	ingredientsAndQuantities0[0].quantity = 250;
	ingredientsAndQuantities0[1].ingredient = &ingredients[0]; // Potato
	ingredientsAndQuantities0[1].quantity = 2;
	ingredientsAndQuantities0[2].ingredient = &ingredients[8]; // Cream
	ingredientsAndQuantities0[2].quantity = 100;
	dishes[0].addIngredients(ingredientsAndQuantities0, 3);

	//	The Italian dish
	dishes[1] = Dish(60, "Great pasta with creamy tomatoes sauce", "The Italian");	
	sIngredientAndQuantity ingredientsAndQuantities1[4];
	ingredientsAndQuantities1[0].ingredient = &ingredients[7]; // Pasta
	ingredientsAndQuantities1[0].quantity = 250;
	ingredientsAndQuantities1[1].ingredient = &ingredients[5]; // Tomato
	ingredientsAndQuantities1[1].quantity = 2;
	ingredientsAndQuantities1[2].ingredient = &ingredients[8]; // Cream
	ingredientsAndQuantities1[2].quantity = 100;
	ingredientsAndQuantities1[3].ingredient = &ingredients[2]; // Cheese
	ingredientsAndQuantities1[3].quantity = 50;
	dishes[1].addIngredients(ingredientsAndQuantities1, 4);

	// Chocolate cake
	dishes[2] = Dish(42, "Hot chocolate cake", "Amazing chocolate cake");	
	sIngredientAndQuantity ingredientsAndQuantities2[4];
	ingredientsAndQuantities2[0].ingredient = &ingredients[4]; // Egg
	ingredientsAndQuantities2[0].quantity = 1;
	ingredientsAndQuantities2[1].ingredient = &ingredients[9]; // Chocolate
	ingredientsAndQuantities2[1].quantity = 100;
	ingredientsAndQuantities2[2].ingredient = &ingredients[8]; // Cream
	ingredientsAndQuantities2[2].quantity = 150;
	ingredientsAndQuantities2[3].ingredient = &ingredients[2]; // Milk	
	ingredientsAndQuantities2[3].quantity = 100;
	dishes[2].addIngredients(ingredientsAndQuantities2, 4);

	// Tomatoes salad
	dishes[3] = Dish(35, "Sliced tomatoes with cheese, served with hot bread", "Tomatoes salad");	
	sIngredientAndQuantity ingredientsAndQuantities3[3];
	ingredientsAndQuantities3[0].ingredient = &ingredients[5]; // Tomato
	ingredientsAndQuantities3[0].quantity = 2;
	ingredientsAndQuantities3[1].ingredient = &ingredients[2]; // Cheese
	ingredientsAndQuantities3[1].quantity = 70;
	ingredientsAndQuantities3[2].ingredient = &ingredients[6]; // Bread
	ingredientsAndQuantities3[2].quantity = 1;
	dishes[3].addIngredients(ingredientsAndQuantities3, 3);

	// Carpaccio
	dishes[4] = Dish(30, "Thin sliced beef with cheese", "Carpaccio");	
	sIngredientAndQuantity ingredientsAndQuantities4[2];
	ingredientsAndQuantities4[0].ingredient = &ingredients[1]; // Beef
	ingredientsAndQuantities4[0].quantity = 100;
	ingredientsAndQuantities4[1].ingredient = &ingredients[2]; // Cheese
	ingredientsAndQuantities4[2].quantity = 40;
	dishes[4].addIngredients(ingredientsAndQuantities4, 2);
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
	order.addDish(menu.getDishByName("The Italian"));
	order.addDish(menu.getDishByName("The classic"));
	order += menu.getDishByName("The classic");	
	order += menu.getDishByName("Amazing chocolate cake");
}

int fillStock(Ingredient* ingredients, int numOfIngredients, sIngredientAndQuantity*& ingredientsAndQuantities)
{
	ingredientsAndQuantities = new sIngredientAndQuantity[numOfIngredients];
	for (int i = 0; i < numOfIngredients; i++)
	{
		ingredientsAndQuantities[i].ingredient = &ingredients[i];
		ingredientsAndQuantities[i].quantity = 2;
	}

	return numOfIngredients;
}