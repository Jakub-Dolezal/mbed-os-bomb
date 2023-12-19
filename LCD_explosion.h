#ifndef __LCD_EXPLOSION
#define __LCD_EXPLOSION

#ifndef __LCD_DISCO_F469NI_H
#include "LCD_DISCO_F469NI.h"
#endif

#ifndef __LCD_STRUCT
#include "LCD_struct.h"
#endif

void explode(LCD_DISCO_F469NI *lcd,Mutex *lock);

#endif