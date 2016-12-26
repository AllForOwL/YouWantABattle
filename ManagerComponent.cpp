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
#include "EnemyInputComponent.h"
#include "HeroInputComponent.h"
#include "GameScene.h"
#include "ChoiseHeroScene.h"
#include "HUDLayer.h"
#include "PhysicComponent.h"
#include "Bullet.h"

/*	Tasks on 25:12:2016
		+ giant		--- jump and hit cudgel;	// derivate way on second part
		+- octupus	--- hit tentacles;			// line down on enemy
			- delete tentacles;
		- yeti		--- throw cudgel on enemy;					// opacity or setcolor white
*/

const int INDEX_BOAR	= 0;
const int INDEX_GIANT	= 1;
const int INDEX_OCTOPUS = 2;
const int INDEX_YETI	= 3; 

const int INDEX_BOWMAN	= 0;
const int INDEX_KNIGHT	= 1;
const int INDEX_PALADIN = 2;
const int INDEX_WIZARD	= 3;


ManagerComponent::ManagerComponent(GameScene& i_gameScene, int i_indexHero) : m_numberHero(i_indexHero)
{
	m_inputHero = new HeroInputComponent();
	m_inputEnemy = new EnemyInputComponent();

	m_HUDLayer = HUDLayer::create();
	i_gameScene.addChild(m_HUDLayer);

	CreateHero(i_gameScene);
	CreateEnemy(i_gameScene);
}

ManagerComponent::ManagerComponent(const ManagerComponent& i_manager)
{

}

void ManagerComponent::CreateHero(GameScene& i_gameScene)
{
	switch (m_numberHero)
	{
		case INDEX_BOAR:
		{
			m_hero			= new Boar();			// бик
			m_weaponHero	= new Horns();		// роги

			break;
		}
		case INDEX_GIANT:
		{
			m_hero			= new Giant();				// г≥гант
			m_weaponHero	= new Sledgehammer();	// кувалда

			break;
		}
		case INDEX_OCTOPUS:
		{
			m_hero			= new Octopus();				// восьмин≥г
			m_weaponHero	= new Tentacles();		// щупальц€

			break;
		}
		case INDEX_YETI:
		{
			m_hero			= new Yeti();				// йЇт≥
			m_weaponHero	= new Cudgel();		// дубина

			break;
		}
	default:
		break;
	}

	m_hero->setPosition(m_hero->getBoundingBox().size.width, 
		m_hero->getBoundingBox().size.height);

	auto _physicBody = PhysicsBody::createBox(m_hero->getContentSize());
	_physicBody->setContactTestBitmask(true);
	_physicBody->setTag(TAG_HERO);
	m_hero->setPhysicsBody(_physicBody);

	i_gameScene.addChild(m_hero);
	i_gameScene.addChild(m_weaponHero);
}

void ManagerComponent::CreateEnemy(GameScene& i_gameScene)
{
	srand(time(0));
	m_numberHero = rand() % 3 + 0;

	switch (m_numberHero)
	{
		case INDEX_BOWMAN:
		{
			m_enemy			= new Bowman();		// стр≥лець
			m_weaponEnemy	= new Arbalest();	// лук

			break;
		}
		case INDEX_KNIGHT:
		{
			m_enemy			= new Knight();		// лицар
			m_weaponEnemy	= new Sword();		// меч

			break;
		}
		case INDEX_PALADIN:
		{
			m_enemy			= new Paladin();		// палад≥н		
			m_weaponEnemy	= new Saber();			// шпага
			
			break;
		}
		case INDEX_WIZARD:
		{
			m_enemy			= new Wizard();			// чар≥вник
			m_weaponEnemy	= new Stick();			// шпага

			break;
		}
	default:
		break;
	}

	m_enemy->setPosition(ChoiseHeroScene::m_visiblSize.width - m_enemy->getBoundingBox().size.width * 2,
		m_enemy->getBoundingBox().size.height);

	auto _physicBody = PhysicsBody::createBox(m_enemy->getContentSize());
	_physicBody->setContactTestBitmask(true);
	_physicBody->setTag(TAG_ENEMY);
	m_enemy->setPhysicsBody(_physicBody);

	i_gameScene.addChild(m_enemy);
	i_gameScene.addChild(m_weaponEnemy);
}

void ManagerComponent::Update(GameScene& i_gameScene)
{
	m_hero->Update(*this, i_gameScene);
	m_enemy->Update(*this, i_gameScene);

	m_weaponHero->Update(*this, i_gameScene);
	m_weaponEnemy->Update(*this, i_gameScene);

	m_inputHero->Update(*this);
	m_inputEnemy->Update(*this);

	m_HUDLayer->Update(*this);
}

ManagerComponent::~ManagerComponent()
{

}