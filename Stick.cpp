#include "Stick.h"
#include "constants.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Bullet.h"
#include "GameScene.h"

Stick::Stick()
{
	m_damage = DAMAGE_STICK;
}

Stick::Stick(const Stick& i_Stick)
{

}

///*virtual*/ void Stick::Update(ManagerComponent& i_manager, GameScene& i_gameScene)
//{
//	
//}

/*virtual*/ void Stick::CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene)
{
	i_manager.m_bulletHero = new Bullet(BULLET_RUBY);
	Point _position = i_manager.m_hero->getPosition();
	_position.x += i_manager.m_hero->getBoundingBox().size.width;
	i_manager.m_bulletHero->setPosition(_position);
	i_gameScene.addChild(i_manager.m_bulletHero);
}

Stick::~Stick()
{

}