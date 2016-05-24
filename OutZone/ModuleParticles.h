#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollider.h"

#define MAX_ACTIVE_PARTICLES 2000

struct SDL_Texture;



struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
};

struct Particle_Bullet
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	fPoint position;
	fPoint player;
	float speed;
	float angle;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle_Bullet();
	Particle_Bullet(const Particle_Bullet& p);
	~Particle_Bullet();
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
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay = 0);

	void AddParticle_Bullet_Enemy(const Particle_Bullet& particle, int x, int y, COLLIDER_TYPE collider_type, uint angle, Uint32 delay = 0);

	void Shots_explosion(int x, int y);

private:

	SDL_Texture* particles_texture = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];
	Particle_Bullet* active_b[MAX_ACTIVE_PARTICLES];
	int life_shots = 500;

public:

	Particle minigun_shot_lv1_up;
	Particle minigun_shot_lv1_upper_right;
	Particle minigun_shot_lv1_upper_left;
	Particle minigun_shot_lv1_up_right;
	Particle minigun_shot_lv1_up_left;
	Particle minigun_shot_lv1_up_righter;
	Particle minigun_shot_lv1_up_lefter;
	Particle minigun_shot_lv1_right;
	Particle minigun_shot_lv1_left;
	Particle minigun_shot_lv1_down_righter;
	Particle minigun_shot_lv1_down_right;
	Particle minigun_shot_lv1_downer_right;
	Particle minigun_shot_lv1_down;
	Particle minigun_shot_lv1_down_left;
	Particle minigun_shot_lv1_downer_left;
	Particle minigun_shot_lv1_down_lefter;

	Particle minigun_shot_lv2_up;
	Particle minigun_shot_lv2_upper_right;
	Particle minigun_shot_lv2_upper_left;
	Particle minigun_shot_lv2_up_right;
	Particle minigun_shot_lv2_up_left;
	Particle minigun_shot_lv2_up_righter;
	Particle minigun_shot_lv2_up_lefter;
	Particle minigun_shot_lv2_right;
	Particle minigun_shot_lv2_left;
	Particle minigun_shot_lv2_down_righter;
	Particle minigun_shot_lv2_down_right;
	Particle minigun_shot_lv2_downer_right;
	Particle minigun_shot_lv2_down;
	Particle minigun_shot_lv2_down_left;
	Particle minigun_shot_lv2_downer_left;
	Particle minigun_shot_lv2_down_lefter;

	Particle minigun_shot_lv3;


	Particle triple_shot_lv1_center;
	Particle triple_shot_lv1_right;
	Particle triple_shot_lv1_left;
	Particle triple_shot_lv2_center;
	Particle triple_shot_lv2_right;
	Particle triple_shot_lv2_left;
	Particle triple_shot_lv3_center;
	Particle triple_shot_lv3_right;
	Particle triple_shot_lv3_left;

	Particle normal_explosion;

	Particle player_explosion;

	Particle screen_bomb;

	Particle player_fall;

	Particle right_laser_turret_light;
	Particle right_laser_turret_shot;

	Particle left_laser_turret_light;
	Particle left_laser_turret_shot;

	Particle left_Shield_Tank_Case;
	Particle right_Shield_Tank_Case;

	Particle blue_shot_left;
	Particle blue_shot_center;
	Particle blue_shot_right;

	Animation shot_explosion;
	Animation triple_gun_shot_explosion;

	Particle_Bullet test;
};

#endif // !__MODULEPARTICLES_H__
