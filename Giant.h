#ifndef __GIANT_H__
#define __GIANT_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;

class Giant : public Warrior
{
public:
	Giant();
	Giant(const Giant& i_Giant);
	~Giant();


	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);

//	virtual void Update(ManagerComponent& i_manager);


private:
};

#endif 
