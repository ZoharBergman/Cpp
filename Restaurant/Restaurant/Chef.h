#ifndef __CHEF_H
#define __CHEF_H

class Chef : public Buthcery, staffManager
{

public:
	// Methods
	bool approveDish(const Dish &dish);
	const Dish* inventNewDish() const;
};

#endif // __CHEF_H
