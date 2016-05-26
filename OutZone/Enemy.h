#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"

#include "ModuleUI.h"


struct SDL_Texture;
struct Collider;
struct SDL_Rect;
enum ENEMY_TYPES;

class Enemy
{
protected:
	Animation* animation;
	Collider* collider;

public:
	fPoint position;
	int life;
	uint typemove;

	bool CollisionUp;
	bool CollisionDown;
	bool CollisionRight;
	bool CollisionLeft;

	//ENEMY_TYPES type;

public:
	Enemy(int x, int y, uint typemove/*, ENEMY_TYPES type*/);
	virtual ~Enemy();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void death() {};
	virtual void droping() {};

	int SeePlayer(const SDL_Rect& r, float& angle2);
	void MoveToPlayer(float& pos_x, float& pos_y, int h, int w, int angle);

};

#endif // __ENEMY_H__