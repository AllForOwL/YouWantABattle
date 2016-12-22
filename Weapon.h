#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"

#include "GraphicComponent.h"
#include "Bullet.h"
#include "ChoiseHeroScene.h"

class ManagerComponent;


class Weapon : public GraphicComponent
{
public:

	enum State
	{
		FIRE,
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

	virtual void Update(ManagerComponent& i_manager, GameScene& i_gameScene) = 0;
	virtual void Fire() = 0;

	bool OutOfOrderWindow()
	{
		if (m_bullet->getPositionX() > ChoiseHeroScene::m_visiblSize.width)
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
		m_state = i_state;
	}

	int GetDamage() const
	{
		return m_bullet->GetDamage();
	}

protected:
	Bullet*	m_bullet;
	State	m_state;
};

#endif 
