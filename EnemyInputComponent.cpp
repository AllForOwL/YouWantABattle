#include "EnemyInputComponent.h"
#include "ManagerComponent.h"

EnemyInputComponent::EnemyInputComponent()
{

}
EnemyInputComponent::EnemyInputComponent(const EnemyInputComponent& i_heroInput)
{

}

/*virtual*/ void EnemyInputComponent::Update(ManagerComponent& i_manager)
{

}

/*virtual*/ bool EnemyInputComponent::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	return true;
}

/*virtual*/ void EnemyInputComponent::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

/*virtual*/ void EnemyInputComponent::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

EnemyInputComponent::~EnemyInputComponent()
{

}