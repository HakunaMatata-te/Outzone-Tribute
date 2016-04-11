#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"


ModulePlayer::ModulePlayer(){
	position.x = 88;
	position.y = 282;
	width = 31;
	height = 36;

	//player stand same place;
	stand.x = 517;
	stand.y = 287;
	stand.w = 31;
	stand.h = 36;

	//walk leftward animation
	leftward.PushBack({ 84, 274, 31, 38 });
	leftward.PushBack({ 84, 316, 31, 38 });
	leftward.PushBack({ 84, 360, 31, 38 });
	leftward.PushBack({ 84, 405, 31, 38 });
	leftward.PushBack({ 84, 448, 31, 38 });
	upward.speed = 0.2f;

	//walk rightward animation
	rightward.PushBack({ 354, 118, 31, 38 });
	rightward.PushBack({ 354, 164, 31, 38 });
	rightward.PushBack({ 354, 212, 31, 38 });
	rightward.PushBack({ 354, 257, 31, 38 });
	rightward.PushBack({ 354, 304, 31, 38 });
	upward.speed = 0.2f;

	// walk upward animation (arcade sprite sheet)

	upward.PushBack({ 517, 151, 31, 38 });
	upward.PushBack({ 517, 197, 31, 38 });
	upward.PushBack({ 517, 240, 31, 38 });
	upward.PushBack({ 517, 287, 31, 38 });
	upward.PushBack({ 517, 334, 31, 38 });
	upward.speed = 0.2f;

	// TODO 4: Make ryu walk backwards with the correct animations

	downward.PushBack({ 434, 252, 31, 38 });
	downward.PushBack({ 434, 302, 31, 38 });
	downward.PushBack({ 434, 352, 31, 38 });
	downward.PushBack({ 434, 400, 31, 38 });
	downward.PushBack({ 434, 450, 31, 38 });
	downward.speed = 0.3f;
}

ModulePlayer::~ModulePlayer(){};

bool ModulePlayer::Start(){
	LOG("Loading player-----------");
	bool ret = true;

	character = App->textures->Load("playermove.png");
	return ret;
};

update_status ModulePlayer::Update(){
	
	Animation* current_animation = &upward;
	
	int speed = 5;

	if (App->input->keyboard[SDL_SCANCODE_W] || App->input->keyboard[SDL_SCANCODE_S] || App->input->keyboard[SDL_SCANCODE_D] || App->input->keyboard[SDL_SCANCODE_A]){
		if (App->input->keyboard[SDL_SCANCODE_W] == 1)
		{
			current_animation = &upward;
			if (position.y - height > (screenlowheight - 320)){
				position.y -= speed;
			}
			//screenlowheight -= SCREEN_SPEED;
		}
		if (App->input->keyboard[SDL_SCANCODE_S] == 1)
		{
			current_animation = &downward;
			if (position.y < (screenlowheight)){
				position.y += speed;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_A] == 1)
		{
			current_animation = &leftward;
			if (position.x >= 0){
				position.x -= speed;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_D] == 1)
		{
			current_animation = &rightward;
			if (position.x < SCREEN_WIDTH - width){
				position.x += speed;
			}
		}
		SDL_Rect r = current_animation->GetCurrentFrame();
		App->render->Blit(character, position.x, position.y - r.h, &r);

	}
	else
		App->render->Blit(character, position.x, position.y - stand.h, &stand);


	return UPDATE_CONTINUE;
}