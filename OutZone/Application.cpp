#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleIntro.h"
#include "ModuleLevel_1.h"
#include "ModuleLevel_2.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollider.h"
#include "ModuleEnemies.h"
#include "ModuleLeaderboard.h"
#include "ModuleEndlevel.h"
#include "ModuleGameOver.h"
#include "ModuleObjects.h"


Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = textures = new ModuleTextures();
	modules[3] = audios = new ModuleAudio();
	modules[4] = input = new ModuleInput();
	modules[5] = intro = new ModuleIntro();
	modules[6] = level_1 = new ModuleLevel_1();
	modules[7] = level_2 = new ModuleLevel_2();
	modules[8] = leaderboard = new ModuleLeaderboard();
	modules[9] = collision = new ModuleCollision();
	modules[10] = enemies = new ModuleEnemies();
	modules[11] = player = new ModulePlayer();
	modules[12] = particles = new ModuleParticles();
	modules[13] = fade = new ModuleFadeToBlack();
	modules[14] = end = new ModuleEndlevel();
	modules[15] = gameover = new ModuleGameOver();
	modules[16] = objects = new ModuleObjects();
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	//Disabled modules

	objects->Disable();
	gameover->Disable();
	end->Disable();
	leaderboard->Disable();
	player->Disable();
	level_1->Disable();
	level_2->Disable();
	collision->Disable();
	enemies->Disable();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = (modules[i]->IsEnabled()) ? (modules[i]->Start()) : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = (modules[i]->IsEnabled()) ? (modules[i]->Update()) : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = (modules[i]->IsEnabled()) ? (modules[i]->PostUpdate()) : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}