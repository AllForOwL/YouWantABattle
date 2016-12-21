#include "Octopus.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 40;
const int STRENGTH	= 50;
const int DEXTERITY = 45;

Octopus::Octopus()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Octopus.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
}

Octopus::Octopus(const Octopus& i_Octopus)
{

}

/*virtual*/ void Octopus::Update(ManagerComponent& i_manager)
{

}

Octopus::~Octopus()
{
}