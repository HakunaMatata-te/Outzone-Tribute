#ifndef __ENEMY_FIRST_BOSS__
#define __ENEMY_FIRST_BOSS__

#include "Enemy.h"
//#include "Path.h"



class First_Boss : public Enemy
{
private:
	int original_y = 0;
	Animation move;
	iPoint original_pos;
	//fPoint speed;
	//Path path;

	/*SDL_Rect animation_count;
	uint count_add;
	uint count_max_spawn;
	bool stop; */

public:

	First_Boss(int x, int y);

	void ChangeDeath();

	//void Move();

};

#endif