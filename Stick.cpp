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

/*virtual*/ void Stick::Update(ManagerComponent& i_manager)
{
	switch (m_state)
	{
		case Weapon::FIRE:
		{
			m_bullet->Update(i_manager);				

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