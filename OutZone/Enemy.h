#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"

#include "ModuleUI.h"

struct SDL_Texture;
struct Collider;
struct SDL_Rect;

class Enemy
{
protected:
	Animation* animation;
	Collider* collider;

public:
	iPoint position;
	int life = 2;
	uint typemove;

public:
	Enemy(int x, int y, uint typemove);
	virtual ~Enemy();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void death() {};
	virtual void droping() {};

	int SeePlayer(const SDL_Rect& r);

};

#endif // __ENEMY_H__