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

const int SPRITES_NINE = 9;
const int MAX_INDEX = 8;

void NinjaGirl::LoadNameSprites()
{
	for (int i = 0; i <= SPRITES_NINE; i++)
	{
		m_vecDead.push_back(PATH_TO_RESOURCES		+ "/Heroes/NinjaGirl/Dead/Dead__00"				+ std::to_string(i));
		m_vecIdle.push_back(PATH_TO_RESOURCES		+ "/Heroes/NinjaGirl/Idle/Idle__00"				+ std::to_string(i));
		m_vecJump.push_back(PATH_TO_RESOURCES		+ "/Heroes/NinjaGirl/Jump/Jump__00"				+ std::to_string(i));
		m_vecMelee.push_back(PATH_TO_RESOURCES		+ "/Heroes/NinjaGirl/Melee/Melee__00"			+ std::to_string(i));
		m_vecRun.push_back(PATH_TO_RESOURCES		+ "/Heroes/NinjaGirl/Run/Run__00"				+ std::to_string(i));
		m_vecSlide.push_back(PATH_TO_RESOURCES		+ "/Heroes/NinjaGirl/Slide/Slide__00"			+ std::to_string(i));
		m_vecThrow.push_back(PATH_TO_RESOURCES		+ "/Heroes/NinjaGirl/Throw/Throw__00"			+ std::to_string(i));
		m_vecThrowJump.push_back(PATH_TO_RESOURCES	+ "/Heroes/NinjaGirl/ThrowJump/ThrowJump__00"	+ std::to_string(i));
		m_vecAttack.push_back(PATH_TO_RESOURCES		+ "/Heroes/NinjaGirl/Attack/Attack__00"			+ std::to_string(i));
		m_vecAttackJump.push_back(PATH_TO_RESOURCES + "/Heroes/NinjaGirl/AttackJump/AttackJump__00" + std::to_string(i));
	}
}

/*virtual*/ void NinjaGirl::Run()
{
	this->create(m_vecRun[m_indexRun]);
	if (++m_indexRun > MAX_INDEX)
	{
		m_indexRun = 0;
	}
}

/*virtual*/ void NinjaGirl::Slide()
{
	this->create(m_vecSlide[m_indexSlide]);
	if (++m_indexSlide > MAX_INDEX)
	{
		m_indexSlide = 0;
	}
}

/*virtual*/ void NinjaGirl::Dead()
{
	this->create(m_vecDead[m_indexDead]);
	if (++m_indexDead > MAX_INDEX)
	{
		m_indexDead = 0;
	}
}

/*virtual*/ void NinjaGirl::Idle()
{
	this->create(m_vecIdle[m_indexIdle]);
	if (++m_indexIdle > MAX_INDEX)
	{
		m_indexIdle = 0;
	}
}

/*virtual*/ void NinjaGirl::Jump()
{
	this->create(m_vecJump[m_indexJump]);
	if (++m_indexJump > MAX_INDEX)
	{
		m_indexJump = 0;
	}
}

/*virtual*/ void NinjaGirl::Throw()
{
	this->create(m_vecThrow[m_indexThrow]);
	if (++m_indexThrow > MAX_INDEX)
	{
		m_indexThrow = 0;
	}
}

/*virtual*/ void NinjaGirl::ThrowJump()
{
	this->create(m_vecThrowJump[m_indexThrowJump]);
	if (++m_indexThrowJump > MAX_INDEX)
	{
		m_indexThrowJump = 0;
	}
}

/*virtual*/ void NinjaGirl::Attack()
{
	this->create(m_vecAttack[m_indexAttack]);
	if (++m_indexAttack > MAX_INDEX)
	{
		m_indexAttack = 0;
	}
}

/*virtual*/ void NinjaGirl::AttackJump()
{
	this->create(m_vecAttackJump[m_indexAttackJump]);
	if (++m_indexAttackJump > MAX_INDEX)
	{
		m_indexAttackJump = 0;
	}
}

/*virtual*/ void NinjaGirl::ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill)
{
	
}

NinjaGirl::~NinjaGirl()
{
}