#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

#include "GraphicComponent.h"

class ManagerComponent;

class Bullet : public GraphicComponent
{
public:
	Bullet();
	~Bullet();

	virtual void Update(ManagerComponent& i_manager) = 0;
};

#endif 
