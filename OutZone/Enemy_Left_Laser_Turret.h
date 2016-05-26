#ifndef __ENEMY_LEFT_LASER_TURRET_H__
#define __ENEMY_LEFT_LASER_TURRET_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Left_Laser_Turret : public Enemy
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

public:

	Enemy_Left_Laser_Turret(int x, int y, uint typemove, ENEMY_TYPES type);
	void death();
	void Move();

};

#endif // __ENEMY_LEFT_LASER_TURRET_H__