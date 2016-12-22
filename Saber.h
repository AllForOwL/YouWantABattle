#ifndef __SABER_H__
#define __SABER_H__

#include "cocos2d.h"

#include "Weapon.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Saber : public Weapon
{
public:
	Saber();
	Saber(const Saber& i_Saber);
	~Saber();

	virtual void Update(ManagerComponent& i_manager, GameScene& i_gameScene);
	virtual void Fire();

private:

};

#endif 
