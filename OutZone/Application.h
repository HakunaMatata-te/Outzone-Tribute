#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 19

class ModuleWindow;
class ModuleTextures;
class ModuleRender;
class ModuleAudio;
class ModuleParticles;
class ModuleIntro;
class ModuleLevel_1;
class ModuleLevel_2;
class ModuleLevel_3;
class ModuleLeaderboard;
class ModuleCollision;
class ModulePlayer;
class ModuleInput;
class ModuleFadeToBlack;
class ModuleEnemies;
class Module;
class ModuleEndlevel;
class ModuleGameOver;
class ModuleObjects;
class ModuleUi;


class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleAudio* audios;
	ModuleIntro* intro;
	ModuleLevel_1* level_1;
	ModuleLevel_2* level_2;
	ModuleLevel_3* level_3;
	ModuleLeaderboard* leaderboard;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModuleEndlevel* end;
	ModuleGameOver* gameover;
	ModuleObjects* objects;
	ModuleUi* ui;
	

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__