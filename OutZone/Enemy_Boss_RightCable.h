#ifndef __ENEMY_BOSS_RIGHTCABLE_H__
#define __ENEMY_BOSS_RIGHTCABLE_H__

#include "Enemy.h"


class Enemy_Boss_RCable : public Enemy
{
private:
	Animation idle;
	LMOVEMENT stage;
	uint Timer;
	bool Timer_state;

public:
	Enemy_Boss_RCable(int x, int y, uint typemove, ENEMY_TYPES type, bool boss);

	void death();
	void Move();
};


#endif // !__ENEMY_BOSS_RIGHTCABLE_H__
