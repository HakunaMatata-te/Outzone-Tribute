
#include "Object.h"


Object::Object(int x, int y) : position(x, y), collider(nullptr)
{}

Object::~Object()
{
	if (collider != nullptr)
		App->collision->EraseCollider(collider);
}

const Collider* Object::GetCollider() const
{
	return collider;
}

void Object::Draw(SDL_Texture* itemsprites)
{
	if (collider->type == COLLIDER_WALL){
		if (App->player->position.y > -4750 && App->player->position.y < -4675)
		{
			if (position.x > 18 && position.x <= 63)
				position.x--;
			if (position.x <= 167 && position.x > 120)
				position.x++;
		}
		else if (App->player->position.y <= -4780)
		{
			if (position.x <= 62 && position.x >= 18)
				position.x++;
			if (position.x > 120)
				position.x--;
		}
	}
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	App->render->Blit(itemsprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

