#include "DisplayHandler_Types.h"

dtDisplayHandler DisplayHandler;

void LCDEnter()
{
    output_high(LCD_EN);
    //delay_ms(10);
    
}

void LCDSendByte(uint8 data, uint8 CoM)
{
    DisplayHandler.OutputBuffer[DisplayHandler.OutputNum].data=data;
    DisplayHandler.OutputBuffer[DisplayHandler.OutputNum].DataOrCmd = CoM;
    DisplayHandler.OutputNum++;
    if(DisplayHandler.OutputNum >= LCD_BUFFER_SIZE) DisplayHandler.OutputNum=0; 
}

void MyPutc(uint8 *data, uint8 line)
{
    uint8 looper;
    if(line != 0) LCDSendByte(0xA9,1);
    else LCDSendByte(0x80,1);
    for(looper = 0; (data[looper] != 0)&& (looper < 16); looper++) LCDSendByte(data[looper],0);
}

void LcdClear(void)
{
    LCDSendByte(0x01,1);
}



void LCDInit(void)
{
    output_low(LCD_RS);
    output_low(LCD_RW);
    output_low(LCD_EN);
    /*output_low(LCD_D4);
    output_low(LCD_D5);
    output_low(LCD_D6);
    output_low(LCD_D7);
    LCDEnter();
    output_high(LCD_D5);
    LCDEnter();*/
    DisplayHandler.OutputCntr=0;
    DisplayHandler.OutputNum=0;
    LCDSendByte(0x02,1);
    
    LCDSendByte(0x01,1);
    LCDSendByte(0x03,1);
}
extern uint32 Ticks;
void DisplayHandler_Task(void)
{
    switch(DisplayHandler.SM)
    {
        case LcdEnter_Wait:
            if(IsPassed(DisplayHandler.Timer,8) != 0)
            {
                output_low(LCD_EN);
                DisplayHandler.SM = DisplayHandler.NextSm;
            }
            break;
            
        case LcdSetPinsHighNibble:
            if(DisplayHandler.OutputCntr != DisplayHandler.OutputNum)
            {
                if(DisplayHandler.OutputBuffer[DisplayHandler.OutputCntr].DataOrCmd != 0) output_low(LCD_RS);
                else output_high(LCD_RS);

                if((DisplayHandler.OutputBuffer[DisplayHandler.OutputCntr].data&0x80)!=0) output_high(LCD_D7);
                else output_low(LCD_D7);
                if((DisplayHandler.OutputBuffer[DisplayHandler.OutputCntr].data&0x40)!=0) output_high(LCD_D6);
                else output_low(LCD_D6);
                if((DisplayHandler.OutputBuffer[DisplayHandler.OutputCntr].data&0x20)!=0) output_high(LCD_D5);
                else output_low(LCD_D5);
                if((DisplayHandler.OutputBuffer[DisplayHandler.OutputCntr].data&0x10)!=0) output_high(LCD_D4);
                else output_low(LCD_D4);
                
                DisplayHandler.NextSm = LcdSetPinsLowNibble;
                output_high(LCD_EN);
                DisplayHandler.SM = LcdEnter_Wait;
                DisplayHandler.Timer = Ticks;
            }
            break;
            
        case LcdSetPinsLowNibble:
            if((DisplayHandler.OutputBuffer[DisplayHandler.OutputCntr].data&0x8)!=0) output_high(LCD_D7);
            else output_low(LCD_D7);
            if((DisplayHandler.OutputBuffer[DisplayHandler.OutputCntr].data&0x4)!=0) output_high(LCD_D6);
            else output_low(LCD_D6);
            if((DisplayHandler.OutputBuffer[DisplayHandler.OutputCntr].data&0x2)!=0) output_high(LCD_D5);
            else output_low(LCD_D5);
            if((DisplayHandler.OutputBuffer[DisplayHandler.OutputCntr].data&0x1)!=0) output_high(LCD_D4);
            else output_low(LCD_D4);
            
            DisplayHandler.OutputCntr++;
            if(DisplayHandler.OutputCntr >= LCD_BUFFER_SIZE) DisplayHandler.OutputCntr=0;
            DisplayHandler.NextSm = LcdSetPinsHighNibble;
            output_high(LCD_EN);
            DisplayHandler.SM = LcdEnter_Wait;
            DisplayHandler.Timer = Ticks;
            
            break;
    }
}