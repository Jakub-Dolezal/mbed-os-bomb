
#include "LCD_explosion.h"
#include "LCD_DISCO_F469NI.h"
#include "stm32469i_discovery_lcd.h"




void explode(LCD_DISCO_F469NI *lcd,Mutex *lock){
    while(1){
        lock->lock();
        lcd->Clear(LCD_COLOR_YELLOW);
        lock->unlock();
        ThisThread::sleep_for(250ms);
        lock->lock();
        lcd->Clear(LCD_COLOR_RED);
        lock->unlock();
    }
}