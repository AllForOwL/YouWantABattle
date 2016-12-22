#include "Arbalest.h"
#include "ManagerComponent.h"
#include "Bullet.h"
#include "constants.h"

Arbalest::Arbalest()
{

}

Arbalest::Arbalest(const Arbalest& i_Arbalest)
{

}

/*virtual*/ void Arbalest::Update(ManagerComponent& i_manager, GameScene& i_gameScene)
{
	switch (m_state)
	{
		case Weapon::FIRE:
		{
			m_bullet->Update(i_manager, i_gameScene);				

			if (OutOfOrderWindow())
			{
				m_state = Weapon::DESTROY_BULLET;
			}

			break;
		}
		case Weapon::DESTROY_BULLET:
		{
			delete m_bullet;

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

/*virtual*/ void Arbalest::Fire()
{
	m_bullet = new Bullet(BULLET_DIAMOND);
	m_state = Weapon::FIRE;
}

Arbalest::~Arbalest()
{

}