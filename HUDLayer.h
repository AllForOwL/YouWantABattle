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
	enum State
	{
		MOVE_BUTTON_TO_TOUCH,
		DETERMINE_TOUCH
	};

	virtual bool init();

	~HUDLayer();

	CREATE_FUNC(HUDLayer);

	void Update(ManagerComponent& i_manager);

	void AddSpritesMoveHero();

	bool DetermineEvent(ManagerComponent& i_manager);

private:
	State	m_state;
	vector<Sprite*>	m_vecMove;
	vector<Rect>	m_rectMove;
	
	Sprite*	m_btnMoveHero;
	Rect*	m_rctMoveButton;
	Point	m_positionPrevious;
	Point	m_positionBegin;
};

#endif // __HUD_LAYER_H__
