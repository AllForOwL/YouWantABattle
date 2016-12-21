#include "Knight.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 60;
const int STRENGTH	= 50;
const int DEXTERITY = 85;

Knight::Knight()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Knight.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
}

Knight::Knight(const Knight& i_Knight)
{

}

/*virtual*/ void Knight::Update(ManagerComponent& i_manager)
{

}

Knight::~Knight()
{
}