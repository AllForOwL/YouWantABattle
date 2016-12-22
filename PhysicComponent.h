#ifndef __PHYSIC_COMPONENT_H__
#define __PHYSIC_COMPONENT_H__

#include "cocos2d.h"

class ManagerComponent;

class PhysicComponent
{
public:
	enum Wounded
	{
		HERO,
		ENEMY,
		NOTHING
	};

	PhysicComponent();

	void Update(ManagerComponent& i_manager);
	bool onContactBegin(cocos2d::PhysicsContact& contact);

	~PhysicComponent();

private:
	Wounded	m_state;
};

#endif