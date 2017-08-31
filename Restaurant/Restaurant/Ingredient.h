#ifndef __INGREDIENT_H
#define __INGREDIENT_H

class Ingredient
{
private:
	char* name;
	int price;
	double caloricValue; 
public:
	Ingredient(const char* name, int price, double caloricValue);
	Ingredient(const Ingredient& other) { *this = other; }
	~Ingredient() {delete []name;}

	// Getters
	const char* getName() const {return name;}
	int getPrice() const {return price;}
	double getCaloricValue() const {return caloricValue;}

	// Setters
	void setPrice(int price) {this->price = price; }

	// Operators
	const Ingredient& operator=(const Ingredient& other);
};

#endif // __INGREDIENT_H