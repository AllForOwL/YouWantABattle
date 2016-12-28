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

const int SPRITES_NINE = 9;

void Boy::LoadNameSprites()
{
	for (int i = 0; i <= SPRITES_NINE; i++)
	{
		m_vecDead.push_back(PATH_TO_RESOURCES + "/Heroes/Boy/Dead/Dead__00" + std::to_string(i));
		m_vecIdle.push_back(PATH_TO_RESOURCES + "/Heroes/Boy/Idle/Idle__00" + std::to_string(i));
		m_vecJump.push_back(PATH_TO_RESOURCES + "/Heroes/Boy/Jump/Jump__00" + std::to_string(i));
		m_vecMelee.push_back(PATH_TO_RESOURCES + "/Heroes/Boy/Melee/Melee__00" + std::to_string(i));
		m_vecRun.push_back(PATH_TO_RESOURCES + "/Heroes/Boy/Run/Run__00" + std::to_string(i));
		m_vecSlide.push_back(PATH_TO_RESOURCES + "/Heroes/Boy/Slide/Slide__00" + std::to_string(i));
	}
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