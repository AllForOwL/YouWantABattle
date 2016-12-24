#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

#include "GraphicComponent.h"

using std::string;

class GraphicComponent;

class Bullet : public GraphicComponent
{
public:
	Bullet();
	Bullet(const Bullet& i_bullet);
	Bullet(int i_type);
	~Bullet();

	void Update();

	void SetImage();
	int GetDamage() const;

private:
	int m_type;
	int m_speed;
	int m_damage;
};

#endif 
