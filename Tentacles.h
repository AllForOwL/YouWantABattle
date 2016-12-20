#ifndef __Tentacles_H__
#define __Tentacles_H__

#include "cocos2d.h"

#include "Weapon.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Tentacles : public Weapon
{
public:
	Tentacles();
	Tentacles(const Tentacles& i_Tentacles);
	~Tentacles();

	virtual void Update(ManagerComponent& i_manager);
	virtual void Fire();

private:
};

#endif 
