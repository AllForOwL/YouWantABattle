#ifndef __ARBALEST_H__
#define __ARBALEST_H__

#include "cocos2d.h"

#include "Weapon.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;
class Bullet;

class Arbalest : public Weapon
{
public:
	Arbalest();
	Arbalest(const Arbalest& i_Arbalest);
	~Arbalest();

	virtual void Update(ManagerComponent& i_manager);
	virtual void Fire();

private:
};

#endif 
