#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"

#include "GraphicComponent.h"
#include "ManagerComponent.h"
#include "ChoiseHeroScene.h"
#include "Bullet.h"
#include "GameScene.h"

const int DAMAGE_ARBALEST		= 20;
const int DAMAGE_Crocodile			= 20;
const int DAMAGE_Robot			= 20;
const int DAMAGE_SABER			= 20;
const int DAMAGE_SLEDGEHAAMMER	= 20;
const int DAMAGE_STICK			= 20;
const int DAMAGE_SWORD			= 20;
const int DAMAGE_TENTACLES		= 20;

class GraphicComponent;
class ManagerComponent;
class GameScene;
class ChoiseHeroScene;

class Weapon : public GraphicComponent
{
public:

	enum State
	{
		FIRE,
		UPDATE_BULLET,
		CREATE_BULLET,
		DESTROY_BULLET,
		NOTHING
	};

	Weapon() 
	{
		m_state = State::NOTHING;
	};

	~Weapon() 
	{

	};

	virtual void Update(ManagerComponent& i_manager, GameScene& i_gameScene)
	{
		switch (m_state)
		{
			case Weapon::CREATE_BULLET:
			{
				CreateBullet(i_manager, i_gameScene);

				m_state = Weapon::UPDATE_BULLET;

				break;
			}
			case Weapon::UPDATE_BULLET:
			{
				i_manager.m_bulletHero->Update();

				if (OutOfOrderWindow(i_manager))
				{
					m_state = Weapon::DESTROY_BULLET;
				}

				break;
			}
			case Weapon::DESTROY_BULLET:
			{
				i_manager.m_bulletHero->getPhysicsBody()->removeFromWorld();
				i_gameScene.removeChild(i_manager.m_bulletHero);

				delete i_manager.m_bulletHero;

				m_state = Weapon::State::NOTHING;

				break;
			}
			case Weapon::NOTHING:
			{

				break;
			}
			default:
				break;
		}
	}

	virtual void CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene) = 0;

	bool OutOfOrderWindow(ManagerComponent& i_manager)
	{
		if (i_manager.m_bulletHero->getPositionX() > ChoiseHeroScene::m_visiblSize.width)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void SetState(State i_state)
	{
		if (i_state == State::CREATE_BULLET && m_state == State::UPDATE_BULLET)
		{
			return;
		}
		else
		{
			m_state = i_state;
		}
	}

	int GetDamage() const
	{
		return m_damage;
	}

protected:
	int m_damage;
	State	m_state;
};

#endif 
