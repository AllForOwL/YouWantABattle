#include "HUDLayer.h"
#include "ManagerComponent.h"
#include "ChoiseHeroScene.h"
#include "Warrior.h"
#include "HeroInputComponent.h"
#include "Weapon.h"

const int INDEX_PRESS_DOWN	= 0;
const int INDEX_PRESS_UP	= 1;
const int INDEX_PRESS_LEFT	= 2;
const int INDEX_PRESS_RIGHT	= 3;

bool HUDLayer::init()
{
	if (!Layer::init())	
	{
		return false;
	}

	AddSpritesMoveHero();
	m_state = State::DETERMINE_TOUCH;

	return true;
}

void HUDLayer::Update(ManagerComponent& i_manager)
{
	switch (m_state)
	{
		case State::MOVE_BUTTON_TO_TOUCH:
		{
			if (i_manager.m_inputHero->GetLocationTouch() != Point::ZERO)
			{
				m_positionPrevious = m_btnMoveHero->getPosition();
				m_btnMoveHero->setPosition(i_manager.m_inputHero->GetLocationTouch());

				if (!m_rctMoveButton->containsPoint(i_manager.m_inputHero->GetLocationTouch()))
				{
					m_btnMoveHero->setPosition(m_positionBegin);
					m_state = State::DETERMINE_TOUCH;
				}
			}

			break;
		}
		case State::DETERMINE_TOUCH:
		{
			if (DetermineEvent(i_manager))
			{
				i_manager.m_inputHero->SetZeroLocation();
			}

			break;
		}
	}
}

void HUDLayer::AddSpritesMoveHero()
{
	m_btnMoveHero = Sprite::create(PATH_TO_RESOURCES + "/MenuItems/SmallRedButton.png");
	m_btnMoveHero->setScale(ChoiseHeroScene::m_visiblSize.width / m_btnMoveHero->getContentSize().width / 10,
		ChoiseHeroScene::m_visiblSize.height / m_btnMoveHero->getContentSize().height / 6);
	m_positionBegin = Point(m_btnMoveHero->getBoundingBox().size.width * 1.5,
		m_btnMoveHero->getBoundingBox().size.height * 1.5);
	m_btnMoveHero->setPosition(m_positionBegin);
	this->addChild(m_btnMoveHero);

	m_rctMoveButton = new Rect(m_btnMoveHero->getPositionX() - m_btnMoveHero->getBoundingBox().size.width,
		m_btnMoveHero->getPositionY() - m_btnMoveHero->getBoundingBox().size.height, m_btnMoveHero->getBoundingBox().size.width * 2,
		m_btnMoveHero->getBoundingBox().size.height * 2);
}

bool HUDLayer::DetermineEvent(ManagerComponent& i_manager)
{
	Point _locationTouchHero = i_manager.m_inputHero->GetLocationTouch();

	if (m_btnMoveHero->getBoundingBox().containsPoint(_locationTouchHero))
	{
		m_state = State::MOVE_BUTTON_TO_TOUCH;
		return true;
	}
	else if (i_manager.m_hero->getBoundingBox().containsPoint(_locationTouchHero))
	{
		i_manager.m_hero->SetState(Warrior::State::RUN);
		return true;
	}
	return false;
}

HUDLayer::~HUDLayer()
{

}