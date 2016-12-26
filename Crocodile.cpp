#include "Cudgel.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Bullet.h"
#include "GameScene.h"

Cudgel::Cudgel()
{
	m_damage = DAMAGE_CUDGEL;
}

Cudgel::Cudgel(const Cudgel& i_Cudgel)
{

}

///*virtual*/ void Cudgel::Update(ManagerComponent& i_manager, GameScene& i_gameScene)
//{
//
//}

/*virtual*/ void Cudgel::CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene)
{
	i_manager.m_bulletHero = new Bullet(BULLET_RUBY);
	Point _position = i_manager.m_hero->getPosition();
	_position.x += i_manager.m_hero->getBoundingBox().size.width;
	i_manager.m_bulletHero->setPosition(_position);
	i_gameScene.addChild(i_manager.m_bulletHero);
}

Cudgel::~Cudgel()
{

}