#include "GettingTroubleCodes_Types.h"
#include <DisplayHandler.h>
dtGettingTroubleCodes Variables;

void GettingTroubleCodes_Task(void)
{
    switch(Variables.SM)
    {
        case Init:
        {
            uint8   temp[] = "Trouble Codes:";
            uint8   temp2[] = "QQuery...";
            uint8 looper;
            for(looper = 0; looper<sizeof(temp);looper++) Variables.Lcd.RawOne[looper] = temp[looper];
            for(looper = 0; looper<sizeof(temp2);looper++) Variables.Lcd.RawTwo[looper] = temp2[looper];
            LcdClear();
            PutStr(&Variables.Lcd.RawOne[0],0);
            PutStr(&Variables.Lcd.RawTwo[1],1);
            Variables.SM = Querry;
        }   
            
            
            break;
            
        case Querry:
            break;
    }
}
