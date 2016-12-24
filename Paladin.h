#ifndef __PALADIN_H__
#define __PALADIN_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class Warrior;

class Paladin : public Warrior
{
public:
	Paladin();
	Paladin(const Paladin& i_Paladin);
	~Paladin();

	//virtual void Update(ManagerComponent& i_manager);


private:
};

#endif 
