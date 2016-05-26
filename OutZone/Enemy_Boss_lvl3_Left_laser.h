#ifndef __ENEMY_BOSS_LVL3_LEFT_LASER_H__
#define __ENEMY_BOSS_LVL3_LEFT_LASER_H__

#include "Enemy.h"

enum LMOVEMENT
{
	START,
	TURN_RIGHT,
	LASER_CREATION,
	LASER_MOVE,
	TURN_IDLE,
	RETREAT,
	FINISHED
};


class Enemy_Boss_L_Laser : public Enemy
{
private:
	Animation idle;
	Animation shooting;
	Animation turn_right;
	Animation turn_idle;

	uint Timer;
	bool Timer_state;
	uint sTimer;
	bool sTimer_state;
	LMOVEMENT stage;

public:
	Enemy_Boss_L_Laser(int x, int y, uint typemove, ENEMY_TYPES type);


	void death();
	void Move();
};



#endif // !__ENEMY_BOSS_LVL3_LEFT_LASER_H__
