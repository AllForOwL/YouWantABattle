#include "Knight.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 6;
const int STRENGTH	= 50;
const int DEXTERITY = 85;
const int HEIGHT_JUMP = 6;

Knight::Knight()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Knight.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;

	LoadNameSprites();
}

Knight::Knight(const Knight& i_Knight)
{

}

const int SPRITES_TEN = 10;
const int MAX_INDEX = 9;

void Knight::LoadNameSprites()
{
	for (int i = 1; i <= SPRITES_TEN; i++)
	{
		m_vecDead.push_back(PATH_TO_RESOURCES		+ "/Heroes/Knight/Dead/Dead_"	+ std::to_string(i) + ".png");
		m_vecIdle.push_back(PATH_TO_RESOURCES		+ "/Heroes/Knight/Idle/Idle_"	+ std::to_string(i) + ".png");
		m_vecJump.push_back(PATH_TO_RESOURCES		+ "/Heroes/Knight/Jump/Jump_"	+ std::to_string(i) + ".png");
		m_vecMelee.push_back(PATH_TO_RESOURCES		+ "/Heroes/Knight/Melee/Melee_" + std::to_string(i) + ".png");
		m_vecRun.push_back(PATH_TO_RESOURCES		+ "/Heroes/Knight/Run/Run_"		+ std::to_string(i) + ".png");
		m_vecSlide.push_back(PATH_TO_RESOURCES		+ "/Heroes/Knight/Slide/Slide_" + std::to_string(i) + ".png");
		m_vecAttack.push_back(PATH_TO_RESOURCES		+ "/Heroes/Knight/Melee/Melee_" + std::to_string(i) + ".png");
		m_vecAttackJump.push_back(PATH_TO_RESOURCES + "/Heroes/Knight/Run/Run_"		+ std::to_string(i) + ".png");
		m_vecWalk.push_back(PATH_TO_RESOURCES		+ "/Heroes/Knight/Slide/Slide_" + std::to_string(i) + ".png");
	}
}

void Knight::Shoot()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecShoot[m_indexShoot]));
	if (++m_indexShoot > MAX_INDEX)
	{
		m_indexShoot = 0;
	}
}

/*virtual*/ void Knight::Run()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecRun[m_indexRun]));
	if (++m_indexRun > MAX_INDEX)
	{
		m_indexRun = 0;
	}
}

/*virtual*/ void Knight::Slide()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSlide[m_indexSlide]));
	if (++m_indexSlide > MAX_INDEX)
	{
		m_indexSlide = 0;
	}
}

/*virtual*/ void Knight::Dead()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDead[m_indexDead]));
	if (++m_indexDead > MAX_INDEX)
	{
		m_indexDead = 0;
	}
}

/*virtual*/ void Knight::Idle()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecIdle[m_indexIdle]));
	if (++m_indexIdle > MAX_INDEX)
	{
		m_indexIdle = 0;
	}
}

/*virtual*/ void Knight::Jump()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecJump[m_indexJump]));
	if (++m_indexJump > MAX_INDEX)
	{
		m_indexJump = 0;
	}
}

/*virtual*/ void Knight::Attack()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecAttack[m_indexAttack]));
	if (++m_indexAttack > MAX_INDEX)
	{
		m_indexAttack = 0;
	}
}

/*virtual*/ void Knight::AttackJump()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecAttackJump[m_indexAttackJump]));
	if (++m_indexAttackJump > MAX_INDEX)
	{
		m_indexAttackJump = 0;
	}
}

/*virtual*/ void Knight::Walk()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecWalk[m_indexWalk]));
	if (++m_indexWalk > MAX_INDEX)
	{
		m_indexWalk = 0;
	}
}

/*virtual*/ void Knight::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{

}

Knight::~Knight()
{
}