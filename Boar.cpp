#include "Boar.h"
#include "ChoiseHeroScene.h"
#include "ManagerComponent.h"

const int SPEED		= 2;
const int STRENGTH	= 80;
const int DEXTERITY = 15;
const int HEIGHT_JUMP = 2;

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
		if (this->getPositionX() + _weight > m_positionEnd.x)
		{
			_weight = m_positionEnd.x - this->getPositionX();
		}
		else
		{
			this->setPositionX(this->getPositionX() + _weight);
			m_stateHitHorns = QuicklyHitHorns::MOVE_BACK;
		}
	}
	else
	{
		if (this->getPositionX() - _weight < m_positionBegin.x)
		{
			_weight = this->getPositionX() - m_positionBegin.x;
		}
		else
		{
			this->setPositionX(this->getPositionX() - _weight);
			return false;
		}
	}

	return true;
}

/*virtual*/ void Boar::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{
	switch (m_skill)
	{
		case Skills::QUICKLY_HIT_HORNS:
		{
			if (m_positionBegin == Point::ZERO && m_positionEnd == Point::ZERO)
			{
				m_positionBegin = i_manager.m_hero->getPosition();
				m_positionEnd = i_manager.m_enemy->getPosition();
			}
			
			if (!SkillQuicklyHitHorns(i_manager))
			{
				i_manager.m_hero->SetState(Warrior::State::NOTHING);
			}

			break;
		}
	default:
		break;
	}
}

/*virtual*/ bool Boar::DetermineSkill()
{
	// here has been determine touch on skill

	return false;
}

/*virtual*/ void Boar::ShowImageSkills()
{
	// here has been load image skills
}

Boar::~Boar()
{

}