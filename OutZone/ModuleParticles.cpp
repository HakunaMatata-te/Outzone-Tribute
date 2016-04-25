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
	particles_texture = App->textures->Load("Animation/particles.png");

	//LVL 1 particles --------------------------------------------------------------

	int life_shots = 1500;

	// Minigun particle
	minigun_shot_lv1_up.anim.PushBack({ 55, 244, 4, 16 });
	minigun_shot_lv1_up.speed.y = -8;
	minigun_shot_lv1_up.life = life_shots;
	minigun_shot_lv1_up.fx = App->audios->LoadFX("Sounds/minigun_shot.wav");
	//upper rigth
	minigun_shot_lv1_upper_right.anim.PushBack({ 55, 244, 4, 16 });
	minigun_shot_lv1_upper_right.speed.x = +4;
	minigun_shot_lv1_upper_right.speed.y = -8;
	minigun_shot_lv1_upper_right.life = 1000;
	//upper left
	minigun_shot_lv1_upper_left.anim.PushBack({ 55, 244, 4, 16 });
	minigun_shot_lv1_upper_left.speed.x = -4;
	minigun_shot_lv1_upper_left.speed.y = -8;
	minigun_shot_lv1_upper_left.life = life_shots;
	//up rigth
	minigun_shot_lv1_up_right.anim.PushBack({ 55, 244, 4, 16 });
	minigun_shot_lv1_up_right.speed.x = +8;
	minigun_shot_lv1_up_right.speed.y = -8;
	minigun_shot_lv1_up_right.life = life_shots;
	//up rigther
	minigun_shot_lv1_up_righter.anim.PushBack({ 55, 244, 4, 16 });
	minigun_shot_lv1_up_righter.speed.x = +8;
	minigun_shot_lv1_up_righter.speed.y = -4;
	minigun_shot_lv1_up_righter.life = life_shots;
	//up rigth
	minigun_shot_lv1_right.anim.PushBack({ 55, 244, 4, 16 });
	minigun_shot_lv1_right.speed.x = +8;
	minigun_shot_lv1_right.life = life_shots;


	// Triple shot particle
	triple_shot_lv1_center.anim.PushBack({ 137, 246, 6, 14 });
	triple_shot_lv1_center.speed.y = -4;
	triple_shot_lv1_center.life = life_shots;
	triple_shot_lv1_center.fx = App->audios->LoadFX("Sounds/triple_shot.wav");
	//Triple right
	triple_shot_lv1_right.anim.PushBack({ 155, 247, 9, 13 });
	triple_shot_lv1_right.speed.y = -4;
	triple_shot_lv1_right.speed.x = +2;
	triple_shot_lv1_right.life = life_shots;
	//Triple left
	triple_shot_lv1_left.anim.PushBack({ 116, 247, 9, 13 });
	triple_shot_lv1_left.speed.y = -4;
	triple_shot_lv1_left.speed.x = -2;
	triple_shot_lv1_left.life = life_shots;


	//LVL 2 particles

	//Minigun
	minigun_shot_lv2.anim.PushBack({ 52, 219, 10, 16 });
	minigun_shot_lv2.speed.y = -4;
	minigun_shot_lv2.life = life_shots;
	minigun_shot_lv2.fx = minigun_shot_lv1_up.fx;

	// Triple shot particle
	triple_shot_lv2_center.anim.PushBack({ 135, 221, 10, 18 });
	triple_shot_lv2_center.speed.y = -4;
	triple_shot_lv2_center.life = life_shots;
	triple_shot_lv2_center.fx = triple_shot_lv1_center.fx;
	//Triple right
	triple_shot_lv2_right.anim.PushBack({ 165, 224, 12, 17 });
	triple_shot_lv2_right.speed.y = -4;
	triple_shot_lv2_right.speed.x = +2;
	triple_shot_lv2_right.life = life_shots;
	//Triple left
	triple_shot_lv2_left.anim.PushBack({ 103, 224, 12, 17 });
	triple_shot_lv2_left.speed.y = -4;
	triple_shot_lv2_left.speed.x = -2;
	triple_shot_lv2_left.life = life_shots;


	//LVL 3 particles

	//Minigun
	minigun_shot_lv3.anim.PushBack({ 45, 128, 24, 24 });
	minigun_shot_lv3.anim.PushBack({45, 100, 24, 24});
	minigun_shot_lv3.anim.speed = 0.25f;
	minigun_shot_lv3.speed.y = -4;
	minigun_shot_lv3.life = life_shots;
	minigun_shot_lv3.fx = minigun_shot_lv1_up.fx;

	// Triple shot particle
	triple_shot_lv3_center.anim.PushBack({ 133, 130, 14, 23 });
	triple_shot_lv3_center.speed.y = -4;
	triple_shot_lv3_center.life = life_shots;
	triple_shot_lv3_center.fx = triple_shot_lv1_center.fx;
	//Triple right
	triple_shot_lv3_right.anim.PushBack({ 155, 130, 17, 22 });
	triple_shot_lv3_right.speed.y = -4;
	triple_shot_lv3_right.speed.x = +2;
	triple_shot_lv3_right.life = life_shots;
	//Triple left
	triple_shot_lv3_left.anim.PushBack({ 108, 130, 17, 22 });
	triple_shot_lv3_left.speed.y = -4;
	triple_shot_lv3_left.speed.x = -2;
	triple_shot_lv3_left.life = life_shots;

	//Normal explosion
	normal_explosion.anim.PushBack({ 71, 537, 38, 38});
	normal_explosion.anim.PushBack({ 124, 537, 39, 38 });
	normal_explosion.anim.PushBack({ 182, 534, 44, 43});
	normal_explosion.anim.PushBack({ 245, 536, 39, 37 });
	normal_explosion.anim.PushBack({ 303, 539, 30, 36 });
	normal_explosion.anim.PushBack({ 352, 536, 24, 29 });
	normal_explosion.anim.PushBack({ 395, 536, 16, 19 });
	normal_explosion.anim.PushBack({ 436, 534, 9, 11 });
	normal_explosion.anim.loop = false;
	normal_explosion.anim.speed = 0.3f;
	normal_explosion.fx = App->audios->LoadFX("Sounds/death_small_enemies.wav");

	//Player explosion
	player_explosion.anim.PushBack({127,625,16,16});
	player_explosion.anim.PushBack({ 228, 617, 32, 31 });
	player_explosion.anim.PushBack({ 313, 605, 64, 69 });
	player_explosion.anim.PushBack({ 68, 696, 86, 90 });
	player_explosion.anim.PushBack({ 185, 690, 117, 115 });
	player_explosion.anim.PushBack({ 320, 696, 113, 113 });
	player_explosion.anim.PushBack({ 48, 820, 112, 113 });
	player_explosion.anim.PushBack({ 118, 829, 114, 104 });
	player_explosion.anim.PushBack({ 328, 845, 113, 91 });
	player_explosion.anim.loop = false;
	player_explosion.anim.speed = 0.3f;
	normal_explosion.fx = App->audios->LoadFX("Sounds/player_die.wav");

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

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				if (collider_type == COLLIDER_PLAYER_SHOT)
					p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			//AddParticle(explosion, active[i]->position.x, active[i]->position.y);
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// Particle sruct methods-------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::~Particle()
{
	if (collider != nullptr)
		App->collision->EraseCollider(collider);
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

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}