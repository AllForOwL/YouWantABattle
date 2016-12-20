#include "GameScene.h"

int GameScene::m_numberHero = 0;

Scene* GameScene::createScene(int i_numberHero)
{
	m_numberHero = i_numberHero;

    auto scene = Scene::create();
    
    auto layer = GameScene::create();

    scene->addChild(layer);

    return scene;
}

bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    m_visiblSize	= Director::getInstance()->getVisibleSize();
    m_origin		= Director::getInstance()->getVisibleOrigin();    




    return true;
}