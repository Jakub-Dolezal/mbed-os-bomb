
#include "LCD_game1.h"
#include <vector>

vector<Button> buttons;

void updatetor(){
    while(true){
        for(Button &bt: buttons){
            bt.update();
        }
    }
}

void fun1(LCD_Data_struct LCD_data){
    LCD_data.LCD->SetTextColor(LCD_COLOR_WHITE);
    LCD_data.LCD->DisplayStringAt(80, 80,(uint8_t*)"FUN1", CENTER_MODE);
}

void game(LCD_Data_struct LCD_data, countdown *ct){
    ct->position_set(0,0);

    Button bt1(LCD_data,20,20,5,5,LCD_COLOR_WHITE,LCD_COLOR_GRAY,&fun1);
    buttons.push_back(bt1);
    Thread updates;
    updates.start(&updatetor);
    while(1){}
}