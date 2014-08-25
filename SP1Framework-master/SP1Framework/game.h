#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using std::vector;
using std::ifstream;
using std::string;
extern StopWatch g_timer;
extern bool g_quitGame;


enum Keys
{
	K_A,
	K_B,
	K_C,
	K_D,
	K_E,
	K_F,
	K_G,
	K_H,
	K_I,
	K_J,
	K_K,
	K_L,
	K_M,
	K_N,
	K_O,
	K_P,
	K_Q,
	K_R,
	K_S,
	K_T,
	K_U,
	K_V,
	K_W,
	K_X,
	K_Y,
	K_Z,
    K_SPACE,
	K_BACKSPACE,
	K_ESCAPE,
	K_COUNT
};

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory
void startGame();
void moveWords();
void matchWords();
#endif // _GAME_H