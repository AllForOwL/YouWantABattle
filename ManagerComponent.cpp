#include "ManagerComponent.h"
#include "GraphicComponent.h"
#include "InputComponent.h"

ManagerComponent::ManagerComponent(int i_indexHero) : m_numberHero(i_indexHero)
{
	
}

ManagerComponent::ManagerComponent(const ManagerComponent& i_manager)
{

}

void ManagerComponent::CreateHero()
{

}

void ManagerComponent::CreateEnemy()
{

}

void ManagerComponent::Update()
{
	m_hero->Update(*this);
	m_enemy->Update(*this);

	m_inputHero->Update(*this);
	m_inputEnemy->Update(*this);
}

ManagerComponent::~ManagerComponent()
{

}