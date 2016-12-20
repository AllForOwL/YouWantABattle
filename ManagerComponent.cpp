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
#include "GameScene.h"
#include "ChoiseHeroScene.h"

const int INDEX_BOAR	= 0;
const int INDEX_BOWMAN	= 1;
const int INDEX_GIANT	= 2;
const int INDEX_KNIGHT	= 3;
const int INDEX_OCTOPUS = 4;
const int INDEX_PALADIN = 5;
const int INDEX_WIZARD	= 6;
const int INDEX_YETI	= 7;

ManagerComponent::ManagerComponent(GameScene& i_gameScene, int i_indexHero) : m_numberHero(i_indexHero)
{
	m_inputHero = new HeroInputComponent();
	m_inputEnemy = new EnemyInputComponent();

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
			m_hero = new Boar();			// ���
			m_weaponHero = new Horns();		// ����

			break;
		}
		case INDEX_BOWMAN:
		{
			m_hero = new Bowman();			// �������
			m_weaponHero = new Arbalest();	// ���

			break;
		}
		case INDEX_GIANT:
		{
			m_hero = new Giant();				// �����
			m_weaponHero = new Sledgehammer();	// �������

			break;
		}
		case INDEX_KNIGHT:
		{
			m_hero = new Knight();				// �����
			m_weaponHero = new Sword();			// ���

			break;
		}
		case INDEX_OCTOPUS:
		{
			m_hero = new Octopus();				// ��������
			m_weaponHero = new Tentacles();		// ��������

			break;
		}
		case INDEX_PALADIN:
		{
			m_hero = new Paladin();				// ������		
			m_weaponHero = new Saber();			// �����
			
			break;
		}
		case INDEX_WIZARD:
		{
			m_hero = new Wizard();				// �������
			m_weaponHero = new Stick();			// �����

			break;
		}
		case INDEX_YETI:
		{
			m_hero = new Yeti();				// ��
			m_weaponHero = new Cudgel();		// ������

			break;
		}
	default:
		break;
	}

	m_hero->setPosition(m_hero->getBoundingBox().size.width, 
		m_hero->getBoundingBox().size.height);

	i_gameScene.addChild(m_hero);
	i_gameScene.addChild(m_weaponHero);
}

void ManagerComponent::CreateEnemy(GameScene& i_gameScene)
{
	srand(time(0));
	m_numberHero = rand() % 7 + 0;

	switch (m_numberHero)
	{
		case INDEX_BOAR:
		{
			m_enemy			= new Boar();			// ���
			m_weaponEnemy	= new Horns();		// ����

			break;
		}
		case INDEX_BOWMAN:
		{
			m_enemy			= new Bowman();			// �������
			m_weaponEnemy	= new Arbalest();	// ���

			break;
		}
		case INDEX_GIANT:
		{
			m_enemy			= new Giant();				// �����
			m_weaponEnemy	= new Sledgehammer();	// �������

			break;
		}
		case INDEX_KNIGHT:
		{
			m_enemy			= new Knight();				// �����
			m_weaponEnemy	= new Sword();			// ���

			break;
		}
		case INDEX_OCTOPUS:
		{
			m_enemy			= new Octopus();				// ��������
			m_weaponEnemy	= new Tentacles();		// ��������

			break;
		}
		case INDEX_PALADIN:
		{
			m_enemy			= new Paladin();				// ������		
			m_weaponEnemy	= new Saber();			// �����
			
			break;
		}
		case INDEX_WIZARD:
		{
			m_enemy			= new Wizard();				// �������
			m_weaponEnemy	= new Stick();			// �����

			break;
		}
		case INDEX_YETI:
		{
			m_enemy			= new Yeti();				// ��
			m_weaponEnemy	= new Cudgel();		// ������

			break;
		}
	default:
		break;
	}

	m_enemy->setPosition(ChoiseHeroScene::m_visiblSize.width - m_enemy->getBoundingBox().size.width,
		m_enemy->getBoundingBox().size.height);

	i_gameScene.addChild(m_enemy);
	i_gameScene.addChild(m_weaponEnemy);
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