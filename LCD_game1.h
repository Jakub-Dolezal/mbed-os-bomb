
#ifndef __LCD_GAME
#define __LCD_GAME

#ifndef __LCD_STRUCT
#include "LCD_struct.h"
#endif

#ifndef __LCD_COUNTDOWN
#include "LCD_countdown.h"
#endif

#ifndef __LCD_BUTTON
#include "LCD_button.h"
#endif


// GAME SETTINGS

#define COUNTDOWN_FROM  60.0
#define COUNTDOWN_SUBTRACT 0.1
#define COUNTDOWN_SPEED 100ms
#define COUNTDOWN_TIME 20min

void update_all();

void game(LCD_Data_struct LCD_data, countdown *ct);





#endif