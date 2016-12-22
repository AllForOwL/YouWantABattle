#ifndef __WIZARD_H__
#define __WIZARD_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Wizard : public Warrior
{
public:
	Wizard();
	Wizard(const Wizard& i_Wizard);
	~Wizard();

	//virtual void Update(ManagerComponent& i_manager);


private:
};

#endif 
