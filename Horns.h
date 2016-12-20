#ifndef __Horns_H__
#define __Horns_H__

#include "cocos2d.h"

#include "Weapon.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Horns : public Weapon
{
public:
	Horns();
	Horns(const Horns& i_Horns);
	~Horns();

	virtual void Update(ManagerComponent& i_manager);

private:
};

#endif 
