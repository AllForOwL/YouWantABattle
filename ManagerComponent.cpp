#include "ManagerComponent.h"
#include "Boar.h"
#include "Bowman.h"
#include "Giant.h"
#include "Knight.h"
#include "Octopus.h"
#include "Paladin.h"
#include "Wizard.h"
#include "Yeti.h"
#include "Arbalest.h"
#include "Cudgel.h"
#include "Horns.h"
#include "Saber.h"
#include "Sledgehammer.h"
#include "Stick.h"
#include "Sword.h"
#include "Tentacles.h"
#include "Bullet.h"
#include "Weapon.h"
#include "Warrior.h"
#include "HeroInputComponent.h"
#include "EnemyInputComponent.h"
#include "InputComponent.h"

const int INDEX_BOAR	= 0;
const int INDEX_BOWMAN	= 1;
const int INDEX_GIANT	= 2;
const int INDEX_KNIGHT	= 3;
const int INDEX_OCTOPUS = 4;
const int INDEX_PALADIN = 5;
const int INDEX_WIZARD	= 6;
const int INDEX_YETI	= 7;

ManagerComponent::ManagerComponent(int i_indexHero) : m_numberHero(i_indexHero)
{
	m_inputHero = new HeroInputComponent();
	m_inputEnemy = new EnemyInputComponent();
}

ManagerComponent::ManagerComponent(const ManagerComponent& i_manager)
{

}

void ManagerComponent::CreateHero()
{
	switch (m_numberHero)
	{
		case INDEX_BOAR:
		{
			m_hero = new Boar();			// бик
			m_weaponHero = new Horns();		// роги

			break;
		}
		case INDEX_BOWMAN:
		{
			m_hero = new Bowman();			// стр≥лець
			m_weaponHero = new Arbalest();	// лук

			break;
		}
		case INDEX_GIANT:
		{
			m_hero = new Giant();				// г≥гант
			m_weaponHero = new Sledgehammer();	// кувалда

			break;
		}
		case INDEX_KNIGHT:
		{
			m_hero = new Knight();				// лицар
			m_weaponHero = new Sword();			// меч

			break;
		}
		case INDEX_OCTOPUS:
		{
			m_hero = new Octopus();				// восьмин≥г
			m_weaponHero = new Tentacles();		// щупальц€

			break;
		}
		case INDEX_PALADIN:
		{
			m_hero = new Paladin();				// палад≥н		
			m_weaponHero = new Saber();			// шпага
			
			break;
		}
		case INDEX_WIZARD:
		{
			m_hero = new Wizard();				// чар≥вник
			m_weaponHero = new Stick();			// шпага

			break;
		}
		case INDEX_YETI:
		{
			m_hero = new Yeti();				// йЇт≥
			m_weaponHero = new Cudgel();		// дубина

			break;
		}
	default:
		break;
	}
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

	m_inputHero->Update(*this);
	m_inputEnemy->Update(*this);
}

ManagerComponent::~ManagerComponent()
{

}