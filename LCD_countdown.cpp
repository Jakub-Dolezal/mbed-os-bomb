#include "LCD_countdown.h"
#include "stm32469i_discovery_lcd.h"
#include <cstdio>

countdown::countdown(LCD_DISCO_F469NI *lcd,Mutex *lock,Watchdog* WD,double time,double to_subtract):
    lcd(lcd),
    LCD_mutex(lock),
    wd(WD),
    allowed_time(time),
    remaining_time(time),
    subtract_time(to_subtract)
{};

void countdown::tick_down(){
    Watchdog::get_instance().kick();
    this->LCD_mutex->lock();
    char a[25];
    sprintf(a,"%.1f",this->remaining_time);
    this->lcd->DisplayStringAt(this->XPos, this->YPos,(uint8_t*)&a, CENTER_MODE);
    this->LCD_mutex->unlock();
}

void countdown::position_set(uint16_t Xpos, uint16_t Ypos){
    this->XPos=Xpos;
    this->YPos=Ypos;
}