#ifndef __CHEF_H
#define __CHEF_H

#include "Buthcery.h"
#include "StaffManager.h"
#include "Dish.h"

class Chef : public Buthcery, StaffManager
{

public:
	Chef(const Buthcery& buthcery, const StaffManager& staffManager);

	// Methods
	bool approveDish(const Dish& dish) const;
	const Dish& inventNewDish() const; // The returned dish must be allocated dynamicly
};

#endif // __CHEF_H
