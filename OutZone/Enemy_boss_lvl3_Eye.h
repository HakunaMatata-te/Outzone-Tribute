#ifndef __ENEMY_BOSS_LVL3_EYE_H__
#define __ENEMY_BOSS_LVL3_EYE_H__

#include "Enemy.h"

class Enemy_Boss_Eye : public Enemy
{
private:
	Animation shoot;
	Animation closed;
	bool open;
	uint closeTimer;
	uint openTimer;


public:
	Enemy_Boss_Eye(int x, int y, uint typemove);
	void death();
	void Move();
};

#endif // !__ENEMY_BOSS_LVL3_EYE_H__
