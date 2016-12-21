#include "Horns.h"
#include "ManagerComponent.h"
#include "Bullet.h"
#include "constants.h"

Horns::Horns()
{

}

Horns::Horns(const Horns& i_Horns)
{

}

/*virtual*/ void Horns::Update(ManagerComponent& i_manager)
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

/*virtual*/ void Horns::Fire()
{
	m_bullet = new Bullet(BULLET_RUBY);
	m_state = Weapon::FIRE;
}

Horns::~Horns()
{

}