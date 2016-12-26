#ifndef __Crocodile_H__
#define __Crocodile_H__

#include "cocos2d.h"

#include "Weapon.h"

USING_NS_CC;

using std::string;
using std::vector;

class Weapon;
class ManagerComponent;

class Crocodile : public Weapon
{
public:
	Crocodile();
	Crocodile(const Crocodile& i_Crocodile);
	~Crocodile();

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
	// not clean
	virtual void Dizzy();

	// below function for skills
	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);
	virtual void DeleteImageSkills(GameScene& i_gameScene);
	virtual void ShowImageSkills(GameScene& i_gameScene);
	virtual bool DetermineSkill(ManagerComponent& i_manager);

	// here has been list all skills heroes
	bool SkillQuicklyHitRobot(ManagerComponent& i_manager);

private:

};

#endif 
