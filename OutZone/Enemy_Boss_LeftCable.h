#ifndef __ENEMY_BOSS_LEFTCABLE_H__
#define __ENEMY_BOSS_LEFTCABLE_H__

#include "Enemy.h"

class Enemy_Boss_LCable : public Enemy
{
private:
	Animation idle;

	uint Timer;
	bool Timer_state;

public:
	Enemy_Boss_LCable(int x, int y, uint typemove, ENEMY_TYPES type);

	void death();
	void Move();
};


#endif // !__ENEMY_BOSS_LEFTCABLE_H__


