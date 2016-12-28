#ifndef __AdventureGirl_H__
#define __AdventureGirl_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;
class ManagerComponent;

class AdventureGirl : public Warrior
{
public:

	enum Skills
	{
		QUICKLY_HIT_Robot
	};

	enum QuicklyHitRobot
	{
		MOVE_FORWARD,
		MOVE_BACK
	};

	AdventureGirl();
	AdventureGirl(const AdventureGirl& i_AdventureGirl);
	~AdventureGirl();
	
	// function act hero clean
	virtual void Dead();
	virtual void Idle();
	virtual void Melee();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void MoveUp();
	virtual void Run();
	virtual void Slide();
	// not clean
	virtual void Shoot();

	// load image
	void LoadNameSprites();

	// below function for skills
	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);
	virtual void DeleteImageSkills(GameScene& i_gameScene);
	virtual void ShowImageSkills(GameScene& i_gameScene);
	virtual bool DetermineSkill(ManagerComponent& i_manager);

	// here has been list all skills heroes
	bool SkillQuicklyHitRobot(ManagerComponent& i_manager);

private:
	vector<string>	m_vecDead;
	vector<string>	m_vecIdle;
	vector<string>	m_vecMelee;
	vector<string>	m_vecShoot;
	vector<string>	m_vecJump;
	vector<string>	m_vecRun;
	vector<string>	m_vecSlide;

	QuicklyHitRobot m_stateHitRobot;
	Skills	m_skill;
	Point m_positionBegin;
	Point m_positionEnd;

	vector<Sprite*> m_vecSkills;
};

#endif 
