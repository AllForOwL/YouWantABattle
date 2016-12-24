#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "cocos2d.h"

#include "GraphicComponent.h"
#include "ChoiseHeroScene.h"

class GraphicComponent;
class ManagerComponent;

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
		SET_DAMAGE,
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
			case Warrior::SET_DAMAGE:
			{
				int _damage = 0;
				if (this->getPhysicsBody()->getTag() == TAG_HERO)
				{
					_damage += i_manager.m_bulletEnemy->GetDamage() + i_manager.m_weaponEnemy->GetDamage();
				}
				else
				{
					_damage += i_manager.m_bulletHero->GetDamage() + i_manager.m_weaponHero->GetDamage();
				}

				m_health -= _damage;

				m_state = Warrior::NOTHING;

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

	//int GetDamage(ManagerComponent& i_manager)
	//{
	//	int _damage = this->m_damage;
	//	if (this->getPhysicsBody()->getTag() == TAG_HERO)
	//	{
	//		_damage += i_manager.m_bulletHero->GetDamage() + i_manager.m_weaponHero->GetDamage();
	//	}
	//	else
	//	{
	//		_damage += i_manager.m_bulletEnemy->GetDamage() + i_manager.m_weaponEnemy->GetDamage();
	//	}

	//	return _damage;
	//}

protected:
	State	m_state;

	int m_startPositionY;

	int m_damage;
	int m_health;
	int m_speed;
	int m_strength;
	int m_dexterity;
	int m_heightJump;
};

#endif 
