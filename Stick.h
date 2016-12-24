#ifndef __STICK_H__
#define __STICK_H__

#include "cocos2d.h"

#include "Weapon.h"

USING_NS_CC;

using std::string;
using std::vector;

class Weapon;
class ManagerComponent;
class GameScene;

class Stick : public Weapon
{
public:
	Stick();
	Stick(const Stick& i_Stick);
	~Stick();

	//virtual void Update(ManagerComponent& i_manager, GameScene& i_gameScene);
	virtual void CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene);

private:

};

#endif 
