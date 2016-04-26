#ifndef __ENEMY_SOLIDER_GREEN_H__
#define __ENEMY_SOLIDER_GREEN_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Solider_Green : public Enemy
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

public:

	Enemy_Solider_Green(int x, int y);

	void Move();

};

#endif // __ENEMY_SOLIDER_GREEN_H__