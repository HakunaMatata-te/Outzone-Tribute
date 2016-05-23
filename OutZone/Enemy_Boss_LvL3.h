#ifndef __ENEMY_BOSS_LVL3_H__
#define __ENEMY_BOSS_LVL3_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Boss_LvL3 : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation move;
	iPoint original_pos;
	fPoint speed;
	Path path;
	Uint32 lastShot = 0;
	int pos_idle = 0;
	bool shot = true;
	bool right = true;
	bool left = false;
	bool up = false;
	bool down = false;

	Animation Structure;

public:

	Enemy_Boss_LvL3(int x, int y, uint typemove);
	void death();
	void Move();

};

#endif // __ENEMY_BOSS_LVL3_H__