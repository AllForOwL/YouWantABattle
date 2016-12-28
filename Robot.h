#ifndef __Robot_H__
#define __Robot_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;
class GameScene;

class Robot : public Warrior
{
public:
	Robot();
	Robot(const Robot& i_Robot);
	~Robot();

	// function act hero clean
	virtual void Run();
	virtual void Slide();
	virtual void Dead();
	virtual void Idle();
	virtual void Jump();
	// not clean
	virtual void MeleeJump();
	virtual void ShootJump();
	virtual void Shoot();
	virtual void ShootRun();

	// below function for skills
//	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);
	//virtual void DeleteImageSkills(GameScene& i_gameScene);
	//virtual void ShowImageSkills(GameScene& i_gameScene);
	//virtual bool DetermineSkill(ManagerComponent& i_manager);

	// here has been list all skills heroes
	bool SkillQuicklyHitRobot(ManagerComponent& i_manager);

	void LoadNameSprites();

private:
	vector<string>	m_vecMeleeJump;
	vector<string>	m_vecShoot;
	vector<string>	m_vecShootJump;
	vector<string>	m_vecShootRun;

	int m_indexMeleeJump;
	int m_indexShoot;
	int m_indexShootJump;
	int m_indexShootRun;
};

#endif 
