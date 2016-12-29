#include "HeroInputComponent.h"
#include "ManagerComponent.h"

HeroInputComponent::HeroInputComponent()
{

}
HeroInputComponent::HeroInputComponent(const HeroInputComponent& i_heroInput)
{

}

/*virtual*/ void HeroInputComponent::Update(ManagerComponent& i_manager)
{

}

Point HeroInputComponent::GetLocationTouch() const
{
	return m_locationTouch;
}

void HeroInputComponent::SetZeroLocation()
{
	m_locationTouch = Point::ZERO;
}

/*virtual*/ bool HeroInputComponent::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	//m_locationTouch = touch->getLocation();

	return true;
}

/*virtual*/ void HeroInputComponent::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	m_locationTouch = touch->getLocation();
}

/*virtual*/ void HeroInputComponent::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	
}

HeroInputComponent::~HeroInputComponent()
{

}