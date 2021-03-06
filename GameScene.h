#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;
class PhysicComponent;

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(int i_numberHero);

    virtual bool init();
 
    CREATE_FUNC(GameScene);

	void update(float dt);

	cocos2d::PhysicsWorld* m_sceneWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld* world)
	{
		m_sceneWorld = world;
	}

	void SetSpeedUpdate(float i_newValueUpdate);

private:
	Size	m_visiblSize;
	Point	m_origin;

	static int m_numberHero;

	ManagerComponent*	m_manager;

	PhysicComponent*	m_physicComponent;

	float m_timeUpdate;
};

#endif 
