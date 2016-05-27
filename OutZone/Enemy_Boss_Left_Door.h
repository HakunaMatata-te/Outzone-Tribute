#ifndef __ENEMY_BOSS_LEFTDOOR_H__
#define __ENEMY_BOSS_LEFTDOOR_H__

#include "Enemy.h"



class Enemy_Boss_LDoor : public Enemy
{
private:
	Animation closed;
	Animation opened;
	Animation opening;
	Animation closing;
	LMOVEMENT stage;
	uint Timer;
	bool Timer_state;

public:
	Enemy_Boss_LDoor(int x, int y, uint typemove, ENEMY_TYPES type);

	void death();
	void Move();
};


#endif // !__ENEMY_BOSS_LEFTDOOR_H__