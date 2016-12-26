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

void AdventureGirl::LoadNameSprites()
{

}

/*virtual*/ void AdventureGirl::Run()
{

}

/*virtual*/ void AdventureGirl::Melee()
{

}

/*virtual*/ void AdventureGirl::Slide()
{

}

/*virtual*/ void AdventureGirl::Dead()
{

}

/*virtual*/ void AdventureGirl::Idle()
{

}

/*virtual*/ void AdventureGirl::MoveUp()
{

}

/*virtual*/ void AdventureGirl::MoveDown()
{

}

/*virtual*/ void AdventureGirl::MoveRight()
{

}

/*virtual*/ void AdventureGirl::MoveLeft()
{

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
	switch (i_numberSkill)
	{
		case Skills::QUICKLY_HIT_Robot:
		{
			if (m_positionBegin == Point::ZERO && m_positionEnd == Point::ZERO)
			{
				m_positionBegin = this->getPosition();
				m_positionEnd = this->getPosition();
				m_positionEnd.x -= i_manager.m_enemy->getBoundingBox().size.width;
			}
			
			if (!SkillQuicklyHitRobot(i_manager))
			{
				this->SetState(Warrior::State::NOTHING);
			}

			break;
		}
	default:
		break;
	}
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