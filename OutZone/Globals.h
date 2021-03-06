#ifndef __GLOBALS_H__
#define __GLOBALS_H__


#include "SDL\include\SDL_rect.h"

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);
void log(const char file[], int line, const char* format, ...);

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

enum Weapon
{
	MINIGUN,
	TRIPLE_GUN,
};

//Boss lasser states
enum LMOVEMENT
{
	START,
	TURN_RIGHT,
	LASER_CREATION,
	LASER_MOVE,
	TURN_IDLE,
	RETREAT,
	FINISHED
};



// Useful typedefs ---------
typedef unsigned int uint;

// Configuration -----------
#define SCREEN_SIZE 2
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
#define WIN_FULLSCREEN 0
#define WIN_FULLSCREEN_DESKTOP 0
#define WIN_BORDERLESS 0
#define WIN_RESIZABLE 0
#define REN_VSYNC 1
#define SCREEN_SPEED 3
#define PLAYER_SPEED 3
#define ENEMY_SPEED 1.1f
#define MAX_N_ENERGY  47  //Normal energy
#define MAX_E_ENERGY 60		//Extended energy poerup, number not correct
#define MAX_ACTIVE_PARTICLES 600000

#endif // __GLOBALS_H__
