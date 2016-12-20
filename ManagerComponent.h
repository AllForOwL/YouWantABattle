#ifndef __MANAGER_COMPONENT_H__
#define __MANAGER_COMPONENT_H__

#include "cocos2d.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;
class Weapon;
class Bullet;
class InputComponent;

class ManagerComponent
{
public:
	ManagerComponent(int i_indexHero);
	ManagerComponent(const ManagerComponent& i_manager);
	~ManagerComponent();

	void CreateHero();
	void CreateEnemy();

	void Update();

private:
	int m_numberHero;

	Warrior*	m_hero;
	Warrior*	m_enemy;

	Weapon*	m_weaponHero;
	Weapon*	m_weaponEnemy;

	Bullet*	m_bulletHero;
	Bullet*	m_bulletEnemy;

	InputComponent*		m_inputHero;
	InputComponent*		m_inputEnemy;
};

#endif 
