#include "Knight.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 6;
const int STRENGTH	= 50;
const int DEXTERITY = 85;
const int HEIGHT_JUMP = 6;

Knight::Knight()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Knight.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;
}

Knight::Knight(const Knight& i_Knight)
{

}

/*virtual*/ void Knight::Run()
{

}

/*virtual*/ void Knight::Melee()
{

}

/*virtual*/ void Knight::Slide()
{

}

/*virtual*/ void Knight::Dead()
{

}

/*virtual*/ void Knight::Idle()
{

}

/*virtual*/ void Knight::MoveUp()
{

}

/*virtual*/ void Knight::MoveDown()
{

}

/*virtual*/ void Knight::MoveRight()
{

}

/*virtual*/ void Knight::MoveLeft()
{

}

/*virtual*/ void Knight::Attack()
{

}

/*virtual*/ void Knight::AttackJump()
{

}

/*virtual*/ void Knight::Walk()
{

}

/*virtual*/ void Knight::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{

}

Knight::~Knight()
{
}