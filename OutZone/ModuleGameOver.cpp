#include "ModuleGameOver.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"

ModuleGameOver::ModuleGameOver()
{
	background.x = 0;
	background.y = 0;
	background.w = 240;
	background.h = 320;
}
ModuleGameOver::~ModuleGameOver()
{}

bool ModuleGameOver::Start()
{
	LOG("Loading game over screen");

	lvl_texture = App->textures->Load("Intro/gameOver.png");
	App->audios->PlayMusic("Sounds/Game_Over.ogg", 0);

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
	App->render->Blit(lvl_texture, 0, 0, &background, 1.0f , false);

	if (App->input->keyboard[SDL_SCANCODE_SPACE]==KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->gameover, (Module*)App->intro, 1);
	}

	return UPDATE_CONTINUE;
}
