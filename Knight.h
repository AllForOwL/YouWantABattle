#ifndef __KNIGHT_H__
#define __KNIGTH_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;

class Knight : public Warrior
{
public:
	Knight();
	Knight(const Knight& i_Knight);
	~Knight();

	// function act hero clean
	virtual void Run();
	virtual void Melee();
	virtual void Slide();
	virtual void Dead();
	virtual void Idle();
	virtual void Jump();
	// not clean
	virtual void Attack();
	virtual void AttackJump();
	virtual void Walk();
	virtual void Shoot();

	// below function for skills
	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);
	virtual void DeleteImageSkills(GameScene& i_gameScene);
	virtual void ShowImageSkills(GameScene& i_gameScene);
	virtual bool DetermineSkill(ManagerComponent& i_manager);

	// here has been list all skills heroes
	bool SkillQuicklyHitRobot(ManagerComponent& i_manager);

	void LoadNameSprites();

private:
	vector<string>	m_vecAttack;
	vector<string>	m_vecAttackJump;
	vector<string>	m_vecShoot;
	vector<string>	m_vecWalk;

	int m_indexAttack;
	int m_indexAttackJump;
	int m_indexShoot;
	int m_indexWalk;
};

#endif 
