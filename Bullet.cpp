#include "Bullet.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

const int SPEED_COAL	= 5;
const int SPEED_DIAMOND = 5;
const int SPEED_ONYX	= 4;
const int SPEED_ORE		= 6;
const int SPEED_RUBY	= 5;

const int DAMAGE_COAL		= 10;
const int DAMAGE_DIAMOND	= 15;
const int DAMAGE_ONYX		= 20;
const int DAMAGE_ORE		= 20;
const int DAMAGE_RUBY		= 40;

Bullet::Bullet()
{

}

Bullet::Bullet(const Bullet& i_bullet)
{

}

Bullet::Bullet(int i_type)
{
	m_type = i_type;
	SetImage();
	this->setPosition(Point::ZERO);

	auto _physicBody = PhysicsBody::createBox(this->getContentSize());
	_physicBody->setContactTestBitmask(true);
	this->setPhysicsBody(_physicBody);
}

void Bullet::Update()
{
	this->setPositionX(this->getPositionX() + m_speed);
}

void Bullet::SetImage()
{
	switch (m_type)
	{
		case BULLET_COAL:
		{
			this->initWithFile(PATH_TO_RESOURCES + "/Bullets/Coal.png");
			this->m_speed = SPEED_COAL;
			this->m_damage = DAMAGE_COAL;

			break;
		}
		case BULLET_DIAMOND:
		{
			this->initWithFile(PATH_TO_RESOURCES + "/Bullets/Diamond.png");
			this->m_speed = SPEED_DIAMOND;
			this->m_damage = DAMAGE_DIAMOND;

			break;
		}
		case BULLET_ONYX:
		{
			this->initWithFile(PATH_TO_RESOURCES + "/Bullets/Onyx.png");
			this->m_speed = SPEED_ONYX;
			this->m_damage = DAMAGE_ONYX;

			break;
		}
		case BULLET_ORE:
		{
			this->initWithFile(PATH_TO_RESOURCES + "/Bullets/Ore.png");
			this->m_speed = SPEED_ORE;
			this->m_damage = DAMAGE_ORE;

			break;
		}
		case BULLET_RUBY:
		{
			this->initWithFile(PATH_TO_RESOURCES + "/Bullets/Ruby.png");
			this->m_speed = SPEED_RUBY;
			this->m_damage = DAMAGE_RUBY;

			break;
		}

	default:
		break;
	}

	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / 20,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / 20);
}

int Bullet::GetDamage() const
{
	return m_damage;
}

Bullet::~Bullet()
{

}