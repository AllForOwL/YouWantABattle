#include "Giant.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 1;
const int STRENGTH	= 90;
const int DEXTERITY = 10;
const int HEIGHT_JUMP = 1;


Giant::Giant()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Giant.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;
}

Giant::Giant(const Giant& i_Giant)
{

}

/*virtual*/ void Giant::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{

}

Giant::~Giant()
{
}