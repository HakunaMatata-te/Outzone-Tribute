#ifndef __BOSS_RIGHT_PLATFORM_H__
#define __BOSS_RIGHT_PLATFORM_H__

#include "Enemy.h"



class Boss_RPlat : public Enemy
{
private:
	Animation idle;

	LMOVEMENT stage;
	uint Timer;
	bool Timer_state;

public:
	Boss_RPlat(int x, int y, uint typemove, ENEMY_TYPES type, bool boss);

	void death();
	void Move();
};


#endif // !__BOSS_LEFT_PLATFORM_H__