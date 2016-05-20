#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleIntro.h"
#include "ModuleLevel_3.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"



ModuleIntro::ModuleIntro()
{
	
	background.x = 0;
	background.y = 0;
	background.w = 240;
	background.h = 320;
	
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

	App->audios->PlayMusic("Sounds/silence.ogg", 0);
	lvl_texture2 = App->textures->Load("Intro/intro_screen.png");
	lvl_title = App->textures->Load("Intro/title.png");

	title.loop = false;

	App->render->camera.y = 0;

	return true;
}

bool ModuleIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	App->textures->Unload(lvl_texture2);
	App->textures->Unload(lvl_texture);

	return true;
}

// Update: draw background
update_status ModuleIntro::Update()
{
	//Negative value to start rendering from the bottom og the image
	App->render->Blit(lvl_texture2, 0, 0, &background, 1);

	if (App->input->keyboard[SDL_SCANCODE_SPACE]){
		App->fade->FadeToBlack(App->intro, App->level_3, 1);
	}

	return UPDATE_CONTINUE;
}