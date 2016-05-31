#ifndef __BOSS_LEFT_PLATFORM_H__
#define __BOSS_LEFT_PLATFORM_H__

#include "Enemy.h"



class Boss_LPlat : public Enemy
{
private:
	Animation idle;
	
	LMOVEMENT stage;
	Uint32 Timer;
	bool Timer_state;

public:
	Boss_LPlat(int x, int y, uint typemove, ENEMY_TYPES type, bool boss);

	void death();
	void Move();
};


#endif // !__BOSS_LEFT_PLATFORM_H__