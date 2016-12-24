#ifndef __SABER_H__
#define __SABER_H__

#include "cocos2d.h"

#include "Weapon.h"

USING_NS_CC;

using std::string;
using std::vector;

class Weapon;
class ManagerComponent;
class GameScene;

class Saber : public Weapon
{
public:
	Saber();
	Saber(const Saber& i_Saber);
	~Saber();

	//virtual void Update(ManagerComponent& i_manager, GameScene& i_gameScene);
	virtual void CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene);

private:

};

#endif 
