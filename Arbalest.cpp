#include "Arbalest.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Bullet.h"
#include "GameScene.h"

Arbalest::Arbalest()
{
	m_damage = DAMAGE_ARBALEST;
}

Arbalest::Arbalest(const Arbalest& i_Arbalest)
{

}

///*virtual*/ void Arbalest::Update(ManagerComponent& i_manager, GameScene& i_gameScene)
//{
//
//}

/*virtual*/ void Arbalest::CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene)
{
	i_manager.m_bulletHero = new Bullet(BULLET_RUBY);
	Point _position = i_manager.m_hero->getPosition();
	_position.x += i_manager.m_hero->getBoundingBox().size.width;
	i_manager.m_bulletHero->setPosition(_position);
	i_gameScene.addChild(i_manager.m_bulletHero);
}

Arbalest::~Arbalest()
{

}