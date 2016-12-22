#ifndef __BOAR_H__
#define __BOAR_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Boar : public Warrior
{
public:
	Boar();
	Boar(const Boar& i_boar);
	~Boar();

	//virtual void Update(ManagerComponent& i_manager);

private:
};

#endif 
