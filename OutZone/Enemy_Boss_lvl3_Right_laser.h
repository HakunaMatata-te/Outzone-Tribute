#ifndef __ENEMY_BOSS_LVL3_RIGHT_LASER_H__
#define __ENEMY_BOSS_LVL3_RIGHT_LASER_H__

#include "Enemy.h"




class Enemy_Boss_R_Laser : public Enemy
{
private:
	Animation idle;
	Animation shooting;
	Animation turn_left;
	Animation turn_idle;

	uint Timer;
	bool Timer_state;
	uint sTimer;
	bool sTimer_state;
	LMOVEMENT stage;

public:
	Enemy_Boss_R_Laser(int x, int y, uint typemove, ENEMY_TYPES type);


	void death();
	void Move();
};



#endif // !__ENEMY_BOSS_LVL3_RIGHT_LASER_H__