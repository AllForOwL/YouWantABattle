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

Robot::~Robot()
{

}