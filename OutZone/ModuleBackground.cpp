#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"


ModuleBackground::ModuleBackground()
{
	background.x = 0;
	background.y = 0;
	background.w = 240;
	background.h = 3896;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Game/level1.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	App->render->Blit(graphics, 0, -3576, &background, 0.75f);

	return UPDATE_CONTINUE;
}