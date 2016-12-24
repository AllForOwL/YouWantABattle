#include "PhysicComponent.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Weapon.h"
#include "constants.h"

PhysicComponent::PhysicComponent()
{
	m_state = Wounded::NOTHING;
}

void PhysicComponent::Update(ManagerComponent& i_manager)
{
	switch (m_state)
	{
		case Wounded::HERO:
		{
			i_manager.m_weaponEnemy->SetState(Weapon::State::DESTROY_BULLET);

			m_state = Wounded::NOTHING;

			break;
		}
		case Wounded::ENEMY:
		{
			i_manager.m_weaponHero->SetState(Weapon::State::DESTROY_BULLET);

			m_state = Wounded::NOTHING;

			break;
		}
		case Wounded::NOTHING:
		{
			break;
		}
	default:
		break;
	}
}

bool PhysicComponent::onContactBegin(cocos2d::PhysicsContact& contact)
{
	PhysicsBody* _a = contact.getShapeA()->getBody();
	PhysicsBody* _b = contact.getShapeB()->getBody();

	if (_a->getTag() == TAG_HERO || _b->getTag() == TAG_HERO)
	{
		m_state = Wounded::HERO;
	}
	else if (_a->getTag() == TAG_ENEMY || _b->getTag() == TAG_ENEMY)
	{
		m_state = Wounded::ENEMY;
	}
	return true;
}

PhysicComponent::~PhysicComponent()
{

}