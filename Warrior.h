#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "cocos2d.h"

#include "GraphicComponent.h"
#include "ChoiseHeroScene.h"
#include "Bullet.h"
#include "Weapon.h"
#include "constants.h"
#include "HeroInputComponent.h"
#include "GameScene.h"

class GraphicComponent;
class ManagerComponent;

class Warrior : public GraphicComponent
{
public:

	enum State
	{
		ATTACK,
		ATTACK_JUMP,
		DEAD,
		DIZZY,
		IDLE,
		MELLE,
		MELEE_JUMP,
		JUMP,
		RUN,
		RUN_SHOOT,
		SHOOT,
		SHOOT_JUMP,
		SLIDE,
		THROW,
		THROW_JUMP,
		WALK,

		SET_DAMAGE,
		SHOW_IMAGE_SKILLS,
		DETERMINE_SKILL,
		EXECUTE_SKILLS
	};

	Warrior() 
	{
		m_state				= State::IDLE;
		m_health			= 100;
		m_startPositionY	= 0;

		m_indexRun	 = 0;
		m_indexMelee = 0;
		m_indexSlide = 0;
		m_indexDead  = 0;
		m_indexIdle  = 0;
		m_indexJump  = 0;
	};
	~Warrior() {};

	virtual void Update(ManagerComponent& i_manager, GameScene& i_gameScene)
	{
		switch (m_state)
		{
			case Warrior::ATTACK:
			{
				Attack();

				break;
			}
			case Warrior::ATTACK_JUMP:
			{
				AttackJump();

				break;
			}
			case Warrior::DEAD:
			{
				Dead();

				break;
			}
			case Warrior::DIZZY:
			{
				Dizzy();
				
				break;
			}
			case Warrior::IDLE:
			{
				Idle();

				break;
			}
			case Warrior::MELLE:
			{
				Melee();

				break;
			}
			case Warrior::MELEE_JUMP:
			{
				MeleeJump();

				break;
			}
			case Warrior::RUN:
			{
				Run();

				break;
			}
			case Warrior::RUN_SHOOT:
			{
				RunShoot();

			    break;
			}
			case Warrior::SHOOT:
			{
				Shoot();

				 break;
			}
			case Warrior::SHOOT_JUMP:
			{
				ShootJump();

				 break;
			}
			case Warrior::SLIDE:
			{
				Slide();

				 break;
			}
			case Warrior::THROW:
			{
				Throw();

				 break;
			}
			case Warrior::THROW_JUMP:
			{
				ThrowJump();

				break;
			}
			case Warrior::WALK:
			{
				Walk();

				 break;
			}
			case Warrior::SET_DAMAGE:
			{
				int _damage = 0;
				if (this->getPhysicsBody()->getTag() == TAG_HERO)
				{
					_damage = i_manager.m_bulletEnemy->GetDamage() + i_manager.m_weaponEnemy->GetDamage();
				}
				else
				{
					_damage = i_manager.m_bulletHero->GetDamage() + i_manager.m_weaponHero->GetDamage();
				}

				m_health -= _damage;

				break;
			}
			case Warrior::SHOW_IMAGE_SKILLS:
			{
				ShowImageSkills(i_gameScene);
				i_manager.m_inputHero->SetZeroLocation();

				m_state = Warrior::DETERMINE_SKILL;

				break;
			}
			case Warrior::DETERMINE_SKILL:
			{
				if (DetermineSkill(i_manager))
				{
					DeleteImageSkills(i_gameScene);
					m_state = Warrior::EXECUTE_SKILLS;
				}

				break;
			}
			case Warrior::EXECUTE_SKILLS:
			{
				ExecuteSkill(i_manager, m_numberSkill); 

				break;
			}
			default:
				break;
		}
	}

	// function act hero
	virtual void Melee() {};
	virtual void Shoot() {};
	virtual void Dizzy() {};
	virtual void Attack() {};
	virtual void AttackJump() {};
	virtual void Walk() {};
	virtual void Throw() {};
	virtual void ThrowJump() {};
	virtual void MeleeJump() {};
	virtual void ShootJump() {};
	virtual void RunShoot() {};
	virtual void Run()		= 0; 
	virtual void Slide()	= 0;
	virtual void Dead()		= 0;
	virtual void Idle()		= 0;
	virtual void Jump()		= 0;

	// function for skills
	virtual void ExecuteSkill(ManagerComponent& i_manager, int i_numberSkill) {};
	virtual void DeleteImageSkills(GameScene& i_gameScene) {};
	virtual void ShowImageSkills(GameScene& i_gameScene){};
	virtual bool DetermineSkill(ManagerComponent& i_manager){ return false; };
	void SetNumberSkill(int i_numberSkill)
	{
		m_numberSkill = i_numberSkill;
	}
	void SetState(State i_state)
	{
		m_state = i_state;
	}
	void SetSkill(int i_numberSkill)
	{
		m_numberSkill = i_numberSkill;
	}
	void SetDamage(int i_damage)
	{
		m_health -= i_damage;
	}

protected:
	vector<string>	m_vecDead;
	vector<string>	m_vecIdle;
	vector<string>	m_vecMelee;
	vector<string>	m_vecJump;
	vector<string>	m_vecRun;
	vector<string>	m_vecSlide;

	int	m_indexRun;
	int m_indexMelee;
	int m_indexSlide;
	int m_indexDead;
	int m_indexIdle;
	int m_indexJump;
	
	State	m_state;

	int m_startPositionY;

	int m_numberSkill;

	int m_damage;
	int m_health;
	int m_speed;
	int m_strength;
	int m_dexterity;
	int m_heightJump;
};

#endif 
