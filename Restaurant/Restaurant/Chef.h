#ifndef __CHEF_H
#define __CHEF_H

#include "Buthcery.h"
#include "StaffManager.h"
#include "Dish.h"

class Chef : public Buthcery, StaffManager
{

public:
	// Methods
	bool approveDish(const Dish& dish);
	const Dish* inventNewDish() const;
};

#endif // __CHEF_H
