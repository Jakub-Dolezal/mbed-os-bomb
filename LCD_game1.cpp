
#include "LCD_game1.h"
#include <vector>

vector<Button> buttons;

void fun1(LCD_Data_struct LCD_data){
    LCD_data.LCD->SetTextColor(LCD_COLOR_WHITE);
    LCD_data.LCD->DisplayStringAt(80, 80,(uint8_t*)"FUN1", CENTER_MODE);
}

void game(LCD_Data_struct LCD_data, countdown *ct){
    ct->position_set(0,0);
    //uint16_t Xpos,uint16_t Ypos,uint16_t _SizeX,uint16_t _SizeY,uint32_t _default_color,uint32_t _activated_color,void (*_func)()):

    Button bt1(LCD_data,20,20,5,5,LCD_COLOR_WHITE,LCD_COLOR_GRAY,&fun1);
    while(1){}
}