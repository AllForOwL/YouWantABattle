#include "Bowman.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 40;
const int STRENGTH	= 45;
const int DEXTERITY = 80;

Bowman::Bowman()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Bowman.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
}

Bowman::Bowman(const Bowman& i_Bowman)
{

}

/*virtual*/ void Bowman::Update(ManagerComponent& i_manager)
{

}

Bowman::~Bowman()
{
}