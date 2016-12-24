#ifndef __SLEDGEHAMMER_H__
#define __SLEDGEHAMMER_H__

#include "cocos2d.h"

#include "Weapon.h"
#include "GraphicComponent.h"

USING_NS_CC;

using std::string;
using std::vector;

class Weapon;
class ManagerComponent;
class GameScene;

class Sledgehammer : public Weapon
{
public:
	Sledgehammer();
	Sledgehammer(const Sledgehammer& i_Sledgehammer);
	~Sledgehammer();

	//virtual void Update(ManagerComponent& i_manager, GameScene& i_gameScene);
	virtual void CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene);

private:

};

#endif 
