#ifndef __GIANT_H__
#define __GIANT_H__

#include "cocos2d.h"

#include "Warrior.h"

#include "GameScene.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;

class Giant : public Warrior
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

	Giant();
	Giant(const Giant& i_Giant);
	~Giant();


	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);
	virtual void DeleteImageSkills(GameScene& i_gameScene);
	virtual void ShowImageSkills(GameScene& i_gameScene);
	virtual bool DetermineSkill(ManagerComponent& i_manager);

	// below list from skill
	bool SkillJumpAndHit(ManagerComponent& i_manager);

private:
	JumpAndHit m_skillJumpAndHit;

	Skills m_skill;
	Point m_positionBegin;
	Point m_positionEnd;
	int	m_distanceToEnemy;

	vector<Sprite*>	m_vecImageSkills;
};

#endif 
