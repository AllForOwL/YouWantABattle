#include "Sword.h"
#include "constants.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Bullet.h"
#include "GameScene.h"

Sword::Sword()
{
	m_damage = DAMAGE_SWORD;
}

Sword::Sword(const Sword& i_Sword)
{

}

///*virtual*/ void Sword::Update(ManagerComponent& i_manager, GameScene& i_gameScene)
//{
//	
//}

/*virtual*/ void Sword::CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene)
{
	i_manager.m_bulletHero = new Bullet(BULLET_RUBY);
	Point _position = i_manager.m_hero->getPosition();
	_position.x += i_manager.m_hero->getBoundingBox().size.width;
	i_manager.m_bulletHero->setPosition(_position);
	i_gameScene.addChild(i_manager.m_bulletHero);
}
Sword::~Sword()
{

}