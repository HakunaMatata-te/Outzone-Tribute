#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 8

class ModuleWindow;
class ModuleTextures;
class ModuleRender;
class ModuleLevel_1;
class ModuleLevel_2;
class ModulePlayer;
class ModuleInput;
class ModuleFadeToBlack;
class Module;


class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleLevel_1* level_1;
	ModuleLevel_2* level_2;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	

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