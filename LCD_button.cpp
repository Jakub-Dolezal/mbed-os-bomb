#include "LCD_button.h"

bool Button::is_pressed(){
    bool ret = false;
    this->LCD_data.TS_lock->lock();
    TS_StateTypeDef TS_State;
    this->LCD_data.TS->GetState(&TS_State);
    if(TS_State.touchDetected){
        for(int idx=0; idx< TS_State.touchDetected;idx++){
            uint16_t x = TS_State.touchX[idx];
            uint16_t y = TS_State.touchY[idx];
            if(((this->XPos+this->SizeX > x)and(this->XPos-this->SizeX < x))and((this->YPos+this->SizeY > y)and(this->YPos+this->SizeY < y))){
                ret = true;
                break;
            }
        }
    }
    this->LCD_data.TS_lock->unlock();
    return ret;
}

void Button::update(){
    if(this->is_pressed()){
        this->LCD_data.LCD_lock->lock();
        this->LCD_data.LCD->SetTextColor(this->activated_color);
        this->LCD_data.LCD->FillRect(this->XPos,this->YPos,this->SizeX,this->SizeY);
        (*(this->func))(this->LCD_data);
        this->LCD_data.LCD_lock->unlock();
    }else{
        this->LCD_data.LCD_lock->lock();
        this->LCD_data.LCD->SetTextColor(this->default_color);
        this->LCD_data.LCD->FillRect(this->XPos,this->YPos,this->SizeX,this->SizeY);
        this->LCD_data.LCD_lock->unlock();
    }
}
