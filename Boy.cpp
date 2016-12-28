#include "Boy.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 4;
const int STRENGTH	= 45;
const int DEXTERITY = 80;
const int HEIGHT_JUMP = 4;

Boy::Boy()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Boy.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;

	LoadNameSprites();
}

Boy::Boy(const Boy& i_Boy)
{

}

const int SPRITES_NINE = 9;
const int MAX_INDEX = 9;

void Boy::LoadNameSprites()
{
	for (int i = 0; i <= SPRITES_NINE; i++)
	{
		m_vecDead.push_back(PATH_TO_RESOURCES	+ "/Heroes/Boy/Dead/Dead__00"	+ std::to_string(i) + ".png");
		m_vecIdle.push_back(PATH_TO_RESOURCES	+ "/Heroes/Boy/Idle/Idle__00"	+ std::to_string(i) + ".png");
		m_vecJump.push_back(PATH_TO_RESOURCES	+ "/Heroes/Boy/Jump/Jump__00"	+ std::to_string(i) + ".png");
		m_vecMelee.push_back(PATH_TO_RESOURCES	+ "/Heroes/Boy/Melee/Melee__00" + std::to_string(i) + ".png");
		m_vecRun.push_back(PATH_TO_RESOURCES	+ "/Heroes/Boy/Run/Run__00"		+ std::to_string(i) + ".png");
		m_vecSlide.push_back(PATH_TO_RESOURCES	+ "/Heroes/Boy/Slide/Slide__00" + std::to_string(i) + ".png");
	}
}

/*virtual*/ void Boy::Run()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecRun[m_indexRun]));
	if (++m_indexRun > MAX_INDEX)
	{
		m_indexRun = 0;
	}
}

/*virtual*/ void Boy::Melee()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecMelee[m_indexMelee]));
	if (++m_indexMelee > MAX_INDEX)
	{
		m_indexMelee = 0;
	}
}

/*virtual*/ void Boy::Slide()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecMelee[m_indexSlide]));
	if (++m_indexSlide > MAX_INDEX)
	{
		m_indexSlide = 0;
	}
}

/*virtual*/ void Boy::Dead()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDead[m_indexDead]));
	if (++m_indexDead > MAX_INDEX)
	{
		m_indexDead = 0;
	}
}

/*virtual*/ void Boy::Idle()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecIdle[m_indexIdle]));
	if (++m_indexIdle > MAX_INDEX)
	{
		m_indexIdle = 0;
	}
}

/*virtual*/ void Boy::Jump()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecJump[m_indexJump]));
	if (++m_indexJump > MAX_INDEX)
	{
		m_indexJump = 0;
	}
}

/*virtual*/ void Boy::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{

}

Boy::~Boy()
{
}