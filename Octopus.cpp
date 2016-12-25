#include "Octopus.h"
#include "ChoiseHeroScene.h"

const int SPEED		= 4;
const int STRENGTH	= 50;
const int DEXTERITY = 45;
const int HEIGHT_JUMP = 4;

const int INDEX_HIT_TENTACLES = 0;

Octopus::Octopus()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/Octopus.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;

	m_skill = Skills::NOTHING;
	m_stateHitTentacles = HitTentacles::MOVE_FORWARD;
}

Octopus::Octopus(const Octopus& i_Octopus)
{

}

bool Octopus::SkillHitTentacles(ManagerComponent& i_manager)
{
	m_vecSkills[INDEX_HIT_TENTACLES]->setPositionX(m_vecSkills[INDEX_HIT_TENTACLES]->getPositionX() + 1);
	if (m_vecSkills[INDEX_HIT_TENTACLES]->getPositionX() >= m_positionEnd.x)
	{
		m_positionBegin = Point::ZERO;
		m_positionEnd	= Point::ZERO;

		return false;
	}

	return true;
}

/*virtual*/ void Octopus::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{
	switch (i_numberSkill)
	{
		case Skills::HIT_TENTACLES:
		{
			if (m_positionBegin == Point::ZERO && m_positionEnd == Point::ZERO)
			{
				m_positionBegin = this->getPosition();
				m_positionEnd = i_manager.m_enemy->getPosition();
				m_vecSkills[INDEX_HIT_TENTACLES]->setPosition(m_positionBegin.x + this->getBoundingBox().size.width / 2, this->getPositionY());
			}
			
			if (!SkillHitTentacles(i_manager))
			{
				i_manager.m_hero->SetState(Warrior::State::NOTHING);
			}

			break;
		}
	default:
		break;
	}
}

/*virtual*/ void Octopus::DeleteImageSkills(GameScene& i_gameScene)
{
	//i_gameScene.removeChild(m_vecSkills[0], true);
	//m_vecSkills.clear();
}

/*virtual*/ void Octopus::ShowImageSkills(GameScene& i_gameScene)
{
	m_vecSkills.push_back(Sprite::create(PATH_TO_RESOURCES + "/Skills/Octopus/HitTentacles.png"));
	m_vecSkills[INDEX_HIT_TENTACLES]->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / 25,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / 25);
	m_vecSkills[INDEX_HIT_TENTACLES]->setPosition(this->getPositionX(), this->getPositionY() + this->getContentSize().width);
	i_gameScene.addChild(m_vecSkills[INDEX_HIT_TENTACLES]);
}

/*virtual*/ bool Octopus::DetermineSkill(ManagerComponent& i_manager)
{
	if (m_vecSkills[INDEX_HIT_TENTACLES]->getBoundingBox().containsPoint(i_manager.m_inputHero->GetLocationTouch()))
	{
		SetSkill(INDEX_HIT_TENTACLES);
		return true;
	}
	return false;
}

Octopus::~Octopus()
{
}