#ifndef __INPUT_COMPONENT_H__
#define __INPUT_COMPONENT_H__

#include "cocos2d.h"

USING_NS_CC;

class ManagerComponent;

class InputComponent
{
public:
	virtual ~InputComponent() {};

	virtual void Update(ManagerComponent& i_manager) = 0;

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) = 0;
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) = 0;
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) = 0;
};

#endif