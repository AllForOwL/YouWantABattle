#include "Cudgel.h"
#include "ManagerComponent.h"
#include "Bullet.h"
#include "constants.h"

Cudgel::Cudgel()
{

}

Cudgel::Cudgel(const Cudgel& i_Cudgel)
{

}

/*virtual*/ void Cudgel::Update(ManagerComponent& i_manager)
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

/*virtual*/ void Cudgel::Fire()
{
	m_bullet = new Bullet(BULLET_ORE);
	m_state = Weapon::FIRE;
}

Cudgel::~Cudgel()
{

}