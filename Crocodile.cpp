#include "Crocodile.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Bullet.h"
#include "GameScene.h"

Crocodile::Crocodile()
{
	m_damage = DAMAGE_Crocodile;
}

Crocodile::Crocodile(const Crocodile& i_Crocodile)
{

}

const int SPRITES_TWO	= 2;
const int SPRITES_THREE = 3;
const int SPRITES_FOUR	= 4;

void Crocodile::LoadNameSprites()
{
	for (int i = 1; i <= SPRITES_FOUR; i++)
	{
		m_vecRun.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Run/Run_" + std::to_string(i));
	}
	for (int i = 1; i <= SPRITES_THREE; i++)
	{
		m_vecDead.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Dead/Dead_" + std::to_string(i));
	}
	for (int i = 1; i <= SPRITES_TWO; i++)
	{
		m_vecDizzy.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Dizzy/Dizzy_" + std::to_string(i));
		m_vecIdle.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Idle/Idle_" + std::to_string(i));
		m_vecJump.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Jump/Jump_" + std::to_string(i));
	}
	m_vecSlide.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Slide/Slide_1");
}

/*virtual*/ void Crocodile::Run()
{

}

/*virtual*/ void Crocodile::Melee()
{

}

/*virtual*/ void Crocodile::Slide()
{

}

/*virtual*/ void Crocodile::Dead()
{

}

/*virtual*/ void Crocodile::Idle()
{

}

/*virtual*/ void Crocodile::MoveUp()
{

}

/*virtual*/ void Crocodile::MoveDown()
{

}

/*virtual*/ void Crocodile::MoveRight()
{

}

/*virtual*/ void Crocodile::MoveLeft()
{

}

Crocodile::~Crocodile()
{

}