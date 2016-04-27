#ifndef __MODULE_OBJECTS_H__
#define __MODULE_OBJECTS_H__

#include "Module.h"
#include "Object.h"

#define MAX_OBJECTS 50

enum OBJECTS_TYPES
{
	NO_OBJECT_TYPE,
	ENERGY,
	POWER_UP,
	WEAPON,
	ENERGYBOX,
	BOX,
	SPECIAL
};

class Object;

struct ObjectsInfo
{
	OBJECTS_TYPES type = OBJECTS_TYPES::NO_OBJECT_TYPE;
	int x, y;
};

class ModuleObjects : public Module
{
public:
	ModuleObjects();
	~ModuleObjects();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	bool AddObject(OBJECTS_TYPES type, int x, int y);

private:

	void SpawnObject(const ObjectsInfo& info);

private:

	ObjectsInfo object[MAX_OBJECTS];
	Object* Items[MAX_OBJECTS];
	SDL_Texture* itemsprites;
};

#endif