#include "ChoiseHeroScene.h"
#include "GameScene.h"

const string PATH_TO_RESOURCES = "E:/programming/cocos/project/YouWantABattle/proj.win32/res";

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
    
    m_visiblSize	= Director::getInstance()->getVisibleSize();
    m_origin		= Director::getInstance()->getVisibleOrigin();    

	LoadMenuItems();
	CCMenu* testMenu = CCMenu::createWithArray(m_menuItems);
	testMenu->alignItemsInColumns(4, 4);
	testMenu->setPosition(m_visiblSize.width / 2, m_visiblSize.height / 2);
	this->addChild(testMenu);

    return true;
}

void ChoiseHeroScene::menuChoiseHeroCallback(cocos2d::Ref* i_pSender)
{
	for (int i = 0; i < m_menuItems.size(); i++)
	{
		if (m_menuItems.at(i)->_ID == i_pSender->_ID)
		{
			CreateSceneGame(i);
			return; 
		}
	}
}

void ChoiseHeroScene::CreateSceneGame(int i_indexHero)
{
	auto _gameScene = GameScene::createScene(i_indexHero);

	srand(time(NULL));
	auto reScene = TransitionFade::create(2.0f, _gameScene, Color3B(rand() % 255 + 0, rand() % 255 + 0, rand() % 255 + 0));
	Director::getInstance()->replaceScene(reScene);
}

void ChoiseHeroScene::LoadMenuItems()
{
	vector<string> _filename;
	_filename.push_back(PATH_TO_RESOURCES + "/MenuItems/Boar.png");
	_filename.push_back(PATH_TO_RESOURCES + "/MenuItems/Bowman.png");
	_filename.push_back(PATH_TO_RESOURCES + "/MenuItems/Giant.png");
	_filename.push_back(PATH_TO_RESOURCES + "/MenuItems/Octopus.png");
	_filename.push_back(PATH_TO_RESOURCES + "/MenuItems/Paladin.png");
	_filename.push_back(PATH_TO_RESOURCES + "/MenuItems/Warrior.png");
	_filename.push_back(PATH_TO_RESOURCES + "/MenuItems/Wizard.png");
	_filename.push_back(PATH_TO_RESOURCES + "/MenuItems/Yeti.png");
	
	for (int i = 0; i < _filename.size(); i++)
	{
		m_menuItems.pushBack(MenuItemImage::create(_filename[i], _filename[i], CC_CALLBACK_1(ChoiseHeroScene::menuChoiseHeroCallback, this)));
		m_menuItems.at(i)->setScale(m_visiblSize.width / m_menuItems.at(i)->getContentSize().width / 6,
			m_visiblSize.height / m_menuItems.at(i)->getContentSize().height / 6);
	}
}