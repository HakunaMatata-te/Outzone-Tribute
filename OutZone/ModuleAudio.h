#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"

#define MAX_MUSIC 10
#define MAX_FX 10

#include "SDL_mixer/include/SDL_mixer.h"

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Start();
	bool CleanUp();

	Mix_Music* const LoadMusic(const char* path);
	Mix_Chunk* const LoadFX(const char* path);

public:
	Mix_Music* musics[MAX_MUSIC];
	Mix_Chunk* fxs[MAX_FX];
	uint last_music = 0;
	uint last_fx = 0;
};

#endif