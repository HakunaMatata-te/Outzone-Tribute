#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#define MAX_ACTIVE_PARTICLES 200

struct SDL_Texture;

struct Particle
{
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();

	void AddParticle(const Particle& particle, int x, int y, Uint32 delay = 0);

private:

	SDL_Texture* particles_texture = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];
	uint last_particle = 0;

public:

	Particle minigun_shot_lv1;
	Particle triple_shot_lv1_center;
	Particle triple_shot_lv1_right;
	Particle triple_shot_lv1_left;
};

#endif // !__MODULEPARTICLES_H__