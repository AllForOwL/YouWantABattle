#include "Giant.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 10;
const int STRENGTH	= 90;
const int DEXTERITY = 10;

Giant::Giant()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Giant.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
}

Giant::Giant(const Giant& i_Giant)
{

}

/*virtual*/ void Giant::Update(ManagerComponent& i_manager)
{

}

Giant::~Giant()
{
}