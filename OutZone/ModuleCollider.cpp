#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollider.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"

ModuleCollision::ModuleCollision()
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[COLLIDER_WALL][COLLIDER_WALL] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_SCREEN_BOMB] = false;
	matrix[COLLIDER_WALL][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_WALL][COLLIDER_BOX] = false;
	matrix[COLLIDER_WALL][COLLIDER_HOLE] = false;
	matrix[COLLIDER_WALL][COLLIDER_TURRET_WALL] = false;
	matrix[COLLIDER_WALL][COLLIDER_TURRET_WALL_2] = false;
	matrix[COLLIDER_WALL][COLLIDER_LASER_LEFT] = false;
	matrix[COLLIDER_WALL][COLLIDER_LASER_RIGHT] = false;

	matrix[COLLIDER_PLAYER][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_SCREEN_BOMB] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ITEMS] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_BOX] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_HOLE] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_TURRET_WALL] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_TURRET_WALL_2] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_LASER_LEFT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_LASER_RIGHT] = true;

	matrix[COLLIDER_ENEMY][COLLIDER_WALL] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_SCREEN_BOMB] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BOX] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_HOLE] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_TURRET_WALL] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_TURRET_WALL_2] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_LASER_LEFT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_LASER_RIGHT] = false;

	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_SCREEN_BOMB] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BOX] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_HOLE] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_TURRET_WALL] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_TURRET_WALL_2] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_LASER_LEFT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_LASER_RIGHT] = false;

	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_SCREEN_BOMB] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BOX] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_HOLE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_TURRET_WALL] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_TURRET_WALL_2] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_LASER_LEFT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_LASER_RIGHT] = false;

	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_WALL] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_SCREEN_BOMB] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_BOX] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_HOLE] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_TURRET_WALL] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_TURRET_WALL_2] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_LASER_LEFT] = false;
	matrix[COLLIDER_SCREEN_BOMB][COLLIDER_LASER_RIGHT] = false;

	matrix[COLLIDER_ITEMS][COLLIDER_WALL] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ITEMS][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_SCREEN_BOMB] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_BOX] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_HOLE] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_TURRET_WALL] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_TURRET_WALL_2] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_LASER_LEFT] = false;
	matrix[COLLIDER_ITEMS][COLLIDER_LASER_RIGHT] = false;

	matrix[COLLIDER_BOX][COLLIDER_WALL] = false;
	matrix[COLLIDER_BOX][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_BOX][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_BOX][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_BOX][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_BOX][COLLIDER_SCREEN_BOMB] = true;
	matrix[COLLIDER_BOX][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_BOX][COLLIDER_BOX] = false;
	matrix[COLLIDER_BOX][COLLIDER_HOLE] = false;
	matrix[COLLIDER_BOX][COLLIDER_TURRET_WALL] = false;
	matrix[COLLIDER_BOX][COLLIDER_TURRET_WALL_2] = false;
	matrix[COLLIDER_BOX][COLLIDER_LASER_LEFT] = true;
	matrix[COLLIDER_BOX][COLLIDER_LASER_RIGHT] = true;

	matrix[COLLIDER_HOLE][COLLIDER_WALL] = false;
	matrix[COLLIDER_HOLE][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_HOLE][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_HOLE][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_HOLE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_HOLE][COLLIDER_SCREEN_BOMB] = false;
	matrix[COLLIDER_HOLE][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_HOLE][COLLIDER_BOX] = false;
	matrix[COLLIDER_HOLE][COLLIDER_HOLE] = false;
	matrix[COLLIDER_HOLE][COLLIDER_TURRET_WALL] = false;
	matrix[COLLIDER_HOLE][COLLIDER_TURRET_WALL_2] = false;
	matrix[COLLIDER_HOLE][COLLIDER_LASER_LEFT] = false;
	matrix[COLLIDER_HOLE][COLLIDER_LASER_RIGHT] = false;

	matrix[COLLIDER_TURRET_WALL][COLLIDER_TURRET_WALL] = false;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_WALL] = false;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_SCREEN_BOMB] = false;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_BOX] = false;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_HOLE] = false;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_TURRET_WALL_2] = false;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_LASER_LEFT] = false;
	matrix[COLLIDER_TURRET_WALL][COLLIDER_LASER_RIGHT] = true;

	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_TURRET_WALL_2] = false;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_TURRET_WALL] = false;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_WALL] = false;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_SCREEN_BOMB] = false;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_BOX] = false;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_HOLE] = false;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_LASER_LEFT] = true;
	matrix[COLLIDER_TURRET_WALL_2][COLLIDER_LASER_RIGHT] = false;

	matrix[COLLIDER_LASER_LEFT][COLLIDER_TURRET_WALL_2] = true;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_TURRET_WALL] = false;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_WALL] = false;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_SCREEN_BOMB] = false;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_BOX] = true;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_HOLE] = false;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_LASER_LEFT] = false;
	matrix[COLLIDER_LASER_LEFT][COLLIDER_LASER_RIGHT] = false;

	matrix[COLLIDER_LASER_RIGHT][COLLIDER_TURRET_WALL_2] = false;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_TURRET_WALL] = true;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_WALL] = false;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_SCREEN_BOMB] = false;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_ITEMS] = false;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_BOX] = true;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_HOLE] = false;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_LASER_LEFT] = false;
	matrix[COLLIDER_LASER_RIGHT][COLLIDER_LASER_RIGHT] = false;


}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr && colliders[i]->to_delete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return UPDATE_CONTINUE;
}

