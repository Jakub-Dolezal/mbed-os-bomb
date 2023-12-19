#include "mbed.h"
#include "ResetReason.h"

#include "TS_DISCO_F469NI.h"
#include "LCD_DISCO_F469NI.h"

#include "LCD_countdown.h"
#include "LCD_explosion.h"
#include "LCD_game1.h"
#include "stm32469i_discovery_lcd.h"
#include "LCD_struct.h"

LCD_DISCO_F469NI lcd;
TS_DISCO_F469NI ts;
Mutex LCD_mutex;
Mutex TS_mutex;
Watchdog &wd = Watchdog::get_instance();
countdown ct(&lcd,&LCD_mutex,&wd,COUNTDOWN_FROM,COUNTDOWN_SUBTRACT);
Ticker time_ticker;

LCD_Data_struct lcd_data;


void count_down_wrapper(){
    ct.tick_down();
}

void init(){
    lcd_data.LCD = &lcd;
    lcd_data.LCD_lock = &LCD_mutex;
    lcd_data.TS = &ts;
    lcd_data.TS_lock = &TS_mutex;

    wd.start((std::chrono::duration_cast<std::chrono::milliseconds>(COUNTDOWN_TIME)).count());
    time_ticker.attach(&count_down_wrapper,COUNTDOWN_SPEED);
    bool status = ts.Init(lcd.GetXSize(), lcd.GetYSize());
    if(status != TS_OK){
        lcd.Clear(LCD_COLOR_DARKRED);
        lcd.DisplayStringAt(0, 0, (uint8_t *)"FAILED TO INITIALISE", LEFT_MODE);
    }
}

void exit(){

}

// main() runs in its own thread in the OS
int main()
{
    init();
    bool RUN = true;
    if(ResetReason::get()==RESET_REASON_WATCHDOG){explode(&lcd,&LCD_mutex);}
    while (RUN) {
        game(lcd_data,&ct);
    }
    exit();
}