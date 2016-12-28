#include "AdventureGirl.h"
#include "ChoiseHeroScene.h"
#include "ManagerComponent.h"
#include "HeroInputComponent.h"

const int SPEED		= 2;
const int STRENGTH	= 80;
const int DEXTERITY = 15;
const int HEIGHT_JUMP = 2;

const int INDEX_SKILL_QUICKLY_HIT_Robot = 0;

AdventureGirl::AdventureGirl()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/AdventureGirl.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	// main
	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;

	// act


	// skills
	m_positionBegin = Point::ZERO;
	m_positionEnd = Point::ZERO;
	m_stateHitRobot = QuicklyHitRobot::MOVE_FORWARD;

}

AdventureGirl::AdventureGirl(const AdventureGirl& i_AdventureGirl)
{

}

const int SPRITES_TEN	= 10;
const int SPRITES_SEVEN = 7;
const int SPRITES_THREE = 3;
const int SPRITES_FIVE	= 5;

void AdventureGirl::LoadNameSprites()
{
	for (int i = 1; i <= SPRITES_TEN; i++)
	{
		m_vecDead.push_back(PATH_TO_RESOURCES + "/Heroes/AdventureGirl/Dead/Dead_" + std::to_string(i));
		m_vecIdle.push_back(PATH_TO_RESOURCES + "/Heroes/AdventureGirl/Idle/Idle_" + std::to_string(i));
		m_vecJump.push_back(PATH_TO_RESOURCES + "/Heroes/AdventureGirl/Jump/Jump_" + std::to_string(i));
	}
	for (int i = 1; i <= SPRITES_SEVEN; i++)
	{
		m_vecMelee.push_back(PATH_TO_RESOURCES + "/Heroes/AdventureGirl/Melee/Melee_" + std::to_string(i));
		m_vecRun.push_back(PATH_TO_RESOURCES + "/Heroes/AdventureGirl/Run/Run_" + std::to_string(i));
	}
	for (int i = 1; i <= SPRITES_FIVE; i++)
	{
		m_vecSlide.push_back(PATH_TO_RESOURCES + "/Heroes/AdventureGirl/Slide/Slide_" + std::to_string(i));
	}
	for (int i = 1; i <= SPRITES_FIVE; i++)
	{
		m_vecShoot.push_back(PATH_TO_RESOURCES + "/Heroes/AdventureGirl/Shoot/Shoot_" + std::to_string(i));
	}
}

const int MAX_INDEX_RUN = 7;
/*virtual*/ void AdventureGirl::Run()
{
	this->create(m_vecRun[m_indexRun]);
	if (++m_indexRun > MAX_INDEX_RUN)
	{
		m_indexRun = 0;
	}
}

const int MAX_INDEX_MELEE = 6;
/*virtual*/ void AdventureGirl::Melee()
{
	this->create(m_vecMelee[m_indexMelee]);
	if (++m_indexMelee > MAX_INDEX_MELEE)
	{
		m_indexMelee = 0;
	}
}

const int MAX_INDEX_SLIDE = 4;
/*virtual*/ void AdventureGirl::Slide()
{
	this->create(m_vecSlide[m_indexSlide]);
	if (++m_indexRun > MAX_INDEX_SLIDE)
	{
		m_indexSlide = 0;
	}
}

const int MAX_INDEX_DEAD = 9;
/*virtual*/ void AdventureGirl::Dead()
{
	this->create(m_vecDead[m_indexDead]);
	if (++m_indexRun > MAX_INDEX_DEAD)
	{
		m_indexDead = 0;
	}
}

const int MAX_INDEX_IDLE = 9;
/*virtual*/ void AdventureGirl::Idle()
{
	this->create(m_vecIdle[m_indexIdle]);
	if (++m_indexRun > MAX_INDEX_IDLE)
	{
		m_indexIdle = 0;
	}
}

const int MAX_INDEX_JUMP = 9;
/*virtual*/ void AdventureGirl::Jump()
{
	this->create(m_vecJump[m_indexJump]);
	if (++m_indexRun > MAX_INDEX_JUMP)
	{
		m_indexRun = 0;
	}
}

const int MAX_INDEX_SHOOT = 2;
/*virtual*/ void AdventureGirl::Shoot()
{
	this->create(m_vecShoot[m_indexShoot]);
	if (++m_indexRun > MAX_INDEX_SHOOT)
	{
		m_indexShoot = 0;
	}
}


bool AdventureGirl::SkillQuicklyHitRobot(ManagerComponent& i_manager)
{
	int _weight = this->m_speed * 2;
	if (m_stateHitRobot == QuicklyHitRobot::MOVE_FORWARD)
	{
		if (this->getPositionX() + _weight >= m_positionEnd.x)
		{
			m_stateHitRobot = QuicklyHitRobot::MOVE_BACK;
		}
		else
		{
			this->setPositionX(this->getPositionX() + _weight);
		}
	}
	else
	{
		if (this->getPositionX() - _weight < m_positionBegin.x)
		{
			m_stateHitRobot = QuicklyHitRobot::MOVE_FORWARD;
			return false;
		}
		else
		{
			this->setPositionX(this->getPositionX() - _weight);
		}
	}

	return true;
}

/*virtual*/ void AdventureGirl::DeleteImageSkills(GameScene& i_gameScene)
{
	for (int i = 0; i < m_vecSkills.size(); i++)
	{
		i_gameScene.removeChild(m_vecSkills[i], true);
	}
	m_vecSkills.clear();
}

/*virtual*/ void AdventureGirl::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{
	
}

/*virtual*/ bool AdventureGirl::DetermineSkill(ManagerComponent& i_manager)
{
	if (m_vecSkills[INDEX_SKILL_QUICKLY_HIT_Robot]->getBoundingBox().containsPoint(i_manager.m_inputHero->GetLocationTouch()))
	{
		SetSkill(INDEX_SKILL_QUICKLY_HIT_Robot);
		return true;
	}

	return false;
}

/*virtual*/ void AdventureGirl::ShowImageSkills(GameScene& i_gameScene)
{
	m_vecSkills.push_back(Sprite::create(PATH_TO_RESOURCES + "/Skills/AdventureGirl/Robot.png"));
	m_vecSkills[0]->setScale(ChoiseHeroScene::m_visiblSize.width / m_vecSkills[0]->getContentSize().width / 15,
		ChoiseHeroScene::m_visiblSize.height / m_vecSkills[0]->getContentSize().height / 15);

	m_vecSkills[0]->setPosition(this->getPositionX(), this->getPositionY() + this->getContentSize().height);
	i_gameScene.addChild(m_vecSkills[0]);
}

AdventureGirl::~AdventureGirl()
{

}