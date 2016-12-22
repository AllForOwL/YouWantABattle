#ifndef __OCTOPUS_H__
#define __OCTOPUS_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Octopus : public Warrior
{
public:
	Octopus();
	Octopus(const Octopus& i_Octopus);
	~Octopus();

	//virtual void Update(ManagerComponent& i_manager);


private:
};

#endif 
