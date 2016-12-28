#include "ManagerComponent.h"
#include "AdventureGirl.h"
#include "Boy.h"
#include "NinjaGirl.h"
#include "Knight.h"
#include "Crocodile.h"
#include "Robot.h"
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
*/

const int INDEX_ADVENTURE_GIRL	= 0;
const int INDEX_BOY				= 1;
const int INDEX_CROCODILE		= 2;
const int INDEX_KNIGHT			= 3;
const int INDEX_NINJA_GIRL		= 4;
const int INDEX_ROBOT			= 5;


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
		case INDEX_ADVENTURE_GIRL:
		{
			m_hero = new AdventureGirl();			

			break;
		}
		case INDEX_BOY:
		{
			m_hero	= new Boy();				

			break;
		}
		case INDEX_CROCODILE:
		{
			m_hero	= new Crocodile();				

			break;
		}
		case INDEX_KNIGHT:
		{
			m_hero	= new Knight();				

			break;
		}
		case INDEX_NINJA_GIRL:
		{
			m_hero = new NinjaGirl();

			break;
		}
		case INDEX_ROBOT:
		{
			m_hero = new Robot();				
							
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
	//i_gameScene.addChild(m_weaponHero);
}

void ManagerComponent::CreateEnemy(GameScene& i_gameScene)
{
	srand(time(0));
	m_numberHero = /*rand() % 3 + */0;

	switch (m_numberHero)
	{
		case INDEX_ADVENTURE_GIRL:
		{
			m_enemy = new AdventureGirl();			

			break;
		}
		case INDEX_BOY:
		{
			m_enemy	= new Boy();				

			break;
		}
		case INDEX_CROCODILE:
		{
			m_enemy	= new Crocodile();				

			break;
		}
		case INDEX_KNIGHT:
		{
			m_enemy	= new Knight();				

			break;
		}
		case INDEX_NINJA_GIRL:
		{
			m_enemy = new NinjaGirl();

			break;
		}
		case INDEX_ROBOT:
		{
			m_enemy = new Robot();				
							
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
//	i_gameScene.addChild(m_weaponEnemy);
}

void ManagerComponent::Update(GameScene& i_gameScene)
{
	m_hero->Update(*this, i_gameScene);
	m_enemy->Update(*this, i_gameScene);

	//m_weaponHero->Update(*this, i_gameScene);
	//m_weaponEnemy->Update(*this, i_gameScene);

	m_inputHero->Update(*this);
	m_inputEnemy->Update(*this);

	m_HUDLayer->Update(*this);
}

ManagerComponent::~ManagerComponent()
{

}