#ifndef __MANAGER_COMPONENT_H__
#define __MANAGER_COMPONENT_H__

#include "cocos2d.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;
class Weapon;
class HeroInputComponent;
class EnemyInputComponent;
class GameScene;
class HUDLayer;
class PhysicComponent;
class Bullet;

class ManagerComponent
{
public:
	ManagerComponent(GameScene& i_gameScene, int i_indexHero);
	ManagerComponent(const ManagerComponent& i_manager);
	~ManagerComponent();

	void CreateHero(GameScene& i_gameScene);
	void CreateEnemy(GameScene& i_gameScene);

	void Update(GameScene& i_gameScene);

public:
	int m_numberHero;

	Warrior*	m_hero;
	Warrior*	m_enemy;

	Weapon*	m_weaponHero;
	Weapon*	m_weaponEnemy;

	HeroInputComponent*		m_inputHero;
	EnemyInputComponent*	m_inputEnemy;

	Bullet*	m_bulletHero;
	Bullet* m_bulletEnemy;

	HUDLayer*	m_HUDLayer;
};

#endif 
