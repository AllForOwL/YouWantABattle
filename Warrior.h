#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "cocos2d.h"

#include "GraphicComponent.h"

class ManagerComponent;

class Warrior : public GraphicComponent
{
public:
	Warrior() 
	{
		m_health = 100;
	};
	~Warrior() {};

	virtual void Update(ManagerComponent& i_manager) = 0;

protected:
	int m_health;
	int m_speed;
	int m_strength;
	int m_dexterity;
};

#endif 
