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

public:

	Enemy_Minor_Turret(int x, int y);

	void Move();

	void ChangeDeath();

};

#endif // __ENEMY_MINOR_TURRET_H__