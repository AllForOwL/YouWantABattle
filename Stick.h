#ifndef __Stick_H__
#define __Stick_H__

#include "cocos2d.h"

#include "Weapon.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Stick : public Weapon
{
public:
	Stick();
	Stick(const Stick& i_Stick);
	~Stick();

	virtual void Update(ManagerComponent& i_manager);

private:
};

#endif 
