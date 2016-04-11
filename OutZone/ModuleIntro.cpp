#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleIntro.h"
#include "ModuleLevel_1.h"


ModuleIntro::ModuleIntro()
{
	background.x = 0;
	background.y = 19;
	background.w = 240;
	background.h = 381;
}

ModuleIntro::~ModuleIntro()
{}

// Load assets
bool ModuleIntro::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	lvl_texture = App->textures->Load("Intro/background.png");
	lvl_texture2 = App->textures->Load("Intro/intro_scree_blue_guy.png");
	return ret;
}

// Update: draw background
update_status ModuleIntro::Update()
{
	App->render->Blit(lvl_texture, 0, 0, &background, 0.75f); //Negative value to start rendering from the bottom og the image
	App->render->Blit(lvl_texture2, 0, 0, &background, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE]){
		App->fade->FadeToBlack(App->intro, App->level_1, 3);
	}

	return UPDATE_CONTINUE;
}