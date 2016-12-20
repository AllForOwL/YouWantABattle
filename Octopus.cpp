#include "Octopus.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

Octopus::Octopus()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Octopus.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);
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