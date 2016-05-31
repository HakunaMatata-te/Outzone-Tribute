#ifndef __ENEMY_BOSS_LVL3_FILES_H__
#define __ENEMY_BOSS_LVL3_FILES_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Boss_LvL3_Files : public Enemy
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
	Uint32 lasttimelapseShot = 0;

	Animation Idle;

public:

	Enemy_Boss_LvL3_Files(int x, int y, uint typemove, ENEMY_TYPES type, bool boss);
	void death();
	void Move();

};

#endif // __ENEMY_BOSS_LVL3_FILES_H__