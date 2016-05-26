#ifndef __ENEMY_HORITZONTAL_MOVING_MACHINE_H__
#define __ENEMY_HORITZONTAL_MOVING_MACHINE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_HMM : public Enemy
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

	Animation Horitzontal;

public:

	Enemy_HMM(int x, int y, uint typemove, ENEMY_TYPES type);
	void death();
	void Move();

};

#endif // __ENEMY_HORITZONTAL_MOVING_MACHINE_H__