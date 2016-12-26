#include "NinjaGirl.h"
#include "ChoiseHeroScene.h"
#include "HeroInputComponent.h"

const int SPEED		= 1;
const int STRENGTH	= 90;
const int DEXTERITY = 10;
const int HEIGHT_JUMP = 1;

const int INDEX_JUMP_AND_HIT = 0;

NinjaGirl::NinjaGirl()
{
	this->initWithFile(PATH_TO_RESOURCES + "/MenuItems/NinjaGirl.png");
	this->setScale(ChoiseHeroScene::m_visiblSize.width / this->getContentSize().width / SCALE_X,
		ChoiseHeroScene::m_visiblSize.height / this->getContentSize().height / SCALE_Y);

	m_speed		= SPEED;
	m_strength	= STRENGTH;
	m_dexterity = DEXTERITY;
	m_heightJump = HEIGHT_JUMP;

	m_skillJumpAndHit = JumpAndHit::MOVE_FORWARD_UP;
}

NinjaGirl::NinjaGirl(const NinjaGirl& i_NinjaGirl)
{

}

/*virtual*/ void NinjaGirl::Run()
{

}

/*virtual*/ void NinjaGirl::Melee()
{

}

/*virtual*/ void NinjaGirl::Slide()
{

}

/*virtual*/ void NinjaGirl::Dead()
{

}

/*virtual*/ void NinjaGirl::Idle()
{

}

/*virtual*/ void NinjaGirl::MoveUp()
{

}

/*virtual*/ void NinjaGirl::MoveDown()
{

}

/*virtual*/ void NinjaGirl::MoveRight()
{

}

/*virtual*/ void NinjaGirl::MoveLeft()
{

}

/*virtual*/ void NinjaGirl::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
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

/*virtual*/ void NinjaGirl::DeleteImageSkills(GameScene& i_gameScene)
{
	for (int i = 0; i < m_vecImageSkills.size(); i++)
	{
		i_gameScene.removeChild(m_vecImageSkills[i], true);
	}
	m_vecImageSkills.clear();
}

/*virtual*/ void NinjaGirl::ShowImageSkills(GameScene& i_gameScene)
{
	m_vecImageSkills.push_back(Sprite::create(PATH_TO_RESOURCES + "/Skills/NinjaGirl/JumpAndHit.png"));
	m_vecImageSkills[INDEX_JUMP_AND_HIT]->setScale(ChoiseHeroScene::m_visiblSize.width / m_vecImageSkills[INDEX_JUMP_AND_HIT]->getContentSize().width / 15,
		ChoiseHeroScene::m_visiblSize.height / m_vecImageSkills[INDEX_JUMP_AND_HIT]->getContentSize().height / 15);
	m_vecImageSkills[INDEX_JUMP_AND_HIT]->setPosition(this->getPositionX(), this->getPositionY() + this->getContentSize().height);

	i_gameScene.addChild(m_vecImageSkills[0]);
}

/*virtual*/ bool NinjaGirl::DetermineSkill(ManagerComponent& i_manager)
{
	if (m_vecImageSkills[INDEX_JUMP_AND_HIT]->getBoundingBox().containsPoint(i_manager.m_inputHero->GetLocationTouch()))
	{
		SetSkill(INDEX_JUMP_AND_HIT);
		return true;
	}

	return false;
}

NinjaGirl::~NinjaGirl()
{
}