#include "Wizard.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

Wizard::Wizard()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Wizard.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);
}

Wizard::Wizard(const Wizard& i_Wizard)
{

}

/*virtual*/ void Wizard::Update(ManagerComponent& i_manager)
{

}

Wizard::~Wizard()
{

}