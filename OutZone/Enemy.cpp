#include <math.h>

#include "Application.h"
#include "Enemy.h"
#include "ModuleCollider.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

#include "SDL\include\SDL.h"

#define PI 3.14159265f

Enemy::Enemy(int x, int y, uint typemove/*,ENEMY_TYPES type*/) : position(x, y), typemove(typemove), /*type(type),*/ collider(nullptr)
{}

Enemy::~Enemy()
{
	if(collider != nullptr)
		App->collision->EraseCollider(collider);
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Draw(SDL_Texture* sprites)
{
	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

int Enemy::SeePlayer(const SDL_Rect& r, float& angle2)
{
	float angle;
	fPoint player;

	int dir = 0;

	player.x = (App->player->width / 2) + App->player->position.x;
	player.y = (App->player->height / 2) + App->player->position.y;

	int distx = player.x - (r.x + r.w / 2);

	float hypotenusa = sqrt(distx*distx + ((player.y - (r.y + r.h / 2))*(player.y - (r.y + r.h / 2))));

	angle = acos(distx / hypotenusa) * 180 / PI;

	if ((player.y - (r.y + r.h / 2)) >= 0)
	angle += 180;
	else angle = (180 - angle);

	if (angle > 78.75 && angle <= 101.25)
		dir = 1;
	else if (angle > 101.25 && angle <= 123.75)
		dir = 2;
	else if (angle > 123.75 && angle <= 146.25)
		dir = 3;
	else if (angle > 146.25 && angle <= 168.75)
		dir = 4;
	else if (angle > 168.75 && angle <= 191.25)
		dir = 5;
	else if (angle > 191.25 && angle <= 213.75)
		dir = 6;
	else if (angle > 213.75 && angle <= 236.25)
		dir = 7;
	else if (angle > 236.25 && angle <= 258.75)
		dir = 8;
	else if ((angle > 258.75 && angle <= 281.25))
		dir = 9;
	else if (angle > 281.25 && angle <= 303.75)
		dir = 10;
	else if (angle > 303.75 && angle <= 326.25)
		dir = 11;
	else if (angle > 326.25 && angle <= 348.75)
		dir = 12;
	else if ((angle > 348.75 && angle <= 360) || (angle >= 0 && angle <= 11.25))
		dir = 13;
	else if (angle > 11.25 && angle <= 33.75)
		dir = 14;
	else if (angle > 33.75 && angle <= 56.25)
		dir = 15;
	else if (angle > 56.25 && angle <= 78.75)
		dir = 16;
	angle2 = angle;
		return dir;
}

void Enemy::MoveToPlayer(float& pos_x, float& pos_y, int h, int w, int angle)
{
	fPoint player;
	player.x = (App->player->width / 2) + App->player->position.x;
	player.y = (App->player->height / 2) + App->player->position.y;

	int distx = player.x - (pos_x + w / 2);
	int disty = player.y - (pos_y + h / 2);


	if (CollisionUp == false && disty + 70 < 0)
		pos_y -= ENEMY_SPEED*(sin(angle*PI / 180));
	if (CollisionDown == false && disty - 70 >= 0)
		pos_y -= ENEMY_SPEED*(sin(angle*PI / 180));
	if (CollisionLeft == false && distx + 70 < 0)
		pos_x -= ENEMY_SPEED*(cos(angle*PI / 180));
	if (CollisionRight == false && distx - 70 >= 0)
		pos_x -= ENEMY_SPEED*(cos(angle*PI / 180));
}