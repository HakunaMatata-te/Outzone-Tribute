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
#include "ModuleFadeToBlack.h"
#include "ModuleEnemies.h"
#include "ModuleUI.h"

#include "SDL\include\SDL.h"



ModulePlayer::ModulePlayer(){

	position.x = 88;
	position.y = 282;
	screenlowheight = 320;
	width = 31;
	height = 36;
	

	/* //player idle
	idle.x = 517;
	idle.y = 287;
	idle.w = 31;
	idle.h = 36; */

	//idle sprites
	idle_up.PushBack({ 521, 197, 27, 37 });
	idle_down.PushBack({ 346, 252, 28, 39 });
	idle_right.PushBack({360, 305, 29, 35});
	idle_left.PushBack({86, 362, 29, 35});
	
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
	upward_right.speed = 0.1f;

	//upward left animation
	upward_left.PushBack({435, 61, 28, 36 });
	upward_left.PushBack({ 437, 108, 28, 36 });
	upward_left.speed = 0.1f;
	

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

	//TRIPLE GUN ANIMATIONS!!
	rightward_triple_gun.PushBack({ 41, 36, 30, 36 });
	rightward_triple_gun.PushBack({ 41, 81, 30, 37 });
	rightward_triple_gun.PushBack({ 41, 127, 30, 37 });
	rightward_triple_gun.PushBack({ 41, 173, 30, 37 });
	rightward_triple_gun.PushBack({ 41, 219, 30, 37 });
	rightward_triple_gun.speed = 0.1f;

	leftward_triple_gun.PushBack({ 120, 36, 30, 37 });
	leftward_triple_gun.PushBack({ 120, 81, 31, 37 });
	leftward_triple_gun.PushBack({ 120, 127, 30, 37 });
	leftward_triple_gun.PushBack({ 120, 173, 30, 37 });
	leftward_triple_gun.PushBack({ 120, 219, 30, 36 });
	leftward_triple_gun.speed = 0.1f;

	downward_triple_gun.PushBack({ 278, 35, 30, 37 });
	downward_triple_gun.PushBack({ 278, 82, 30, 36 });
	downward_triple_gun.PushBack({ 278, 128, 30, 37 });
	downward_triple_gun.PushBack({ 278, 175, 30, 37 });
	downward_triple_gun.PushBack({ 278, 218, 31, 37 });
	downward_triple_gun.speed = 0.1f;

	upward_triple_gun.PushBack({ 199, 36, 30, 37 });
	upward_triple_gun.PushBack({ 199, 81, 30, 37 });
	upward_triple_gun.PushBack({ 199, 127, 30, 37 });
	upward_triple_gun.PushBack({ 199, 172, 30, 37 }); //only uses 4 animations, not 5 like previous movements
	upward_triple_gun.speed = 0.1f;

}

ModulePlayer::~ModulePlayer(){};

bool ModulePlayer::Start(){
	LOG("Loading player-----------");
	up = 0;
	left = 0;
	position.x = 88;
	position.y = 282;
	position_test.x = 50;
	position_test.y = 150;
	screenlowheight = 320;	
	destroyed = false;
	fall_animation = false;
	spbombmunition = 3;
	speed = PLAYER_SPEED;
	current_weapon = MINIGUN;
	lvl = 1;
	player_dir = 0;
	
	character = App->textures->Load("Animation/playermove.png");

	playercollider = App->collision->AddCollider({ 88,250, 22,20 }, COLLIDER_PLAYER, App->player);
	fx_lvlup_weapon = App->audios->LoadFX("Sounds/power_up_weapon.ogg");

	return true;
};

bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(character);

	return true;
}

