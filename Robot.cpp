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

/*virtual*/ void Robot::Run()
{

}

/*virtual*/ void Robot::Melee()
{

}

/*virtual*/ void Robot::Slide()
{

}

/*virtual*/ void Robot::Dead()
{

}

/*virtual*/ void Robot::Idle()
{

}

/*virtual*/ void Robot::MoveUp()
{

}

/*virtual*/ void Robot::MoveDown()
{

}

/*virtual*/ void Robot::MoveRight()
{

}

/*virtual*/ void Robot::MoveLeft()
{

}

/*virtual*/ void Robot::MeleeJump()
{

}

/*virtual*/ void Robot::ShootJump()
{

}

/*virtual*/ void Robot::ShootRun()
{

}

Robot::~Robot()
{

}