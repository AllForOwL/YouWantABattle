#ifndef __ENEMY_INPUT_COMPONENT_H__
#define __ENEMY_INPUT_COMPONENT_H__

#include "cocos2d.h"

#include "InputComponent.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class EnemyInputComponent : public InputComponent
{
public:
	EnemyInputComponent();
	EnemyInputComponent(const EnemyInputComponent& i_manager);
	~EnemyInputComponent();

	virtual void Update(ManagerComponent& i_manager);

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

private:
};

#endif 
