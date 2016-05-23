#ifndef __ENEMY_SHIELD_TANK_H__
#define __ENEMY_SHIELD_TANK_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Shield_Tank : public Enemy
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

	Animation Shield;
	Animation Nude;
	bool nude = true;

public:

	Enemy_Shield_Tank(int x, int y);
	void death();
	void Move();

};

#endif // __ENEMY_SHIELD_TANK_H__