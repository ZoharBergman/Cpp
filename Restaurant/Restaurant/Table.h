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

	Table(const Table& other);
	const Table& operator=(const Table& other);

public:
	Table(int maxNumOfGuests, bool isTaken);	

	// Getters
	long getId() const { return id; }
	int getMaxNumOfGuests() const { return maxNumOfGuests; }
	bool getIsTaken() const { return isTaken; }

	// Setters
	void setIsTaken(bool isTaken) {this->isTaken = isTaken;}
	void setMaxNumOfGuests(int maxNumOfGuests){ this->maxNumOfGuests = maxNumOfGuests; }
};
long Table::idCounter = 0;

#endif