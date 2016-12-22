#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

#include "GraphicComponent.h"

class ManagerComponent;
class GameScene;


using std::string;

class Bullet : public GraphicComponent
{
public:
	Bullet();
	Bullet(const Bullet& i_bullet);
	Bullet(int i_type);
	~Bullet();

	void Update(ManagerComponent& i_manager, GameScene& i_gameScene);

	void SetImage();
	int GetDamage() const;

private:
	int m_type;
	int m_speed;
	int m_damage;
};

#endif 
