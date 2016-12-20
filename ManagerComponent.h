#ifndef __MANAGER_COMPONENT_H__
#define __MANAGER_COMPONENT_H__

#include "cocos2d.h"

USING_NS_CC;

using std::string;
using std::vector;

class GraphicComponent;
class InputComponent;

class ManagerComponent
{
public:
	ManagerComponent(int i_indexHero);
	ManagerComponent(const ManagerComponent& i_manager);
	~ManagerComponent();

	void CreateHero();
	void CreateEnemy();

	void Update();

private:
	int m_numberHero;

	GraphicComponent*	m_hero;
	GraphicComponent*	m_enemy;

	InputComponent*		m_inputHero;
	InputComponent*		m_inputEnemy;
};

#endif 
