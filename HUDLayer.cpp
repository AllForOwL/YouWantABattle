#include "HUDLayer.h"
#include "ManagerComponent.h"
#include "ChoiseHeroScene.h"
#include "Warrior.h"
#include "HeroInputComponent.h"
#include "constants.h"

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

	return true;
}

void HUDLayer::Update(ManagerComponent& i_manager)
{
	if (DetermineEvent(i_manager))
	{
		i_manager.m_inputHero->SetZeroLocation();
	}
}

void HUDLayer::AddSpritesMoveHero()
{
	vector<string> _filename;
	_filename.push_back(PATH_TO_RESOURCES + "/UI/Move/PressDown.png");
	_filename.push_back(PATH_TO_RESOURCES + "/UI/Move/PressUp.png");
	_filename.push_back(PATH_TO_RESOURCES + "/UI/Move/PressLeft.png");
	_filename.push_back(PATH_TO_RESOURCES + "/UI/Move/PressRight.png");

	for (int i = 0; i < _filename.size(); i++)
	{
		m_vecMove.push_back(Sprite::create(_filename[i]));
		this->addChild(m_vecMove[i]);
	}

	m_vecMove[INDEX_PRESS_DOWN]->setScale(ChoiseHeroScene::m_visiblSize.width / m_vecMove[INDEX_PRESS_DOWN]->getContentSize().width / 20,
		ChoiseHeroScene::m_visiblSize.height / m_vecMove[INDEX_PRESS_DOWN]->getContentSize().height / 16);

	m_vecMove[INDEX_PRESS_UP]->setScale(ChoiseHeroScene::m_visiblSize.width / m_vecMove[INDEX_PRESS_UP]->getContentSize().width / 20,
		ChoiseHeroScene::m_visiblSize.height / m_vecMove[INDEX_PRESS_UP]->getContentSize().height / 16);

	m_vecMove[INDEX_PRESS_LEFT]->setScale(ChoiseHeroScene::m_visiblSize.width / m_vecMove[INDEX_PRESS_LEFT]->getContentSize().width / 16,
		ChoiseHeroScene::m_visiblSize.height / m_vecMove[INDEX_PRESS_LEFT]->getContentSize().height / 20);

	m_vecMove[INDEX_PRESS_RIGHT]->setScale(ChoiseHeroScene::m_visiblSize.width / m_vecMove[INDEX_PRESS_RIGHT]->getContentSize().width / 16,
		ChoiseHeroScene::m_visiblSize.height / m_vecMove[INDEX_PRESS_RIGHT]->getContentSize().height / 20);

	Size _sizePressVertical		= m_vecMove[INDEX_PRESS_DOWN]->getBoundingBox().size;
	Size _sizePressHorizontal	= m_vecMove[INDEX_PRESS_LEFT]->getBoundingBox().size; 

	m_vecMove[INDEX_PRESS_DOWN]->setPosition(ChoiseHeroScene::m_visiblSize.width - (_sizePressHorizontal.width + _sizePressVertical.height / 2),
		_sizePressVertical.height / 2);
		
	m_vecMove[INDEX_PRESS_UP]->setPosition(ChoiseHeroScene::m_visiblSize.width - (_sizePressHorizontal.width + _sizePressVertical.height / 2),
		_sizePressVertical.height + _sizePressVertical.height / 2);

	m_vecMove[INDEX_PRESS_LEFT]->setPosition(m_vecMove[INDEX_PRESS_DOWN]->getPositionX() -  _sizePressHorizontal.width / 2,
		_sizePressVertical.height);

	m_vecMove[INDEX_PRESS_RIGHT]->setPosition(m_vecMove[INDEX_PRESS_DOWN]->getPositionX() + _sizePressHorizontal.width / 2,
		_sizePressVertical.height);

	for (int i = 0; i < _filename.size(); i++)
	{
		m_rectMove.push_back(m_vecMove[i]->getBoundingBox());
	}
}

bool HUDLayer::DetermineEvent(ManagerComponent& i_manager)
{
	Point _locationTouchHero = i_manager.m_inputHero->GetLocationTouch();

	if (m_rectMove[INDEX_PRESS_UP].containsPoint(_locationTouchHero))
	{
		i_manager.m_hero->SetState(Warrior::State::JUMP);
		return true;
	}
	else if (m_rectMove[INDEX_PRESS_DOWN].containsPoint(_locationTouchHero))
	{
		i_manager.m_hero->SetState(Warrior::State::CROUCH);
		return true;
	}
	else if (m_rectMove[INDEX_PRESS_LEFT].containsPoint(_locationTouchHero))
	{
		i_manager.m_hero->SetState(Warrior::State::MOVE_LEFT);
		return true;
	}
	else if (m_rectMove[INDEX_PRESS_RIGHT].containsPoint(_locationTouchHero))
	{
		i_manager.m_hero->SetState(Warrior::State::MOVE_RIGHT);
		return true;
	}
	else if (i_manager.m_hero->getBoundingBox().containsPoint(_locationTouchHero))
	{
		i_manager.m_hero->SetState(Warrior::State::FIRE);
		return true;
	}
	return false;
}

HUDLayer::~HUDLayer()
{

}