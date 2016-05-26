#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#define MAX_COLLIDERS 200

#include "Module.h"

enum COLLIDER_TYPE
{
	COLLIDER_NONE = -1,
	COLLIDER_WALL,
	COLLIDER_PLAYER,
	COLLIDER_ENEMY,
	COLLIDER_PLAYER_SHOT,
	COLLIDER_ENEMY_SHOT,
	COLLIDER_SCREEN_BOMB,
	COLLIDER_ITEMS,
	COLLIDER_BOX,
	COLLIDER_HOLE,
	COLLIDER_TURRET_WALL,
	COLLIDER_MAX
};

struct Collider
{
	SDL_Rect rect;
	bool to_delete = false;
	COLLIDER_TYPE type;
	Module* callback = nullptr;

	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, Module* callback = nullptr) :
		rect(rectangle),
		type(type),
		callback(callback)
	{}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r) const;
	bool CheckCollisionhole(const SDL_Rect& r) const;
	//CollisionSide CheckCollisionSide(const SDL_Rect& r) const;
	bool CheckCollisionUp(const SDL_Rect& r) const;
	bool CheckCollisionDown(const SDL_Rect& r) const;
	bool CheckCollisionRight(const SDL_Rect& r) const;
	bool CheckCollisionLeft(const SDL_Rect& r) const;
	bool CheckCollisionUpEnemy(const SDL_Rect& r) const;
	bool CheckCollisionDownEnemy(const SDL_Rect& r) const;
	bool CheckCollisionRightEnemy(const SDL_Rect& r) const;
	bool CheckCollisionLeftEnemy(const SDL_Rect& r) const;
};

class ModuleCollision : public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	update_status PreUpdate();
	update_status Update();
	//update_status PostUpdate();
	bool CleanUp();

	Collider* AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback = nullptr);
	bool EraseCollider(Collider* collider);
	void DebugDraw();

	int returny(int posy, int max_map)
	{
		return (posy - (max_map - SCREEN_HEIGHT));
	}

private:

	Collider* colliders[MAX_COLLIDERS];
	bool matrix[COLLIDER_MAX][COLLIDER_MAX];
	bool debug = false;
};

#endif