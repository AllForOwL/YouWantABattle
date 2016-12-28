#include "Robot.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Bullet.h"
#include "GameScene.h"

Robot::Robot()
{
	m_damage = DAMAGE_Robot;
}

Robot::Robot(const Robot& i_Robot)
{

}

const int SPRITES_TEN	= 10;
const int SPRITES_NINE	= 9;
const int SPRITES_EIGHT = 8;
const int SPRITES_FIVE	= 5;
const int SPRITES_FOUR	= 4;

void Robot::LoadNameSprites()
{
	for (int i = 1; i <= SPRITES_TEN; i++)
	{
		m_vecDead.push_back(PATH_TO_RESOURCES	+ "/Heroes/Robot/Dead/Dead_"	+ std::to_string(i));
		m_vecIdle.push_back(PATH_TO_RESOURCES	+ "/Heroes/Robot/Idle/Idle_"	+ std::to_string(i));
		m_vecJump.push_back(PATH_TO_RESOURCES	+ "/Heroes/Robot/Jump/Jump"		+ std::to_string(i));
		m_vecSlide.push_back(PATH_TO_RESOURCES	+ "/Heroes/Robot/Slide/Slide_"	+ std::to_string(i));
	}
	for (int i = 1; i <= SPRITES_NINE; i++)
	{
		m_vecShootRun.push_back(PATH_TO_RESOURCES + "/Heroes/Robot/RunShoot/RunShoot_" + std::to_string(i));
	}
	for (int i = 1; i <= SPRITES_EIGHT; i++)
	{
		m_vecMeleeJump.push_back(PATH_TO_RESOURCES	+ "/Heroes/Robot/JumpMelee/JumpMelee_"	+ std::to_string(i));
		m_vecMelee.push_back(PATH_TO_RESOURCES		+ "/Heroes/Robot/Melee/Melee_"			+ std::to_string(i));
		m_vecRun.push_back(PATH_TO_RESOURCES		+ "/Heroes/Robot/Run/Run_"				+ std::to_string(i));
	}
	for (int i = 1; i <= SPRITES_FIVE; i++)
	{
		m_vecShootJump.push_back(PATH_TO_RESOURCES + "/Heroes/Robot/JumpShoot/JumpShoot_" + std::to_string(i));
	}
	for (int i = 1; i <= SPRITES_FOUR; i++)
	{
		m_vecShoot.push_back(PATH_TO_RESOURCES + "/Heroes/Robot/Shoot/Shoot_" + std::to_string(i));
	}
}

const int MAX_INDEX_RUN = 7;
/*virtual*/ void Robot::Run()
{
	this->create(m_vecRun[m_indexRun]);
	if (++m_indexRun > MAX_INDEX_RUN)
	{
		m_indexRun = 0;
	}
}

const int MAX_INDEX_SLIDE = 9;
/*virtual*/ void Robot::Slide()
{
	this->create(m_vecSlide[m_indexSlide]);
	if (++m_indexSlide > MAX_INDEX_SLIDE)
	{
		m_indexSlide = 0;
	}
}

const int MAX_INDEX_DEAD = 9;
/*virtual*/ void Robot::Dead()
{
	this->create(m_vecDead[m_indexDead]);
	if (++m_indexDead > MAX_INDEX_DEAD)
	{
		m_indexDead = 0;
	}
}

const int MAX_INDEX_IDLE = 9;
/*virtual*/ void Robot::Idle()
{
	this->create(m_vecIdle[m_indexIdle]);
	if (++m_indexIdle > MAX_INDEX_IDLE)
	{
		m_indexIdle = 0;
	}
}

const int MAX_INDEX_JUMP = 9;
/*virtual*/ void Robot::Jump()
{
	this->create(m_vecJump[m_indexJump]);
	if (++m_indexJump > MAX_INDEX_JUMP)
	{
		m_indexJump = 0;
	}
}

const int MAX_INDEX_MELEE_JUMP = 7;
/*virtual*/ void Robot::MeleeJump()
{
	this->create(m_vecMeleeJump[m_indexMeleeJump]);
	if (++m_indexMeleeJump > MAX_INDEX_MELEE_JUMP)
	{
		m_indexMeleeJump = 0;
	}
}

const int MAX_INDEX_SHOOT_JUMP = 4;
/*virtual*/ void Robot::ShootJump()
{
	this->create(m_vecShootJump[m_indexShootJump]);
	if (++m_indexShootJump > MAX_INDEX_SHOOT_JUMP)
	{
		m_indexShootJump = 0;
	}
}

const int MAX_INDEX_SHOOT_RUN = 8;
/*virtual*/ void Robot::ShootRun()
{
	this->create(m_vecShootRun[m_indexShootRun]);
	if (++m_indexShootRun > MAX_INDEX_SHOOT_RUN)
	{
		m_indexShootRun = 0;
	}
}

const int MAX_INDEX_SHOOT = 3;
/*virtual*/ void Robot::Shoot()
{
	this->create(m_vecShoot[m_indexShoot]);
	if (++m_indexShoot > MAX_INDEX_SHOOT)
	{
		m_indexShoot = 0;
	}
}

Robot::~Robot()
{

}