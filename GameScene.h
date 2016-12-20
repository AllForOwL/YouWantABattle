#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(int i_numberHero);

    virtual bool init();
 
    CREATE_FUNC(GameScene);

	void update(float dt);

private:
	Size	m_visiblSize;
	Point	m_origin;

	static int m_numberHero;

	ManagerComponent*	m_manager;
};

#endif 
