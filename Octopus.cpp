#include "Octopus.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 4;
const int STRENGTH	= 50;
const int DEXTERITY = 45;
const int HEIGHT_JUMP = 4;

Octopus::Octopus()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Octopus.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;
}

Octopus::Octopus(const Octopus& i_Octopus)
{

}

Octopus::~Octopus()
{
}