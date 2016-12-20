#include "Knight.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

Knight::Knight()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Knight.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);
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