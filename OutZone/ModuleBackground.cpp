#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"


ModuleBackground::ModuleBackground()
{
	background.x = 1;
	background.y = 0;
	background.w = 240;
	background.h = 4756;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Game/lvl_1.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	App->render->Blit(graphics, 0, -4756 + SCREEN_HEIGHT, &background, 0.75f); //Negative value to start rendering from the bottom og the image

	return UPDATE_CONTINUE;
}