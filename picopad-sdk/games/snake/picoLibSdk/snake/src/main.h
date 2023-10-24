// ****************************************************************************
//
//                                 Main code
//
// ****************************************************************************

#ifndef _MAIN_H
#define _MAIN_H

// Sound files
#include "../snd/eatSnd.h"
#include "../snd/deadSnd.h"

// Image files
#include "../img/deadPict.h"

// Definition of snake
#define WIDTH_SNAKE 80
#define HEIGHT_SNAKE 60
#define SNAKE_SIZE 6

// Sound definition
extern const u8 EatSnd[13848];
extern const u8 deadSnd[85328];

// Graphic definition
#define COL_BACKGROUND	RGBTO16(135, 165, 5)
#define COL_BODY        RGBTO16(33, 45, 22)
#define COL_SCORE       RGBTO16(33, 45, 22)

//Variables for pause
bool pause = false;
int isPause = 0;

//Score area definition
#define SCORE_AREA 6

//Variables for score
int score = 0;
char scoreText[20];

#endif // _MAIN_H
