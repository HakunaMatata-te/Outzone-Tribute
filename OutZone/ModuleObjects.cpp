
#include "ModuleObjects.h"


ModuleObjects::ModuleObjects()
{
	for (uint i = 0; i < MAX_OBJECTS; ++i)
		Items[i] = nullptr;
}

// Destructor
ModuleObjects::~ModuleObjects()
{
}

bool ModuleObjects::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	itemsprites = App->textures->Load("Animation/particles.png");

	return true;
}

update_status ModuleObjects::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_OBJECTS; ++i)
	{
		if (object[i].type != OBJECTS_TYPES::NO_OBJECT_TYPE)
		{
			if ((object[i].y) * SCREEN_SIZE > -1 * (App->render->camera.y))
			{
				SpawnObject(object[i]);
				object[i].type = OBJECTS_TYPES::NO_OBJECT_TYPE;
				LOG("Spawning object at %d", object[i].y * SCREEN_SIZE);
			}
		}
	}
	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleObjects::Update()
{

	for (uint i = 0; i < MAX_OBJECTS; ++i)
		if (Items[i] != nullptr)
			Items[i]->Draw(itemsprites);

	return UPDATE_CONTINUE;
}

update_status ModuleObjects::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_OBJECTS; ++i)
	{
		if (Items[i] != nullptr)
		{
			if (Items[i]->position.y * SCREEN_SIZE > -1 * (App->render->camera.y - (App->render->camera.h * SCREEN_SIZE)-150))
			{
				LOG("DeSpawning object at %d", Items[i]->position.y * SCREEN_SIZE);
				delete Items[i];
				Items[i] = nullptr;
			}
		}
	}



	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleObjects::CleanUp()
{
	LOG("Freeing all Items");

	App->textures->Unload(itemsprites);

	for (uint i = 0; i < MAX_OBJECTS; ++i)
	{
		if (Items[i] != nullptr)
		{
			delete Items[i];
			Items[i] = nullptr;
		}
	}

	return true;
}

bool ModuleObjects::AddObject(OBJECTS_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_OBJECTS; ++i)
	{
		if (object[i].type == OBJECTS_TYPES::NO_OBJECT_TYPE)
		{
			object[i].type = type;
			object[i].x = x;
			object[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleObjects::SpawnObject(const ObjectsInfo& info)
{
	// find room for the new object
	uint i = 0;
	for (; Items[i] != nullptr && i < MAX_OBJECTS; ++i);

	if (i != MAX_OBJECTS)
	{
		switch (info.type)
		{
		case OBJECTS_TYPES::BOX:
			Items[i] = new Box(info.x, info.y);
			break;
		case OBJECTS_TYPES::POWER_UP:
			Items[i] = new Powerup(info.x, info.y);
			break;
		case OBJECTS_TYPES::SPECIAL:
			Items[i] = new Bomb(info.x, info.y);
			break;
		case OBJECTS_TYPES::WEAPON:
			Items[i] = new ChangeWeapon(info.x, info.y);
			break;
		}
	}
}

void ModuleObjects::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_OBJECTS; ++i)
	{
		if (Items[i] != nullptr && Items[i]->GetCollider() == c1 && (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_SCREEN_BOMB))
		{
			App->particles->AddParticle(App->particles->normal_explosion, Items[i]->position.x, Items[i]->position.y, COLLIDER_NONE);
			Items[i]->drop();
			delete Items[i];
			Items[i] = nullptr;
			break;
		}
		else if (Items[i] != nullptr && Items[i]->GetCollider() == c1 && (c2->type == COLLIDER_PLAYER))
		{
		//	App->particles->AddParticle(App->particles->normal_explosion, enemies[i]->position.x, enemies[i]->position.y, COLLIDER_NONE);
			Items[i]->pick();
			delete Items[i];
			Items[i] = nullptr;
			break;
		}
	}
}