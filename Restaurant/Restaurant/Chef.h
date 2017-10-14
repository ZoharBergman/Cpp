#ifndef __CHEF_H
#define __CHEF_H

#include "Buthcery.h"
#include "StaffManager.h"
#include "Dish.h"

class Chef : public Buthcery, public StaffManager
{
private:
	Chef(const Chef& other);
	const Chef& operator=(const Chef& other);

public:
	Chef(const char* name, int seniority, long bankAccountID, int salary);

	// Methods
	bool approveDish(const Dish& dish) const;
	const Dish& inventNewDish() const; // The returned dish must be allocated dynamicly
};

#endif // __CHEF_H
