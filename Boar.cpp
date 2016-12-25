#include "Boar.h"
#include "ChoiseHeroScene.h"
#include "ManagerComponent.h"
#include "HeroInputComponent.h"

const int SPEED		= 2;
const int STRENGTH	= 80;
const int DEXTERITY = 15;
const int HEIGHT_JUMP = 2;

const int INDEX_SKILL_QUICKLY_HIT_HORNS = 0;

Boar::Boar()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Boar.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;

	m_positionBegin = Point::ZERO;
	m_positionEnd = Point::ZERO;

	m_stateHitHorns = QuicklyHitHorns::MOVE_FORWARD;

}

Boar::Boar(const Boar& i_boar)
{

}

bool Boar::SkillQuicklyHitHorns(ManagerComponent& i_manager)
{
	int _weight = this->m_speed * 2;
	if (m_stateHitHorns == QuicklyHitHorns::MOVE_FORWARD)
	{
		if (this->getPositionX() + _weight >= m_positionEnd.x)
		{
			m_stateHitHorns = QuicklyHitHorns::MOVE_BACK;
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
			m_stateHitHorns = QuicklyHitHorns::MOVE_FORWARD;
			return false;
		}
		else
		{
			this->setPositionX(this->getPositionX() - _weight);
		}
	}

	return true;
}

/*virtual*/ void Boar::DeleteImageSkills(GameScene& i_gameScene)
{
	for (int i = 0; i < m_vecSkills.size(); i++)
	{
		i_gameScene.removeChild(m_vecSkills[i], true);
	}
	m_vecSkills.clear();
}

/*virtual*/ void Boar::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{
	switch (i_numberSkill)
	{
		case Skills::QUICKLY_HIT_HORNS:
		{
			if (m_positionBegin == Point::ZERO && m_positionEnd == Point::ZERO)
			{
				m_positionBegin = this->getPosition();
				m_positionEnd = this->getPosition();
				m_positionEnd.x -= i_manager.m_enemy->getBoundingBox().size.width;
			}
			
			if (!SkillQuicklyHitHorns(i_manager))
			{
				this->SetState(Warrior::State::NOTHING);
			}

			break;
		}
	default:
		break;
	}
}

/*virtual*/ bool Boar::DetermineSkill(ManagerComponent& i_manager)
{
	if (m_vecSkills[INDEX_SKILL_QUICKLY_HIT_HORNS]->getBoundingBox().containsPoint(i_manager.m_inputHero->GetLocationTouch()))
	{
		SetSkill(INDEX_SKILL_QUICKLY_HIT_HORNS);
		return true;
	}

	return false;
}

/*virtual*/ void Boar::ShowImageSkills(GameScene& i_gameScene)
{
	m_vecSkills.push_back(Sprite::create(PATH_TO_RESOURCES + "/Skills/Boar/Horns.png"));
	m_vecSkills[0]->setScale(ChoiseHeroScene::m_visiblSize.width / m_vecSkills[0]->getContentSize().width / 15,
		ChoiseHeroScene::m_visiblSize.height / m_vecSkills[0]->getContentSize().height / 15);

	m_vecSkills[0]->setPosition(this->getPositionX(), this->getPositionY() + this->getContentSize().height);
	i_gameScene.addChild(m_vecSkills[0]);
}

Boar::~Boar()
{

}