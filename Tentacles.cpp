#include "Tentacles.h"
#include "ManagerComponent.h"
#include "Bullet.h"
#include "constants.h"

Tentacles::Tentacles()
{

}

Tentacles::Tentacles(const Tentacles& i_Tentacles)
{

}

/*virtual*/ void Tentacles::Update(ManagerComponent& i_manager, GameScene& i_gameScene)
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
			m_bullet->getParent()->removeFromParentAndCleanup(true);
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

/*virtual*/ void Tentacles::Fire()
{
	m_bullet = new Bullet(BULLET_COAL);
	m_state = Weapon::FIRE;
}

Tentacles::~Tentacles()
{

}