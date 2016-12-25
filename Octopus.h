#ifndef __OCTOPUS_H__
#define __OCTOPUS_H__

#include "cocos2d.h"

#include "Warrior.h"
#include "GameScene.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;

class Octopus : public Warrior
{
public:

	enum Skills
	{
		HIT_TENTACLES,
		NOTHING
	};

	enum HitTentacles
	{
		MOVE_FORWARD
	};

	Octopus();
	Octopus(const Octopus& i_Octopus);
	~Octopus();

	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);	
	virtual void DeleteImageSkills(GameScene& i_gameScene);
	virtual void ShowImageSkills(GameScene& i_gameScene);
	virtual bool DetermineSkill(ManagerComponent& i_manager);

	// below list skills
	bool SkillHitTentacles(ManagerComponent& i_manager);
	
private:
	HitTentacles	m_stateHitTentacles;
	Skills			m_skill;
	Point			m_positionBegin;
	Point			m_positionEnd;

	vector<Sprite*> m_vecSkills;


};

#endif 
