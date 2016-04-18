#include "Globals.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

ModuleAudio::ModuleAudio() : Module()
{
	for (uint i = 0; i < MAX_MUSIC; ++i)
		musics[i] = nullptr;
	for (uint i = 0; i < MAX_FX; ++i)
		fxs[i] = nullptr;
}

ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Start(){

	LOG("Init Mixer library");
	bool ret = true;

	int flags = MIX_INIT_OGG;
	int init = Mix_Init(flags);

	if ((init & flags) != flags)
	{
		LOG("Could not initialize mixer lib. Sound_Init: %s", Mix_GetError());
		ret = false;
	}

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	
	return ret;
}

bool ModuleAudio::CleanUp(){

	for (uint i = 0; i < MAX_MUSIC; ++i)
		if (musics[i] != nullptr)
			Mix_FreeMusic(musics[i]);

	for (uint i = 0; i < MAX_MUSIC; ++i)
		if (fxs[i] != nullptr)
			Mix_FreeChunk(fxs[i]);

	Mix_Quit();

	return true;
}

Mix_Music* const ModuleAudio::LoadMusic(const char* path)
{
	Mix_Music* music = Mix_LoadMUS(path);

	if (music == NULL)
	{
		LOG("Could not load music with path: %s. Mix_LoadMUS: %s", path, Mix_GetError());
	}
	else
	{
		musics[last_music++] = music;
	}

	return music;
}

Mix_Chunk* const ModuleAudio::LoadFX(const char* path)
{
	Mix_Chunk* fx = Mix_LoadWAV(path);

	if (fx == NULL)
	{
		LOG("Could not load fx with path: %s. Mix_LoadWAV: %s", path, Mix_GetError());
	}
	else
	{
		fxs[last_fx++] = fx;
	}

	return fx;
}