#ifndef __MANAGER_COMPONENT_H__
#define __MANAGER_COMPONENT_H__

#include "cocos2d.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;
class Weapon;
class InputComponent;
class GameScene;

class ManagerComponent
{
public:
	ManagerComponent(GameScene& i_gameScene, int i_indexHero);
	ManagerComponent(const ManagerComponent& i_manager);
	~ManagerComponent();

	void CreateHero(GameScene& i_gameScene);
	void CreateEnemy(GameScene& i_gameScene);

	void Update();

public:
	int m_numberHero;

	Warrior*	m_hero;
	Warrior*	m_enemy;

	Weapon*	m_weaponHero;
	Weapon*	m_weaponEnemy;

	InputComponent*		m_inputHero;
	InputComponent*		m_inputEnemy;
};

#endif 
