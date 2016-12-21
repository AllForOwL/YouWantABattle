#include "Sledgehammer.h"
#include "ManagerComponent.h"
#include "Bullet.h"
#include "constants.h"

Sledgehammer::Sledgehammer()
{

}

Sledgehammer::Sledgehammer(const Sledgehammer& i_Sledgehammer)
{

}

/*virtual*/ void Sledgehammer::Update(ManagerComponent& i_manager)
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

/*virtual*/ void Sledgehammer::Fire()
{
	m_bullet = new Bullet(BULLET_ONYX);
	m_state = Weapon::FIRE;
}

Sledgehammer::~Sledgehammer()
{

}