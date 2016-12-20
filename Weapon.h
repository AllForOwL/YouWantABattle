#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"

#include "GraphicComponent.h"

class ManagerComponent;

class Weapon : public GraphicComponent
{
public:
	Weapon() {};
	~Weapon() {};

	virtual void Update(ManagerComponent& i_manager) = 0;
	virtual void Fire() = 0;
};

#endif 
