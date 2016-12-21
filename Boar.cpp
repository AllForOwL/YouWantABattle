#include "Boar.h"
#include "ManagerComponent.h"
#include "constants.h"
#include "ChoiseHeroScene.h"
#include "Weapon.h"

const int SPEED		= 20;
const int STRENGTH	= 80;
const int DEXTERITY = 15;

Boar::Boar()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Boar.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
}

Boar::Boar(const Boar& i_boar)
{

}

/*virtual*/ void Boar::Update(ManagerComponent& i_manager)
{
	//i_manager.m_weaponHero->Fire();		// very cool !!! 
}

Boar::~Boar()
{

}