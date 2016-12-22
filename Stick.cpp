#include "Stick.h"
#include "ManagerComponent.h"
#include "Bullet.h"
#include "constants.h"

Stick::Stick()
{

}

Stick::Stick(const Stick& i_Stick)
{

}

/*virtual*/ void Stick::Update(ManagerComponent& i_manager, GameScene& i_gameScene)
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

/*virtual*/ void Stick::Fire()
{
	m_bullet = new Bullet(BULLET_RUBY);
	m_state = Weapon::FIRE;
}

Stick::~Stick()
{

}