#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "cocos2d.h"

#include "GraphicComponent.h"
#include "ChoiseHeroScene.h"
#include "Bullet.h"
#include "ManagerComponent.h"
#include "Weapon.h"

class Warrior : public GraphicComponent
{
public:

	enum State
	{
		JUMP,
		CROUCH,
		MOVE_LEFT,
		MOVE_RIGHT,
		FIRE,
		NOTHING
	};

	Warrior() 
	{
		m_state = State::NOTHING;
		m_health = 100;
		m_startPositionY = 0;
	};
	~Warrior() {};

	virtual void Update(ManagerComponent& i_manager)
	{
		switch (m_state)
		{
			case Warrior::JUMP:
			{
				this->setPositionY(this->getPositionY() + m_heightJump);

				m_state = State::NOTHING;

				break;
			}
			case Warrior::CROUCH:
			{
				this->setPositionY(this->getPositionY() - m_heightJump);

				m_state = State::NOTHING;

				break;
			}
			case Warrior::MOVE_LEFT:
			{
				if (this->getPositionX() >= m_speed)
				{
					this->setPositionX(this->getPositionX() - m_speed);
				}

				m_state = State::NOTHING;

				break;
			}
			case Warrior::MOVE_RIGHT:
			{
				if (this->getPositionX() + m_speed < ChoiseHeroScene::m_visiblSize.width)
				{
					this->setPositionX(this->getPositionX() + m_speed);
				}

				m_state = State::NOTHING;

				break;
			}
			case Warrior::FIRE:
			{
				i_manager.m_weaponHero->Fire();

				m_state = State::NOTHING;

				break;
			}
			case Warrior::NOTHING:
			{
				if (!m_startPositionY)
				{
					m_startPositionY = this->getPositionY();
				}

				if (this->getPositionY() != m_startPositionY)
				{
					this->setPositionY(m_startPositionY);
				}

				break;
			}
			default:
				break;
		}
	}

	void SetState(State i_state)
	{
		m_state = i_state;
	}

	void SetDamage(int i_damage)
	{
		m_health -= i_damage;
	}

protected:
	State	m_state;

	int m_startPositionY;

	int m_health;
	int m_speed;
	int m_strength;
	int m_dexterity;
	int m_heightJump;
};

#endif 
