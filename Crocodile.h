#ifndef __Crocodile_H__
#define __Crocodile_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Crocodile : public Warrior
{
public:
	Crocodile();
	Crocodile(const Crocodile& i_Crocodile);
	~Crocodile();

	// function act hero clean
	virtual void Run();
	virtual void Slide();
	virtual void Dead();
	virtual void Idle();
	virtual void Jump();
	// not clean
	virtual void Dizzy();
	virtual void Shoot();

	// below function for skills
	//virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);
	//virtual void DeleteImageSkills(GameScene& i_gameScene);
	//virtual void ShowImageSkills(GameScene& i_gameScene);
	//virtual bool DetermineSkill(ManagerComponent& i_manager);

	// here has been list all skills heroes
	bool SkillQuicklyHitRobot(ManagerComponent& i_manager);

	void LoadNameSprites();

private:
	vector<string>	m_vecShoot;
	vector<string>	m_vecDizzy;

	int m_indexDizzy;
	int m_indexShoot;
};

#endif 
