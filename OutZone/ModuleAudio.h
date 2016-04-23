#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"

#define DEFAULT_MUSIC_FADE_TIME 2.0f
#define MAX_FX 200

#include "SDL_mixer/include/SDL_mixer.h"

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Start();
	bool CleanUp();

	bool PlayMusic(const char* path, float fade_time = DEFAULT_MUSIC_FADE_TIME);

	uint LoadFX(const char* path);
	bool UnLoadFx(uint id);
	bool PlayFx(unsigned int fx, int repeat = 0);

public:
	Mix_Music* music = nullptr;
	Mix_Chunk* fx[MAX_FX];
	uint last_fx = 1;
};

#endif