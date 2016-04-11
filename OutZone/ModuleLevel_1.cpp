#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLevel_1.h"
#include "ModuleLevel_2.h"


ModuleLevel_1::ModuleLevel_1()
{
	background.x = 1;
	background.y = 0;
	background.w = 240;
	background.h = 4756;
}

ModuleLevel_1::~ModuleLevel_1()
{}

// Load assets
bool ModuleLevel_1::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	lvl_texture = App->textures->Load("Game/lvl_1.png");
	return ret;
}

// Update: draw background
update_status ModuleLevel_1::Update()
{
	App->render->Blit(lvl_texture, 0, -4756 + SCREEN_HEIGHT, &background, 0.75f); //Negative value to start rendering from the bottom og the image

	if (App->input->keyboard[SDL_SCANCODE_SPACE]){
		App->fade->FadeToBlack(App->level_1, App->level_2, 3);
	}

	return UPDATE_CONTINUE;
}