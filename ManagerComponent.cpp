#include "ManagerComponent.h"
#include "Warrior.h"
#include "Weapon.h"
#include "Bullet.h"
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

	m_weaponHero->Update(*this);
	m_weaponEnemy->Update(*this);

	m_bulletHero->Update(*this);
	m_bulletEnemy->Update(*this);
	
	m_inputHero->Update(*this);
	m_inputEnemy->Update(*this);
}

ManagerComponent::~ManagerComponent()
{

}