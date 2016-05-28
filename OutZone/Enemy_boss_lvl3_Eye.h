#ifndef __ENEMY_BOSS_LVL3_EYE_H__
#define __ENEMY_BOSS_LVL3_EYE_H__

#include "Enemy.h"

enum PROGRESS
{
	CLOSE,
	OPENING,
	OPEN,
	CLOSING
};

class Enemy_Boss_Eye : public Enemy
{
private:
	Animation opening;
	Animation closing;
	Animation closed;
	Animation opened;
	PROGRESS stage;
	uint shotTimer;
	uint Timer;
	


public:
	Enemy_Boss_Eye(int x, int y, uint typemove, ENEMY_TYPES type, bool boss);
	void death();
	void Move();
};

#endif // !__ENEMY_BOSS_LVL3_EYE_H__
