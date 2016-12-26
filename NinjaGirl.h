#ifndef __NinjaGirl_H__
#define __NinjaGirl_H__

#include "cocos2d.h"

#include "Warrior.h"

#include "GameScene.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;

class NinjaGirl : public Warrior
{
public:

	enum Skills
	{
		JUMP_AND_HIT
	};

	enum JumpAndHit
	{
		MOVE_FORWARD_UP,
		MOVE_FORWARD_DOWN,
		MOVE_BACK
	};

	NinjaGirl();
	NinjaGirl(const NinjaGirl& i_NinjaGirl);
	~NinjaGirl();

	// function act hero
	virtual void Run();
	virtual void Melee();
	virtual void Slide();
	virtual void Dead();
	virtual void Idle();
	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveRight();
	virtual void MoveLeft();

	// below function for skills
	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);
	virtual void DeleteImageSkills(GameScene& i_gameScene);
	virtual void ShowImageSkills(GameScene& i_gameScene);
	virtual bool DetermineSkill(ManagerComponent& i_manager);

	// here has been list all skills heroes
	bool SkillQuicklyHitRobot(ManagerComponent& i_manager);

private:
	JumpAndHit m_skillJumpAndHit;

	Skills m_skill;
	Point m_positionBegin;
	Point m_positionEnd;
	int	m_distanceToEnemy;

	vector<Sprite*>	m_vecImageSkills;
};

#endif 
