#ifndef __CUDGEL_H__
#define __CUDGEL_H__

#include "cocos2d.h"

#include "Weapon.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Cudgel : public Weapon
{
public:
	Cudgel();
	Cudgel(const Cudgel& i_Cudgel);
	~Cudgel();

	virtual void Update(ManagerComponent& i_manager, GameScene& i_gameScene);
	virtual void Fire();

private:

};

#endif 
