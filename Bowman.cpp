#include "Bowman.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

Bowman::Bowman()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Bowman.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);
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