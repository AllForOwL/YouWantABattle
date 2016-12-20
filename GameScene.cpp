#include "GameScene.h"
#include "ManagerComponent.h"

const float CNT_TIME_UPDATE_MANAGER = 0.01;

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

	m_manager = new ManagerComponent(m_numberHero);

	this->schedule(schedule_selector(GameScene::update), CNT_TIME_UPDATE_MANAGER);

    return true;
}

void GameScene::update(float dt)
{
	m_manager->Update();
}