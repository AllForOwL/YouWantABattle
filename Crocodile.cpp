#include "Crocodile.h"
#include "ManagerComponent.h"
#include "Warrior.h"
#include "Bullet.h"
#include "GameScene.h"

Crocodile::Crocodile()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Crocodile.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);


	m_damage = DAMAGE_Crocodile;

	LoadNameSprites();
}

Crocodile::Crocodile(const Crocodile& i_Crocodile)
{

}

const int SPRITES_TWO	= 2;
const int SPRITES_THREE = 3;
const int SPRITES_FOUR	= 4;

void Crocodile::LoadNameSprites()
{
	for (int i = 1; i <= SPRITES_FOUR; i++)
	{
		m_vecRun.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Run/Run_" + std::to_string(i) + ".png");
	}
	for (int i = 1; i <= SPRITES_THREE; i++)
	{
		m_vecDead.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Dead/Dead_" + std::to_string(i) + ".png");
	}
	for (int i = 1; i <= SPRITES_TWO; i++)
	{
		m_vecDizzy.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Dizzy/Dizzy_" + std::to_string(i) + ".png");
		m_vecIdle.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Idle/Idle_" + std::to_string(i) + ".png");
		m_vecJump.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Jump/Jump_" + std::to_string(i) + ".png");
	}
	m_vecSlide.push_back(PATH_TO_RESOURCES + "/Heroes/Crocodile/Slide/Slide_1.png");
}

const int MAX_INDEX_SHOOT = 2;
/*virtual*/ void Crocodile::Shoot()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecShoot[m_indexShoot]));
	if (++m_indexShoot > MAX_INDEX_SHOOT)
	{
		m_indexShoot = 0;
	}
}

const int MAX_INDEX_DIZZY = 2;
/*virtual*/ void Crocodile::Dizzy()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDizzy[m_indexDizzy]));
	if (++m_indexDizzy > MAX_INDEX_DIZZY)
	{
		m_indexDizzy = 0;
	}
}

const int MAX_INDEX_RUN = 3;
/*virtual*/ void Crocodile::Run()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecRun[m_indexRun]));
	if (++m_indexRun > MAX_INDEX_RUN)
	{
		m_indexRun = 0;
	}
}

/*virtual*/ void Crocodile::Slide()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSlide[0]));
}

const int MAX_INDEX_DEAD = 2;
/*virtual*/ void Crocodile::Dead()
{
	this->create(m_vecDead[m_indexDead]);
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDead[m_indexDead]));
	if (++m_indexDead > MAX_INDEX_DEAD)
	{
		m_indexDead = 0;
	}
}

const int MAX_INDEX_IDLE = 1;
/*virtual*/ void Crocodile::Idle()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecIdle[m_indexIdle]));
	if (++m_indexIdle > MAX_INDEX_IDLE)
	{
		m_indexIdle = 0;
	}
}

const int MAX_INDEX_JUMP = 2;
/*virtual*/ void Crocodile::Jump()
{
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecJump[m_indexJump]));
	if (++m_indexJump > MAX_INDEX_JUMP)
	{
		m_indexJump = 0;
	}
}

Crocodile::~Crocodile()
{

}