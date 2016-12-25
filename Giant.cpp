#include "Giant.h"
#include "ChoiseHeroScene.h"
#include "HeroInputComponent.h"

const int SPEED		= 1;
const int STRENGTH	= 90;
const int DEXTERITY = 10;
const int HEIGHT_JUMP = 1;

const int INDEX_JUMP_AND_HIT = 0;

Giant::Giant()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Giant.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;

	m_skillJumpAndHit = JumpAndHit::MOVE_FORWARD_UP;
}

Giant::Giant(const Giant& i_Giant)
{

}

bool Giant::SkillJumpAndHit(ManagerComponent& i_manager)
{
	if (m_skillJumpAndHit == JumpAndHit::MOVE_FORWARD_UP)
	{
		this->setPosition(this->getPositionX() + 1, this->getPositionY() + 1);
		if (this->getPositionX() - m_positionBegin.x >= (m_distanceToEnemy / 2))
		{
			m_skillJumpAndHit = JumpAndHit::MOVE_FORWARD_DOWN;
		}
	}
	else if (m_skillJumpAndHit == JumpAndHit::MOVE_FORWARD_DOWN)
	{
		this->setPosition(this->getPositionX() + 1, this->getPositionY() - 1);
		if (this->getPositionY() == m_positionEnd.y)
		{
			m_skillJumpAndHit = JumpAndHit::MOVE_BACK;
		}
	}
	else
	{
		this->setPositionX(this->getPositionX() - 1);
		if (this->getPositionX() <= m_positionBegin.x)
		{
			m_skillJumpAndHit = JumpAndHit::MOVE_FORWARD_UP;
			m_positionBegin = Point::ZERO;
			m_positionEnd = Point::ZERO;
			return false;
		}
	}
	return true;
}

/*virtual*/ void Giant::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{
	switch (i_numberSkill)
	{
		case Skills::JUMP_AND_HIT:
		{
			if (m_positionBegin == Point::ZERO && m_positionEnd == Point::ZERO)
			{
				m_positionBegin = this->getPosition();
				m_positionEnd = i_manager.m_enemy->getPosition();
				m_positionEnd.x -= i_manager.m_enemy->getBoundingBox().size.width;
				m_distanceToEnemy = m_positionEnd.x - m_positionBegin.x;
			}
			
			if (!SkillJumpAndHit(i_manager))
			{
				this->SetState(Warrior::State::NOTHING);
			}

			break;
		}
	default:
		break;
	}
}

/*virtual*/ void Giant::DeleteImageSkills(GameScene& i_gameScene)
{
	for (int i = 0; i < m_vecImageSkills.size(); i++)
	{
		i_gameScene.removeChild(m_vecImageSkills[i], true);
	}
	m_vecImageSkills.clear();
}

/*virtual*/ void Giant::ShowImageSkills(GameScene& i_gameScene)
{
	m_vecImageSkills.push_back(Sprite::create(PATH_TO_RESOURCES + "/Skills/Giant/JumpAndHit.png"));
	m_vecImageSkills[INDEX_JUMP_AND_HIT]->setScale(ChoiseHeroScene::m_visiblSize.width / m_vecImageSkills[INDEX_JUMP_AND_HIT]->getContentSize().width / 15,
		ChoiseHeroScene::m_visiblSize.height / m_vecImageSkills[INDEX_JUMP_AND_HIT]->getContentSize().height / 15);
	m_vecImageSkills[INDEX_JUMP_AND_HIT]->setPosition(this->getPositionX(), this->getPositionY() + this->getContentSize().height);

	i_gameScene.addChild(m_vecImageSkills[0]);
}

/*virtual*/ bool Giant::DetermineSkill(ManagerComponent& i_manager)
{
	if (m_vecImageSkills[INDEX_JUMP_AND_HIT]->getBoundingBox().containsPoint(i_manager.m_inputHero->GetLocationTouch()))
	{
		SetSkill(INDEX_JUMP_AND_HIT);
		return true;
	}

	return false;
}

Giant::~Giant()
{
}