#ifndef __YETI_H__
#define __YETI_H__

#include "cocos2d.h"

#include "Warrior.h"

USING_NS_CC;

using std::string;
using std::vector;

class ManagerComponent;

class Yeti : public Warrior
{
public:
	Yeti();
	Yeti(const Yeti& i_Yeti);
	~Yeti();

	//virtual void Update(ManagerComponent& i_manager);

private:
};

#endif 
