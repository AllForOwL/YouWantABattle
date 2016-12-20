#ifndef __HERO_INPUT_COMPONENT_H__
#define __HERO_INPUT_COMPONENT_H__

#include "cocos2d.h"

#include "InputComponent.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class HeroInputComponent : public InputComponent
{
public:
	HeroInputComponent();
	HeroInputComponent(const HeroInputComponent& i_heroInput);
	~HeroInputComponent();

	virtual void Update(ManagerComponent& i_manager);

private:
};

#endif 
