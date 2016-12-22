#ifndef __BOWMAN_H__
#define __BOWMAN_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Bowman : public Warrior
{
public:
	Bowman();
	Bowman(const Bowman& i_bowman);
	~Bowman();

	//virtual void Update(ManagerComponent& i_manager);


private:
};

#endif 
