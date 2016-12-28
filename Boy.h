#ifndef __Boy_H__
#define __Boy_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;
class GraphicComponent;

class Boy : public Warrior
{
public:
	Boy();
	Boy(const Boy& i_Boy);
	~Boy();

	// function act hero clean
	virtual void Run();
	virtual void Melee();
	virtual void Slide();
	virtual void Dead();
	virtual void Idle();
	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveRight();
	virtual void MoveLeft();
	// not clean nothing


	// below function for skills
	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);
	virtual void DeleteImageSkills(GameScene& i_gameScene);
	virtual void ShowImageSkills(GameScene& i_gameScene);
	virtual bool DetermineSkill(ManagerComponent& i_manager);

	// here has been list all skills heroes
	bool SkillQuicklyHitRobot(ManagerComponent& i_manager);

	void LoadNameSprites();

private:
	vector<string>	m_vecDead;
	vector<string>	m_vecIdle;
	vector<string>	m_vecMelee;
	vector<string>	m_vecJump;
	vector<string>	m_vecRun;
	vector<string>	m_vecSlide;

};

#endif 
