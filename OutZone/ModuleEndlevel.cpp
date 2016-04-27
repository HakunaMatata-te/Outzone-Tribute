#include "ModuleEndlevel.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ModuleEndlevel::ModuleEndlevel()
{
	endlevel.x = 0;
	endlevel.y = 0;
	endlevel.w = 240;
	endlevel.h = 381;
}
ModuleEndlevel::~ModuleEndlevel()
{}

bool ModuleEndlevel::Start()
{
	LOG("Loading end screen");

	endlvl_texture = App->textures->Load("Intro/EndlevelScreen.png");

	App->render->camera.y = 0;

	return true;
}

bool ModuleEndlevel::CleanUp()
{
	LOG("Unloading End screen");

	App->textures->Unload(endlvl_texture);

	return true;
}

update_status ModuleEndlevel::Update()
{
	App->render->Blit(endlvl_texture, 0, 0, &endlevel, 0.75f); //starts rendering from bottom of the image

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack((Module*)App->end, (Module*)App->leaderboard, 3);
	}

	return UPDATE_CONTINUE;
}