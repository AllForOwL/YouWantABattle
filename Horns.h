#ifndef __HORNS_H__
#define __HORNS_H__

#include "cocos2d.h"

#include "Weapon.h"

USING_NS_CC;

using std::string;
using std::vector;

class Weapon;
class ManagerComponent;
class GameScene;

class Horns : public Weapon
{
public:
	Horns();
	Horns(const Horns& i_Horns);
	~Horns();

	//virtual void Update(ManagerComponent& i_manager, GameScene& i_gameScene);
	virtual void CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene);

private:
};

#endif 