update_status ModuleCollision::Update()
{
	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (c1->CheckCollision(c2->rect) == true)
			{
				c1->Checkparticle(c1, c2);
				if (matrix[c1->type][c2->type] && c1->callback)
					c1->callback->OnCollision(c1, c2);

				if (matrix[c2->type][c1->type] && c2->callback)
					c2->callback->OnCollision(c2, c1);
			}
		}
	}

	DebugDraw();

	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw()
{
	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	if (debug == false)
		return;

	Uint8 alpha = 80;
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
			continue;

		switch (colliders[i]->type)
		{
		case COLLIDER_NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_WALL: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case COLLIDER_PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case COLLIDER_ENEMY: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case COLLIDER_BOX: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case COLLIDER_PLAYER_SHOT: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_SCREEN_BOMB: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_ENEMY_SHOT: // magenta
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case COLLIDER_HOLE: //color?
			App->render->DrawQuad(colliders[i]->rect, 0, 150, 255, alpha);
			break;
		case COLLIDER_TURRET_WALL: //color?
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 100, alpha);
			break;
		}
	}
}

bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback)
{
	Collider* ret = nullptr;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}

	return ret;
}

bool ModuleCollision::EraseCollider(Collider* collider)
{
	if (collider != nullptr)
	{
		// we still search for it in case we received a dangling pointer
		for (uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if (colliders[i] == collider)
			{
				collider->to_delete = true;
				break;
			}
		}
	}

	return false;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
		rect.x + rect.w > r.x &&
		rect.y < r.y + r.h &&
		rect.h + rect.y > r.y);
}

bool Collider::CheckCollisionhole(const SDL_Rect& r) const
{
	return (rect.x + 15 < r.x + r.w &&
		rect.x - 15 + rect.w > r.x &&
		rect.y + 15 < r.y + r.h &&
		rect.h - 15 + rect.y > r.y);
}
bool Collider::CheckCollisionUp(const SDL_Rect& r) const
{
	return (rect.y < r.y + r.h && rect.y + (PLAYER_SPEED + 1) > r.y + r.h);
}

bool Collider::CheckCollisionDown(const SDL_Rect& r) const
{
	return (rect.y + rect.h > r.y && rect.y + rect.h - (PLAYER_SPEED + 1)< r.y);
}
bool Collider::CheckCollisionRight(const SDL_Rect& r) const
{
	return (rect.x + rect.w > r.x && rect.x + rect.w - (PLAYER_SPEED + 1) < r.x && rect.y + rect.h - (PLAYER_SPEED + 1)> r.y && rect.y + (PLAYER_SPEED + 1) < r.y + r.h);
}
bool Collider::CheckCollisionLeft(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w && rect.x + (PLAYER_SPEED + 1) > r.x + r.w && rect.y + rect.h - (PLAYER_SPEED + 1)> r.y && rect.y + (PLAYER_SPEED + 1) < r.y + r.h);
}

bool Collider::CheckCollisionUpEnemy(const SDL_Rect& r) const
{
	return (rect.y < r.y + r.h && rect.y + (ENEMY_SPEED + 1) > r.y + r.h);
}
bool Collider::CheckCollisionDownEnemy(const SDL_Rect& r) const
{
	return (rect.y + rect.h > r.y && rect.y + rect.h - (ENEMY_SPEED + 1)< r.y);
}
bool Collider::CheckCollisionRightEnemy(const SDL_Rect& r) const
{
	return (rect.x + rect.w > r.x && rect.x + rect.w - (ENEMY_SPEED + 1) < r.x);
}
bool Collider::CheckCollisionLeftEnemy(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w && rect.x + (ENEMY_SPEED + 1) > r.x + r.w);
}


void Collider::Checkparticle(Collider* c1, Collider* c2) const
{
	if (c1->type == COLLIDER_PLAYER_SHOT  && c2->type != COLLIDER_SCREEN_BOMB && c1->type != COLLIDER_PLAYER && c2->type != COLLIDER_NONE && c2->type != COLLIDER_PLAYER_SHOT && c2->type != COLLIDER_ENEMY_SHOT && c2->type != COLLIDER_HOLE && c2->type != COLLIDER_ITEMS)
	{
		if (App->player->current_weapon == MINIGUN)
			App->particles->AddParticle(App->particles->Minigunshot_coll, c1->rect.x - 5, c1->rect.y - 5, COLLIDER_NONE);
		if (App->player->current_weapon == TRIPLE_GUN)
			App->particles->AddParticle(App->particles->Triplegunshot_coll, c1->rect.x - 5, c1->rect.y - 5, COLLIDER_NONE);
	}
	if (c2->type == COLLIDER_PLAYER_SHOT && c1->type != COLLIDER_SCREEN_BOMB && c1->type != COLLIDER_PLAYER && c1->type != COLLIDER_NONE && c1->type != COLLIDER_PLAYER_SHOT && c1->type != COLLIDER_ENEMY_SHOT && c1->type != COLLIDER_HOLE && c1->type != COLLIDER_ITEMS)
	{
		if (App->player->current_weapon == MINIGUN)
			App->particles->AddParticle(App->particles->Minigunshot_coll, c2->rect.x - 5, c2->rect.y - 5, COLLIDER_NONE);
		if (App->player->current_weapon == TRIPLE_GUN)
			App->particles->AddParticle(App->particles->Triplegunshot_coll, c2->rect.x - 5, c2->rect.y - 5, COLLIDER_NONE);
	}
}