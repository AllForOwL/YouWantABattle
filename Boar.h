#ifndef __BOAR_H__
#define __BOAR_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;
class ManagerComponent;

class Boar : public Warrior
{
public:

	enum Skills
	{
		QUICKLY_HIT_HORNS
	};

	enum QuicklyHitHorns
	{
		MOVE_FORWARD,
		MOVE_BACK
	};

	Boar();
	Boar(const Boar& i_boar);
	~Boar();

//	virtual void Update(ManagerComponent& i_manager);

	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);

	virtual void ShowImageSkills();

	bool SkillQuicklyHitHorns(ManagerComponent& i_manager);

	virtual bool DetermineSkill();

private:
	QuicklyHitHorns m_stateHitHorns;
	Skills	m_skill;
	Point m_positionBegin;
	Point m_positionEnd;
};

#endif 
