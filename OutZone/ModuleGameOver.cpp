#include "ModuleGameOver.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ModuleGameOver::ModuleGameOver()
{
	background.x = 0;
	background.y = 0;
	background.w = 240;
	background.h = 381;
}
ModuleGameOver::~ModuleGameOver()
{}

bool ModuleGameOver::Start()
{
	LOG("Loading game over screen");

	lvl_texture = App->textures->Load("Intro/gameOver.png");

	App->render->camera.y = 0;

	return true;
}

bool ModuleGameOver::CleanUp()
{
	LOG("Unloading game over screen");

	App->textures->Unload(lvl_texture);

	return true;
}

update_status ModuleGameOver::Update()
{
	App->render->Blit(lvl_texture, 0, 0, &background, 0.75f); //starts rendering from bottom of the image

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack((Module*)App->gameover, (Module*)App->leaderboard, 3);
	}

	return UPDATE_CONTINUE;
}
