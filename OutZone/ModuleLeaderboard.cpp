#include "ModuleLeaderboard.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ModuleLeaderboard::ModuleLeaderboard()
{
	leaderboard.x = 1;
	leaderboard.y = 0;
	leaderboard.w = 240;
	leaderboard.h = 4760;
}
ModuleLeaderboard::~ModuleLeaderboard()
{}

bool ModuleLeaderboard::Start()
{
	LOG("Loading leaderboard");

	lvl_texture = App->textures->Load("Intro/Leaderboard.png");

	App->render->camera.y = 0;

	return true;
}

bool ModuleLeaderboard::CleanUp()
{
	LOG("Unloading leaderboard");

	App->textures->Unload(lvl_texture);

	return true;
}

update_status ModuleLeaderboard::Update()
{
	App->render->Blit(lvl_texture, 0, 0, &leaderboard, 0.75f); //starts rendering from bottom of the image

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack((Module*)App->leaderboard, (Module*)App->intro, 3);
	}

	return UPDATE_CONTINUE;
}
