#include "Bullet.h"
#include "ManagerComponent.h"
#include "constants.h"


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
}

/*virtual*/ void Bullet::Update(ManagerComponent& i_manager)
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
}

int Bullet::GetDamage() const
{
	return m_damage;
}

Bullet::~Bullet()
{

}