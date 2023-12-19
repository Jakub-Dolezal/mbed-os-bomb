
#ifndef __LCD_STRUCT
#define __LCD_STRUCT

#ifndef __LCD_DISCO_F469NI_H
#include "LCD_DISCO_F469NI.h"
#endif

#ifndef __TS_DISCO_F469NI_H
#include "TS_DISCO_F469NI.h"
#endif

struct LCD_Data_struct{
    LCD_DISCO_F469NI* LCD;
    Mutex* LCD_lock;
    TS_DISCO_F469NI* TS; // Touch Screen
    Mutex* TS_lock;
};

#endif