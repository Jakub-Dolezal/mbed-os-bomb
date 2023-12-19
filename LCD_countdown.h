#ifndef __LCD_COUNTDOWN
#define __LCD_COUNTDOWN

#ifndef __LCD_DISCO_F469NI_H
#include "LCD_DISCO_F469NI.h"
#endif

#ifndef __LCD_STRUCT
#include "LCD_struct.h"
#endif

class countdown{
    double allowed_time;
    double remaining_time;
    double subtract_time;
    LCD_DISCO_F469NI *lcd;
    Mutex* LCD_mutex;
    Watchdog* wd;
    uint16_t XPos=0;
    uint16_t YPos=0;

    public:
        countdown(LCD_DISCO_F469NI *lcd,Mutex *lock,Watchdog* WD,double time,double to_subtract);
        void tick_down();
        void position_set(uint16_t Xpos,uint16_t Ypos);
    
};



#endif