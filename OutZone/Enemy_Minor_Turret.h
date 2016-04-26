#ifndef __ENEMY_MINOR_TURRET_H__
#define __ENEMY_MINOR_TURRET_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Minor_Turret : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation move;
	Animation deathanim;
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
	Animation Idle_9;
	Animation Idle_10;
	Animation Idle_11;
	Animation Idle_12;
	Animation Idle_13;
	Animation Idle_14;
	Animation Idle_15;
	Animation Idle_16;

public:

	Enemy_Minor_Turret(int x, int y);

	void Move();

	void ChangeDeath();

};

#endif // __ENEMY_MINOR_TURRET_H__