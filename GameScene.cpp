#include "GameScene.h"
#include "ManagerComponent.h"
#include "HeroInputComponent.h"
#include "PhysicComponent.h"
#include "ChoiseHeroScene.h"

#define SCENE_COLLISION_BITMASK		0x000004

int GameScene::m_numberHero = 0;

Scene* GameScene::createScene(int i_numberHero)
{
	m_numberHero = i_numberHero;

	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));    

	auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);

    return scene;
}

bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
	auto edgeBody = PhysicsBody::createEdgeBox(ChoiseHeroScene::m_visiblSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeBody->setCollisionBitmask(SCENE_COLLISION_BITMASK);
	edgeBody->setContactTestBitmask(true);

	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(ChoiseHeroScene::m_visiblSize.width / 2, ChoiseHeroScene::m_visiblSize.height / 2));
	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);

    m_visiblSize	= Director::getInstance()->getVisibleSize();
    m_origin		= Director::getInstance()->getVisibleOrigin();    

	m_manager = new ManagerComponent(*this, m_numberHero);

	m_physicComponent = new PhysicComponent();

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(PhysicComponent::onContactBegin, m_physicComponent);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);


	auto _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(HeroInputComponent::onTouchBegan, m_manager->m_inputHero);
	_touchListener->onTouchMoved = CC_CALLBACK_2(HeroInputComponent::onTouchMoved, m_manager->m_inputHero);
	_touchListener->onTouchEnded = CC_CALLBACK_2(HeroInputComponent::onTouchEnded, m_manager->m_inputHero);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);

	m_timeUpdate = 0.0001;
	this->schedule(schedule_selector(GameScene::update), m_timeUpdate);

    return true;
}

void GameScene::update(float dt)
{
	m_manager->Update(*this);
	m_physicComponent->Update(*m_manager);
}

void GameScene::SetSpeedUpdate(float i_newValueUpdate)
{
	m_timeUpdate = i_newValueUpdate;
}