#ifndef __ENEMY_TRUCK_H__
#define __ENEMY_TRUCK_H__

#include "Enemy.h"
#include "Path.h"



class Enemy_Truck : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation move;
	iPoint original_pos;
	fPoint speed;
	Path path;

	SDL_Rect animation_count;
	uint count_add;
	uint count_max_spawn;

public:

	Enemy_Truck(int x, int y);

	void Move();

};

#endif // __ENEMY_TRUCK_H__