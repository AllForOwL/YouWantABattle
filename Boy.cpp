#include "Boy.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 4;
const int STRENGTH	= 45;
const int DEXTERITY = 80;
const int HEIGHT_JUMP = 4;

Boy::Boy()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Boy.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;
}

Boy::Boy(const Boy& i_Boy)
{

}

/*virtual*/ void Boy::Run()
{

}

/*virtual*/ void Boy::Melee()
{

}

/*virtual*/ void Boy::Slide()
{

}

/*virtual*/ void Boy::Dead()
{

}

/*virtual*/ void Boy::Idle()
{

}

/*virtual*/ void Boy::MoveUp()
{

}

/*virtual*/ void Boy::MoveDown()
{

}

/*virtual*/ void Boy::MoveRight()
{

}

/*virtual*/ void Boy::MoveLeft()
{

}

/*virtual*/ void Boy::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{

}


Boy::~Boy()
{
}