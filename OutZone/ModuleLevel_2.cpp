#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLevel_2.h"
#include "ModuleLevel_1.h"


ModuleLevel_2::ModuleLevel_2()
{
	background.x = 1;
	background.y = 0;
	background.w = 240;
	background.h = 5777;
}

ModuleLevel_2::~ModuleLevel_2()
{}

// Load assets
bool ModuleLevel_2::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	lvl_texture = App->textures->Load("Game/lvl_2.png");
	lvl_music = App->audios->LoadMusic("Game/lvl_2.wav");
	Mix_PlayMusic(lvl_music, -1);
	return ret;
}

// Update: draw background
update_status ModuleLevel_2::Update()
{
	App->render->Blit(lvl_texture, 0, -5777 + SCREEN_HEIGHT, &background, 0.75f); //Negative value to start rendering from the bottom og the image

	if (App->input->keyboard[SDL_SCANCODE_SPACE]){
		App->fade->FadeToBlack(App->level_2, App->level_1, 3);
	}

	return UPDATE_CONTINUE;
}