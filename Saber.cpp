#include "Saber.h"
#include "constants.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Bullet.h"
#include "GameScene.h"

Saber::Saber()
{
	m_damage = DAMAGE_SABER;
}

Saber::Saber(const Saber& i_Saber)
{

}

///*virtual*/ void Saber::Update(ManagerComponent& i_manager, GameScene& i_gameScene)
//{
//}

/*virtual*/ void Saber::CreateBullet(ManagerComponent& i_manager, GameScene& i_gameScene)
{
	i_manager.m_bulletHero = new Bullet(BULLET_RUBY);
	Point _position = i_manager.m_hero->getPosition();
	_position.x += i_manager.m_hero->getBoundingBox().size.width;
	i_manager.m_bulletHero->setPosition(_position);
	i_gameScene.addChild(i_manager.m_bulletHero);
}
Saber::~Saber()
{

}