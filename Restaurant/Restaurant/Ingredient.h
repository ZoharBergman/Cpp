#ifndef __INGREDIENT_H
#define __INGREDIENT_H

class Ingredient
{
public:
	const static int MAX_NAME_SIZE = 20;
private:
	char name[MAX_NAME_SIZE];
	int price;
	double caloricValue; 

public:
	Ingredient(const char* name, int price, double caloricValue);
	Ingredient(const Ingredient& other) { *this = other; }

	// Getters
	const char* getName() const {return name;}
	int getPrice() const {return price;}
	double getCaloricValue() const {return caloricValue;}

	// Setters
	void setPrice(int price) {this->price = price; }

	// Operators
	const Ingredient& operator=(const Ingredient& other);

	// Methods
	void print() const;
};

#endif // __INGREDIENT_H