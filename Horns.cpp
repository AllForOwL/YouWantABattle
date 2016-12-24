#include "Horns.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Bullet.h"
#include "GameScene.h"

Horns::Horns()
{
	m_damage = DAMAGE_HORNS;
}

Horns::Horns(const Horns& i_Horns)
{

}

///*virtual*/ void Horns::Update(ManagerComponent& i_manager, GameScene& i_gameScene)
//{
//
//}

/*virtual*/ void Horns::CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene)
{
	i_manager.m_bulletHero = new Bullet(BULLET_RUBY);
	Point _position = i_manager.m_hero->getPosition();
	_position.x += i_manager.m_hero->getBoundingBox().size.width;
	i_manager.m_bulletHero->setPosition(_position);
	i_gameScene.addChild(i_manager.m_bulletHero);
}

Horns::~Horns()
{

}