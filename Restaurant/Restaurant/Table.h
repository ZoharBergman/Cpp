#ifndef __TABLE_H
#define __TABLE_H

class Table
{
public:
	static long idCounter;

private:
	long id;
	int maxNumOfGuests;
	bool isTaken;	

public:
	Table(int maxNumOfGuests = 0, bool isTaken = false);
	Table(const Table& other){ *this = other; }

	// Setters
	void setIsTaken(bool isTaken) {this->isTaken = isTaken;}

	// Operators
	const Table& operator=(const Table& other);
};
long Table::idCounter = 0;

#endif