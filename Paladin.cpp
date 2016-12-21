#include "Paladin.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 50;
const int STRENGTH	= 60;
const int DEXTERITY = 55;

Paladin::Paladin()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Paladin.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
}

Paladin::Paladin(const Paladin& i_Paladin)
{

}

/*virtual*/ void Paladin::Update(ManagerComponent& i_manager)
{

}

Paladin::~Paladin()
{
}