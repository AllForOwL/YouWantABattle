#include "Sledgehammer.h"
#include "constants.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Bullet.h"
#include "GameScene.h"

Sledgehammer::Sledgehammer()
{
	m_damage = DAMAGE_SLEDGEHAAMMER;
}

Sledgehammer::Sledgehammer(const Sledgehammer& i_Sledgehammer)
{

}

///*virtual*/ void Sledgehammer::Update(ManagerComponent& i_manager, GameScene& i_gameScene)
//{
//	
//}

/*virtual*/ void Sledgehammer::CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene)
{
	i_manager.m_bulletHero = new Bullet(BULLET_RUBY);
	Point _position = i_manager.m_hero->getPosition();
	_position.x += i_manager.m_hero->getBoundingBox().size.width;
	i_manager.m_bulletHero->setPosition(_position);
	i_gameScene.addChild(i_manager.m_bulletHero);
}

Sledgehammer::~Sledgehammer()
{

}