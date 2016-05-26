#ifndef __ENEMY_RED_INFANTERY_H__
#define __ENEMY_RED_INFANTERY_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Red_Infantery : public Enemy
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

	Animation Idle_1;
	Animation Idle_2;
	Animation Idle_3;
	Animation Idle_4;
	Animation Idle_5;
	Animation Idle_6;
	Animation Idle_7;
	Animation Idle_8;

public:

	Enemy_Red_Infantery(int x, int y, uint typemove, ENEMY_TYPES type);
	void death();
	void Move();

};

#endif // __ENEMY_RED_INFANTERY_H__