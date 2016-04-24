#ifndef __ENEMY_SOLIDER_RED_H__
#define __ENEMY_SOLIDER_RED_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Solider_Red : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation move;
	iPoint original_pos;
	fPoint speed;
	Path path;

public:

	Enemy_Solider_Red(int x, int y);

	void Move();

};

#endif // __ENEMY_SOLIDER_RED_H__