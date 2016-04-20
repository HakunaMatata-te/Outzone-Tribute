#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleIntro.h"
#include "ModuleLevel_1.h"
#include "ModulePlayer.h"


ModuleIntro::ModuleIntro()
{
	
	background.x = 0;
	background.y = 19;
	background.w = 240;
	background.h = 381;
	
	//title animation
	title.PushBack({ 0, 0, 416, 112});
	title.PushBack({ 0, 417, 416, 112});
	title.PushBack({ 0, 834, 416, 112 });
	title.PushBack({ 0, 1251, 416, 112 });
	title.PushBack({ 0, 1668, 416, 112 });
	title.PushBack({ 0, 2085, 416, 112 });
	title.PushBack({ 0, 2501, 416, 112 });

}

ModuleIntro::~ModuleIntro()
{}

// Load assets
bool ModuleIntro::Start()
{
	LOG("Loading background assets");

	lvl_texture2 = App->textures->Load("Intro/intro_scree_blue_guy.png");
	lvl_title = App->textures->Load("Intro/title.png");

	title.loop = false;


	return true;
}

bool ModuleIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	App->textures->Unload(lvl_texture);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleIntro::Update()
{
	//Negative value to start rendering from the bottom og the image
	App->render->Blit(lvl_texture2, 0, 0, &background, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE]){
		App->fade->FadeToBlack(App->intro, App->level_1, 3);
	}

	return UPDATE_CONTINUE;
}