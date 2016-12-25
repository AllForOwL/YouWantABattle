#ifndef __OCTOPUS_H__
#define __OCTOPUS_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;

class Octopus : public Warrior
{
public:
	Octopus();
	Octopus(const Octopus& i_Octopus);
	~Octopus();

	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);	
	virtual void DeleteImageSkills();
	virtual void ShowImageSkills();
	virtual bool DetermineSkills(ManagerComponent& i_manager);

private:
};

#endif 
