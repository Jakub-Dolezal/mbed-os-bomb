#ifndef __LCD_BUTTON
#define __LCD_BUTTON

#ifndef __LCD_STRUCT
#include "LCD_struct.h"
#endif

class GUI_element{
protected:
    LCD_Data_struct LCD_data;
    uint16_t XPos;
    uint16_t YPos;
    GUI_element(LCD_Data_struct _LCD_data,uint16_t Xpos ,uint16_t Ypos):
        LCD_data(_LCD_data),
        XPos(Xpos),
        YPos(Ypos){};
public:
    virtual void update() = 0;
};


class Button: public GUI_element{
    uint32_t default_color;
    uint32_t activated_color;
    uint16_t SizeX;
    uint16_t SizeY;
    void (*func)(LCD_Data_struct);
public:
    Button(LCD_Data_struct _LCD_data,uint16_t Xpos,uint16_t Ypos,uint16_t _SizeX,uint16_t _SizeY,uint32_t _default_color,uint32_t _activated_color,void (*_func)(LCD_Data_struct)):
        GUI_element(_LCD_data,Xpos,Ypos),
        SizeX(_SizeX),
        SizeY(_SizeY),
        default_color(_default_color),
        activated_color(_activated_color),
        func(_func){};
    void update();
    bool is_pressed();
};


#endif