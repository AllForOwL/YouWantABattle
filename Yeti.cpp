#include "Yeti.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 20;
const int STRENGTH	= 90;
const int DEXTERITY = 10;

Yeti::Yeti()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Yeti.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / 3,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / 3);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
}

Yeti::Yeti(const Yeti& i_Yeti)
{

}

/*virtual*/ void Yeti::Update(ManagerComponent& i_manager)
{

}

Yeti::~Yeti()
{
}