update_status ModulePlayer::Update(){

	last_dir = player_dir;

	//Special Screen bomb
	if (App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_DOWN && spbombmunition >= 0)
	{
		App->particles->AddParticle(App->particles->screen_bomb, 0, screenlowheight - SCREEN_HEIGHT, COLLIDER_SCREEN_BOMB, 0);
		spbombmunition--;
	}

	//Set direction
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_REPEAT){
		if (position.y - height > (screenlowheight - 320))
			if (CollisionUp == false)
				position.y -= speed;
		if (player_dir <= 8 && player_dir != 0)
			player_dir--;
		if (player_dir > 8 && player_dir != 0)
			player_dir++;
	}

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_REPEAT){
		if (position.y < (screenlowheight)-height)
			if (CollisionDown == false)
				position.y += speed;
		if (player_dir < 8)
			player_dir++;
		if (player_dir > 8)
			player_dir--;
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_REPEAT){
		if (position.x >= 0)
			if (CollisionLeft == false)
				position.x -= speed;

		if (player_dir < 12 && player_dir>4)
			player_dir++;
		if (player_dir > 12 || player_dir <= 4)
			player_dir--;
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_REPEAT){
		if (position.x < SCREEN_WIDTH - width)
			if (CollisionRight == false)
				position.x += speed;
		if (player_dir < 12 && player_dir>4)
			player_dir--;
		if (player_dir >= 12 || player_dir < 4)
			player_dir++;
	}

	//if (App->input->keyboard[SDL_SCANCODE_D] == KEY_IDLE && App->input->keyboard[SDL_SCANCODE_A] == KEY_IDLE && App->input->keyboard[SDL_SCANCODE_S] == KEY_IDLE)

	//Reseting position to 0 making a loop with directions
	if (player_dir > 15)
		player_dir = 0;
	if (player_dir < 0)
		player_dir = 15;

	//Dir check
	if (current_weapon == MINIGUN){
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
		if (player_dir > 12 && player_dir <= 15)
			current_animation = &upward_left;
	}

	if (current_weapon == TRIPLE_GUN) {
		if (player_dir > 12 || player_dir < 4)
			current_animation = &upward_triple_gun;
		if (player_dir == 12)
			current_animation = &leftward_triple_gun;
		if (player_dir == 4)
			current_animation = &rightward_triple_gun;
		if (player_dir < 12 && player_dir>4)
			current_animation = &downward_triple_gun;
	}



	//Player shoting
	if (current_weapon == MINIGUN && App->input->keyboard[SDL_SCANCODE_E] == KEY_REPEAT && (SDL_GetTicks() - lastShot > 100 || player_dir != last_dir)){
		if (lvl == 1){
			if (player_dir == 0)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_up, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 1)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_upper_right, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 2)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_up_right, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 3)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_up_righter, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 4)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_right, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 5)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_down_righter, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 6)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_down_right, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 7)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_downer_right, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 8)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_down, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 9)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_downer_left, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 10)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_down_left, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 11)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_down_lefter, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 12)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_left, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 13)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_up_lefter, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 14)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_up_left, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 15)
				App->particles->AddParticle(App->particles->minigun_shot_lv1_upper_left, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);

			lastShot = SDL_GetTicks();
		}
		else if (lvl == 2){
			if (player_dir == 0)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_up, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 1)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_upper_right, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 2)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_up_right, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 3)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_up_righter, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 4)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_right, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 5)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_down_righter, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 6)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_down_right, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 7)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_downer_right, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 8)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_down, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 9)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_downer_left, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 10)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_down_left, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 11)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_down_lefter, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 12)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_left, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 13)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_up_lefter, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 14)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_up_left, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);
			if (player_dir == 15)
				App->particles->AddParticle(App->particles->minigun_shot_lv2_upper_left, position.x + (3 * width / 4), position.y, COLLIDER_PLAYER_SHOT);

			lastShot = SDL_GetTicks();
		}
		else if (lvl == 3){
			if (player_dir == 0){
				App->particles->minigun_shot_lv3.speed.x = 0;
				App->particles->minigun_shot_lv3.speed.y = -8;
			}
			if (player_dir == 1){
				App->particles->minigun_shot_lv3.speed.x = +4;
				App->particles->minigun_shot_lv3.speed.y = -8;
			}
			if (player_dir == 2){
				App->particles->minigun_shot_lv3.speed.x = +8;
				App->particles->minigun_shot_lv3.speed.y = -8;
			}
			if (player_dir == 3){
				App->particles->minigun_shot_lv3.speed.x = +8;
				App->particles->minigun_shot_lv3.speed.y = -4;
			}
			if (player_dir == 4){
				App->particles->minigun_shot_lv3.speed.x = +8;
				App->particles->minigun_shot_lv3.speed.y = 0;
			}
			if (player_dir == 5){
				App->particles->minigun_shot_lv3.speed.x = +8;
				App->particles->minigun_shot_lv3.speed.y = +4;
			}
			if (player_dir == 6){
				App->particles->minigun_shot_lv3.speed.x = +8;
				App->particles->minigun_shot_lv3.speed.y = +8;
			}
			if (player_dir == 7){
				App->particles->minigun_shot_lv3.speed.x = +4;
				App->particles->minigun_shot_lv3.speed.y = +8;
			}
			if (player_dir == 8){
				App->particles->minigun_shot_lv3.speed.x = 0;
				App->particles->minigun_shot_lv3.speed.y = +8;
			}
			if (player_dir == 9){
				App->particles->minigun_shot_lv3.speed.x = -4;
				App->particles->minigun_shot_lv3.speed.y = +8;
			}
			if (player_dir == 10){
				App->particles->minigun_shot_lv3.speed.x = -8;
				App->particles->minigun_shot_lv3.speed.y = +8;
			}
			if (player_dir == 11){
				App->particles->minigun_shot_lv3.speed.x = -8;
				App->particles->minigun_shot_lv3.speed.y = +4;
			}
			if (player_dir == 12){
				App->particles->minigun_shot_lv3.speed.x = -8;
				App->particles->minigun_shot_lv3.speed.y = 0;
			}
			if (player_dir == 13){
				App->particles->minigun_shot_lv3.speed.x = -8;
				App->particles->minigun_shot_lv3.speed.y = -4;
			}
			if (player_dir == 14){
				App->particles->minigun_shot_lv3.speed.x = -8;
				App->particles->minigun_shot_lv3.speed.y = -8;
			}
			if (player_dir == 15){
				App->particles->minigun_shot_lv3.speed.x = -4;
				App->particles->minigun_shot_lv3.speed.y = -8;
			}
			App->particles->AddParticle(App->particles->minigun_shot_lv3, position.x + width / 2, position.y, COLLIDER_PLAYER_SHOT);
			lastShot = SDL_GetTicks();
		}
	}


	if (current_weapon == TRIPLE_GUN && (App->input->keyboard[SDL_SCANCODE_E] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_E] == KEY_REPEAT && SDL_GetTicks() - lastShot > 700)){
		if (lvl == 1){
			App->particles->AddParticle(App->particles->triple_shot_lv1_center, position.x + width / 2, position.y, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->triple_shot_lv1_right, position.x + 3 + width / 2, position.y, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->triple_shot_lv1_left, position.x - 6 + width / 2, position.y, COLLIDER_PLAYER_SHOT);
			lastShot = SDL_GetTicks();
		}
		else if (lvl == 2){
			App->particles->AddParticle(App->particles->triple_shot_lv2_center, position.x + width / 2, position.y, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->triple_shot_lv2_right, position.x + 3 + width / 2, position.y, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->triple_shot_lv2_left, position.x - 6 + width / 2, position.y, COLLIDER_PLAYER_SHOT);
			lastShot = SDL_GetTicks();
		}
		else if (lvl == 3){
			App->particles->AddParticle(App->particles->triple_shot_lv3_center, position.x + width / 2, position.y, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->triple_shot_lv3_right, position.x + 3 + width / 2, position.y, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->triple_shot_lv3_left, position.x - 6 + width / 2, position.y, COLLIDER_PLAYER_SHOT);
			lastShot = SDL_GetTicks();
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

		App->audios->PlayFx(fx_lvlup_weapon);
	}

	playercollider->SetPos(position.x + 5, position.y + 10);

	//Energy depletion
	if (App->input->keyboard[SDL_SCANCODE_U] == KEY_DOWN)
		App->ui->infinite_energy = !App->ui->infinite_energy;

	//Print player
	if (destroyed == false)
		App->render->Blit(character, position.x, position.y, &current_animation->GetCurrentFrame());

	//Debug funtions -----------------------------------------------------------

	//invencible mode
	if (App->input->keyboard[SDL_SCANCODE_I] == KEY_DOWN)
		invencible = !invencible;

	//tp to boss
	if (App->input->keyboard[SDL_SCANCODE_B]){
		position.y = -5600;
		App->render->camera.y = 5900 * SCREEN_SIZE;
		screenlowheight = -5600;
	}



		

	return UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	CollisionUp = false;
	CollisionDown = false;
	CollisionLeft = false;
	CollisionRight = false;

	//Energy depletion death
	if (invencible == false){
		if (App->ui->energy == 0){
			Disable();
			
			App->fade->FadeToBlack((Module*)App->level_3, (Module*)App->gameover, 1);

			App->particles->AddParticle(App->particles->player_explosion, position.x, position.y, COLLIDER_NONE);

			destroyed = true;
		}
	}

	return UPDATE_CONTINUE;
}


