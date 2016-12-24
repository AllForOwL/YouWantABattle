#include "Wizard.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 4;
const int STRENGTH	= 60;
const int DEXTERITY = 95;
const int HEIGHT_JUMP = 4;

Wizard::Wizard()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Wizard.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;
}

/*virtual*/ void Wizard::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{

}

Wizard::~Wizard()
{

}