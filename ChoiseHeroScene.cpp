#include "ChoiseHeroScene.h"

const string PATH_TO_RESOURCES = "E:\programming\cocos\project\YouWantABattle\proj.win32\res";

Scene* ChoiseHeroScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = ChoiseHeroScene::create();

    scene->addChild(layer);

    return scene;
}

bool ChoiseHeroScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize	= Director::getInstance()->getVisibleSize();
    Vec2 origin			= Director::getInstance()->getVisibleOrigin();    


	LoadMenuItems();

	/*CCMenu* testMenu = CCMenu::createWithArray(m_menuItems);

	testMenu->alignItemsInColumns(2, 2, 2, 2, 2, 2, 1);

	CCSize size1 = CCDirector::sharedDirector()->getWinSize();

	testMenu->setPosition(ccp(size1.width / 2, size1.height / 2));*/

    return true;
}

void ChoiseHeroScene::menuChoiseHeroCallback(cocos2d::Ref* i_pSender)
{
	for (int i = 0; i < m_menuItems.size(); i++)
	{
		if (m_menuItems.at(i)->_ID == i_pSender->_ID)
		{
			CreateSceneGame(i);
		}
	}
}

void ChoiseHeroScene::CreateSceneGame(int i_indexHero)
{
	// here has been create game scene
}

void ChoiseHeroScene::LoadMenuItems()
{
	vector<string> _filename;
	_filename.push_back(PATH_TO_RESOURCES + "\MenuItems\Boar.png");
	_filename.push_back(PATH_TO_RESOURCES + "\MenuItems\Bowman.png");
	_filename.push_back(PATH_TO_RESOURCES + "\MenuItems\Giant.png");
	_filename.push_back(PATH_TO_RESOURCES + "\MenuItems\Octopus.png");
	_filename.push_back(PATH_TO_RESOURCES + "\MenuItems\Paladin.png");
	_filename.push_back(PATH_TO_RESOURCES + "\MenuItems\Warrior.png");
	_filename.push_back(PATH_TO_RESOURCES + "\MenuItems\Wizard.png");
	_filename.push_back(PATH_TO_RESOURCES + "\MenuItems\Yeti.png");
	
	for (int i = 0; i < _filename.size(); i++)
	{
		m_menuItems.pushBack(MenuItemImage::create(_filename[i], _filename[i], CC_CALLBACK_1(ChoiseHeroScene::menuChoiseHeroCallback, this)));
	}
}