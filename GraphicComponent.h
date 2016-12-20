#ifndef __GRAPHIC_COMPONENT_H__
#define __GRAPHIC_COMPONENT_H__

#include "cocos2d.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class GraphicComponent : public cocos2d::Sprite
{
public:
	GraphicComponent() {};
	virtual ~GraphicComponent() {};
};

#endif 
