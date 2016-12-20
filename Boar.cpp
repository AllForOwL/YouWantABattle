#include "Boar.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"

Boar::Boar()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Boar.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);
}

Boar::Boar(const Boar& i_boar)
{

}

/*virtual*/ void Boar::Update(ManagerComponent& i_manager)
{

}

Boar::~Boar()
{

}