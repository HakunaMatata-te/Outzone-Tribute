#include "ModuleEndlevel.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"

ModuleEndlevel::ModuleEndlevel()
{
	endlevel.x = 0;
	endlevel.y = 1;
	endlevel.w = 239;
	endlevel.h = 381;
}
ModuleEndlevel::~ModuleEndlevel()
{}

bool ModuleEndlevel::Start()
{
	LOG("Loading end screen");
	App->audios->PlayMusic("Sounds/silence.ogg", 0);
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
	App->render->Blit(endlvl_texture, 0, 0, &endlevel, 1, false); //starts rendering from bottom of the image

	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack((Module*)App->end, (Module*)App->leaderboard, 1);
	}

	return UPDATE_CONTINUE;
}
