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

	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill);


	//virtual void Update(ManagerComponent& i_manager);


private:
};

#endif 
