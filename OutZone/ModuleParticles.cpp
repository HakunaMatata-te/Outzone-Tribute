#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	particles_texture = App->textures->Load("Animation/weapon_shots.png");

	//LVL 1 particles --------------------------------------------------------------

	// Minigun particle
	minigun_shot_lv1.anim.PushBack({ 55, 244, 4, 16 });
	minigun_shot_lv1.speed.y = -4;
	minigun_shot_lv1.life = 1000;
	minigun_shot_lv1.fx = App->audios->LoadFX("Sounds/minigun_shot.wav");

	// Triple shot particle
	triple_shot_lv1_center.anim.PushBack({ 137, 246, 6, 14 });
	triple_shot_lv1_center.speed.y = -4;
	triple_shot_lv1_center.life = 1000;
	triple_shot_lv1_center.fx = App->audios->LoadFX("Sounds/triple_shot.wav");
	//Triple right
	triple_shot_lv1_right.anim.PushBack({ 155, 247, 9, 13 });
	triple_shot_lv1_right.speed.y = -4;
	triple_shot_lv1_right.speed.x = +2;
	triple_shot_lv1_right.life = 1000;
	//Triple left
	triple_shot_lv1_left.anim.PushBack({ 116, 247, 9, 13 });
	triple_shot_lv1_left.speed.y = -4;
	triple_shot_lv1_left.speed.x = -2;
	triple_shot_lv1_left.life = 1000;


	//LVL 2 particles

	//Minigun
	minigun_shot_lv2.anim.PushBack({ 52, 219, 10, 16 });
	minigun_shot_lv2.speed.y = -4;
	minigun_shot_lv2.life = 1000;
	minigun_shot_lv2.fx = minigun_shot_lv1.fx;

	// Triple shot particle
	triple_shot_lv2_center.anim.PushBack({ 135, 221, 10, 18 });
	triple_shot_lv2_center.speed.y = -4;
	triple_shot_lv2_center.life = 1000;
	triple_shot_lv2_center.fx = triple_shot_lv1_center.fx;
	//Triple right
	triple_shot_lv2_right.anim.PushBack({ 165, 224, 12, 17 });
	triple_shot_lv2_right.speed.y = -4;
	triple_shot_lv2_right.speed.x = +2;
	triple_shot_lv2_right.life = 1000;
	//Triple left
	triple_shot_lv2_left.anim.PushBack({ 103, 224, 12, 17 });
	triple_shot_lv2_left.speed.y = -4;
	triple_shot_lv2_left.speed.x = -2;
	triple_shot_lv2_left.life = 1000;


	//LVL 3 particles

	//Minigun
	minigun_shot_lv3.anim.PushBack({ 45, 128, 24, 24 });
	minigun_shot_lv3.anim.PushBack({45, 100, 24, 24});
	minigun_shot_lv3.anim.speed = 0.25f;
	minigun_shot_lv3.speed.y = -4;
	minigun_shot_lv3.life = 1000;
	minigun_shot_lv3.fx = minigun_shot_lv1.fx;

	// Triple shot particle
	triple_shot_lv3_center.anim.PushBack({ 133, 130, 14, 23 });
	triple_shot_lv3_center.speed.y = -4;
	triple_shot_lv3_center.life = 1000;
	triple_shot_lv3_center.fx = triple_shot_lv1_center.fx;
	//Triple right
	triple_shot_lv3_right.anim.PushBack({ 155, 130, 17, 22 });
	triple_shot_lv3_right.speed.y = -4;
	triple_shot_lv3_right.speed.x = +2;
	triple_shot_lv3_right.life = 1000;
	//Triple left
	triple_shot_lv3_left.anim.PushBack({ 108, 130, 17, 22 });
	triple_shot_lv3_left.speed.y = -4;
	triple_shot_lv3_left.speed.x = -2;
	triple_shot_lv3_left.life = 1000;

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(particles_texture);

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(particles_texture, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				App->audios->PlayFx(p->fx);
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, Uint32 delay)
{
	Particle* p = new Particle(particle);
	p->born = SDL_GetTicks() + delay;
	p->position.x = x;
	p->position.y = y;

	active[last_particle++] = p;
}

// Particle sruct methods-------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	return ret;
}