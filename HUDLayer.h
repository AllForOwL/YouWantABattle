#ifndef __HUD_LAYER_H__
#define __HUD_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class ManagerComponent;

using std::vector;
using std::string;

class HUDLayer : public cocos2d::Layer
{
public:
	virtual bool init();

	~HUDLayer();

	CREATE_FUNC(HUDLayer);

	void Update(ManagerComponent& i_manager);

	void AddSpritesMoveHero();

	bool DetermineEvent(ManagerComponent& i_manager);

private:
	vector<Sprite*>	m_vecMove;
	vector<Rect>	m_rectMove;
};

#endif // __HUD_LAYER_H__
