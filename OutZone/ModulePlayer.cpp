#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollider.h"
#include "ModuleLevel_1.h"



ModulePlayer::ModulePlayer(){

	position.x = 88;
	position.y = 282;
	screenlowheight = 320;
	width = 31;
	height = 36;
	

	//player stand same place;
	idle.x = 517;
	idle.y = 287;
	idle.w = 31;
	idle.h = 36;
	
	// walk upward animation (arcade sprite sheet)
	upward.PushBack({ 517, 151, 31, 38 });
	upward.PushBack({ 517, 197, 31, 38 });
	upward.PushBack({ 517, 240, 31, 38 });
	upward.PushBack({ 517, 287, 31, 38 });
	upward.PushBack({ 517, 334, 31, 38 });
	upward.speed = 0.1f;

	//upward right animation
	upward_right.PushBack({600, 293, 25, 36});
	upward_right.PushBack({358, 73, 27, 36 });
	upward_right.speed == 0.1f;

	//upward left animation
	upward_left.PushBack({435, 61, 28, 36 });
	upward_left.PushBack({ 437, 108, 28, 36 });
	upward_left.speed == 0.1f;
	

	//walk downward animation
	downward.PushBack({ 434, 252, 31, 38 });
	downward.PushBack({ 434, 302, 31, 38 });
	downward.PushBack({ 434, 352, 31, 38 });
	downward.PushBack({ 434, 400, 31, 38 });
	downward.PushBack({ 434, 450, 31, 38 });
	downward.speed = 0.1f;

	//downward right animation
	downward_right.PushBack({248, 403, 28, 37});
	downward_right.PushBack({ 248, 448, 27, 37 });
	downward_right.speed = 0.1f;
	
	//downward left animation
	downward_left.PushBack({248, 326, 30, 37});
	downward_left.PushBack({ 162, 405, 30, 37 });
	downward_left.speed = 0.1f;

	//walk rightward animation
	rightward.PushBack({ 354, 118, 31, 38 });
	rightward.PushBack({ 354, 164, 31, 38 });
	rightward.PushBack({ 354, 212, 31, 38 });
	rightward.PushBack({ 354, 257, 31, 38 });
	rightward.PushBack({ 354, 304, 31, 38 });
	rightward.speed = 0.1f;

	//walk leftward animation
	leftward.PushBack({ 84, 274, 31, 38 });
	leftward.PushBack({ 84, 316, 31, 38 });
	leftward.PushBack({ 84, 360, 31, 38 });
	leftward.PushBack({ 84, 405, 31, 38 });
	leftward.PushBack({ 84, 448, 31, 38 });
	leftward.speed = 0.1f;

	//BIG GUN ANIMATIONS!!
	rightward_triple_gun.PushBack({ 41, 51, 30, 36 });
	rightward_triple_gun.PushBack({ 41, 96, 30, 37 });
	rightward_triple_gun.PushBack({ 41, 142, 30, 37 });
	rightward_triple_gun.PushBack({ 41, 188, 30, 37 });
	rightward_triple_gun.PushBack({ 41, 234, 30, 37 });
	rightward_triple_gun.speed = 0.1f;

	leftward_triple_gun.PushBack({ 120, 51, 30, 37 });
	leftward_triple_gun.PushBack({ 120, 96, 31, 37 });
	leftward_triple_gun.PushBack({ 120, 141, 30, 37 });
	leftward_triple_gun.PushBack({ 120, 188, 30, 37 });
	leftward_triple_gun.PushBack({ 120, 234, 30, 36 });
	leftward_triple_gun.speed = 0.1f;

	downward_triple_gun.PushBack({ 278, 50, 30, 37 });
	downward_triple_gun.PushBack({ 278, 97, 30, 36 });
	downward_triple_gun.PushBack({ 278, 143, 30, 37 });
	downward_triple_gun.PushBack({ 278, 190, 30, 37 });
	downward_triple_gun.PushBack({ 278, 233, 31, 37 });
	downward_triple_gun.speed = 0.1f;

	upward_triple_gun.PushBack({ 199, 51, 30, 37 });
	upward_triple_gun.PushBack({ 199, 96, 30, 37 });
	upward_triple_gun.PushBack({ 199, 142, 30, 36 });
	upward_triple_gun.PushBack({ 199, 187, 30, 37 }); //only uses 4 animations, not 5 like previous movements
	upward_triple_gun.speed = 0.1f;
}

ModulePlayer::~ModulePlayer(){};

bool ModulePlayer::Start(){
	LOG("Loading player-----------");

	position.x = 88;
	position.y = 282;
	screenlowheight = 320;	

	current_weapon = MINIGUN;
	lvl = 1;
	player_dir = 0;
	character = App->textures->Load("Animation/playermove.png");


	playercollider = App->collision->AddCollider({ 88,250,31,36 }, COLLIDER_PLAYER);

	return true;
};

bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(character);

	return true;
}

update_status ModulePlayer::Update(){

	
	
	int speed = 2;
	
	//Set direction
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_REPEAT){
		position.y -= speed;
		if (player_dir <= 8 && player_dir != 0)
			player_dir--;
		if (player_dir > 8 && player_dir != 0)
			player_dir++;
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT){
		position.y += speed;
		if (player_dir < 8)
			player_dir++;
		if (player_dir > 8)
			player_dir--;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT){
		position.x -= speed;
		
		if (player_dir < 12 && player_dir>4)
			player_dir++;
		if (player_dir > 12 || player_dir<=4)
			player_dir--;
	}
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT){
		position.x += speed;

		if (player_dir < 12 && player_dir>4)
			player_dir--;
		if (player_dir >= 12 || player_dir < 4)
			player_dir++;
	}
	
	//Reseting position to 0 making a loop with directions
	if (player_dir==16)
		player_dir = 0;
	if (player_dir == -1)
		player_dir = 15;

	
	
	//Dir check
	if (player_dir == 0)
		current_animation = &upward;
	if (player_dir < 4 && player_dir>0)
		current_animation = &upward_right;
	if (player_dir == 4)
		current_animation = &rightward;
	if (player_dir < 8 && player_dir>4)
		current_animation = &downward_right;
	if (player_dir == 8)
		current_animation = &downward;
	if (player_dir < 12 && player_dir>8)
		current_animation = &downward_left;
	if (player_dir == 12)
		current_animation = &leftward;
	if (player_dir > 12)
		current_animation = &upward_left;



	//Print player
	App->render->Blit(character, position.x, position.y, &current_animation->GetCurrentFrame());
	playercollider->SetPos(position.x, position.y);

	//Player shoting
	if (App->input->keyboard[SDL_SCANCODE_E] == KEY_DOWN){

		if (current_weapon == MINIGUN){		
			if (lvl == 1){
				App->particles->AddParticle(App->particles->minigun_shot_lv1, position.x + (3 * width / 4), position.y - height);
			}
			else if (lvl == 2){
				App->particles->AddParticle(App->particles->minigun_shot_lv2, position.x + (3 * width / 4), position.y - height);
			}
			else if (lvl == 3){
				App->particles->AddParticle(App->particles->minigun_shot_lv3, position.x + (3 * width / 4), position.y - height);
			}
		}


		if (current_weapon == TRIPLE_GUN){
			if (lvl == 1){
				App->particles->AddParticle(App->particles->triple_shot_lv1_center, position.x + width / 2, position.y - height);
				App->particles->AddParticle(App->particles->triple_shot_lv1_right, position.x + 3 + width / 2, position.y - height);
				App->particles->AddParticle(App->particles->triple_shot_lv1_left, position.x - 6 + width / 2, position.y - height);
			}
			else if (lvl == 2){
				App->particles->AddParticle(App->particles->triple_shot_lv2_center, position.x + width / 2, position.y - height);
				App->particles->AddParticle(App->particles->triple_shot_lv2_right, position.x + 3 + width / 2, position.y - height);
				App->particles->AddParticle(App->particles->triple_shot_lv2_left, position.x - 6 + width / 2, position.y - height);
			}
			else if (lvl == 3){
				App->particles->AddParticle(App->particles->triple_shot_lv3_center, position.x + width / 2, position.y - height);
				App->particles->AddParticle(App->particles->triple_shot_lv3_right, position.x + 3 + width / 2, position.y - height);
				App->particles->AddParticle(App->particles->triple_shot_lv3_left, position.x - 6 + width / 2, position.y - height);
			}
		}

	}

	//Weapon change
	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_DOWN){

		if (current_weapon == MINIGUN)
			current_weapon = TRIPLE_GUN;
		else if (current_weapon == TRIPLE_GUN)
			current_weapon = MINIGUN;
	}


	//LVL up weapons

	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_DOWN) { 
		if (lvl < 3)
			lvl++;
		else
			lvl = 1;		//Reset the lvl allowing loop, for testing purposes only
	}


	/*
	uint colliders = lvl_collision->size();
	
	for (uint i = 0; i < colliders; i++)
	{
		if (playercollider->CheckCollision(lvl_collision[i].))
	}*/

	uint colliders = App->level_1->lvl_collider.size();

	for (uint i = 0; i < colliders; i++)
	{

		if (playercollider->CheckCollision(App->level_1->lvl_collider[i]->rect))
		{
			if (App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT)
				position.x -= speed;
			if (App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT)
				position.x += speed;
			if (App->input->keyboard[SDL_SCANCODE_W] == KEY_REPEAT)
				position.y += speed;
			if (App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT)
				position.y -= speed;
		}

	}
	

	return UPDATE_CONTINUE;
}

