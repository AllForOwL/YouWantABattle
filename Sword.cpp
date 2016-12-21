#include "Sword.h"
#include "ManagerComponent.h"
#include "Bullet.h"
#include "constants.h"

Sword::Sword()
{

}

Sword::Sword(const Sword& i_Sword)
{

}

/*virtual*/ void Sword::Update(ManagerComponent& i_manager)
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

/*virtual*/ void Sword::Fire()
{
	m_bullet = new Bullet(BULLET_ORE);
	m_state = Weapon::FIRE;
}

Sword::~Sword()
{

}