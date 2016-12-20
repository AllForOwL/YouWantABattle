#ifndef __CHOISE_HERO_SCENE_H__
#define __CHOISE_HERO_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

using std::string;
using std::vector;

class ChoiseHeroScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
 
    CREATE_FUNC(ChoiseHeroScene);

	void menuChoiseHeroCallback(cocos2d::Ref* i_pSender);

	void LoadMenuItems();
	void CreateSceneGame(int i_indexHero);

	static Size	m_visiblSize;
private:
	Point	m_origin;

	Vector<MenuItem*>	m_menuItems;
};

#endif // __HELLOWORLD_SCENE_H__