void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == playercollider && (c2->type == COLLIDER_WALL || c2->type == COLLIDER_BOX))
	{
		//side_wall = c1->CheckCollisionSide(c2->rect);
		if (CollisionUp == false)
			CollisionUp = c1->CheckCollisionUp(c2->rect);
		if (CollisionDown == false)
			CollisionDown = c1->CheckCollisionDown(c2->rect);
		if (CollisionRight == false)
			CollisionRight = c1->CheckCollisionRight(c2->rect);
		if (CollisionLeft == false)
			CollisionLeft = c1->CheckCollisionLeft(c2->rect);
	}
	//Lose Condition
	if (invencible == false){
		if (playercollider == c1 && c2->type == COLLIDER_ENEMY || c2->type == COLLIDER_ENEMY_SHOT && App->fade->IsFading() == false)
		{
			Disable();
			App->fade->FadeToBlack((Module*)App->level_3, (Module*)App->gameover, 1);

			App->particles->AddParticle(App->particles->player_explosion, position.x, position.y, COLLIDER_NONE);
			App->ui->energy = MAX_N_ENERGY;
			destroyed = true;

		}
	}
	if (c1 == playercollider && c2->type == COLLIDER_HOLE && c1->CheckCollisionhole(c2->rect) == true)
	{
		Disable();
		if (fall_animation == false){
			App->particles->AddParticle(App->particles->player_fall, position.x, position.y, COLLIDER_NONE);
			fall_animation = true;
		}
		App->fade->FadeToBlack((Module*)App->level_3, (Module*)App->gameover, 5);
		
		destroyed = true;
	}
	//Win Condition
}
