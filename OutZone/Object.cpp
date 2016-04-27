#include "Object.h"
#include "Application.h"
#include "ModuleCollider.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

#include "SDL\include\SDL.h"


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
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	App->render->Blit(itemsprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

