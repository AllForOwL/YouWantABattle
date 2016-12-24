#include "Boar.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 2;
const int STRENGTH	= 80;
const int DEXTERITY = 15;
const int HEIGHT_JUMP = 2;

Boar::Boar()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Boar.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;
}

Boar::Boar(const Boar& i_boar)
{

}

Boar::~Boar()
{

}