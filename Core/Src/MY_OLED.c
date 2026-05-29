//
// Created by wnywl on 2026/5/18.
//

#include "../Inc/MY_OLED.h"

#include "main.h"
#include "OLED.h"
#include "OLED_Data.h"
#include "stm32f1xx_hal.h"


void interface_1(void) {
        OLED_Clear();
        OLED_ShowChar(0,0,'S',OLED_6X8);
        OLED_ShowString(12,0,"hello",OLED_6X8);
        OLED_ShowNum(0,8,999,3,OLED_6X8);
        OLED_ShowHexNum(24,8,0xA5A5,4,OLED_6X8);
        OLED_ShowBinNum(54,8,0xA1,8,OLED_6X8);
        OLED_ShowSignedNum(0,16,-99,2,OLED_6X8);
        OLED_ShowSignedNum(24,16,97,2,OLED_6X8);
        OLED_ShowFloatNum(48,16,55.33,2,2,OLED_6X8);
        OLED_Printf(90,16,OLED_6X8,"wn3&?");
        OLED_Printf(0,24,OLED_8X16,"你好世界X#1");
        OLED_Printf(0,40,OLED_8X16,"电流电压");

        OLED_Update();
    }


    void interface_2(void) {
        OLED_Clear();
        OLED_ShowImage(0,0,64,32,PK);
        OLED_ShowImage(0,32,15,15,Diode);

        OLED_Update();
    }


void interface_3(void) {
        OLED_Clear();
        OLED_ShowImage(0,0,128,64,girl);
        OLED_Reverse();

        OLED_Update();
    }


void interface_4(void) {
        OLED_Clear();
        OLED_DrawRectangle(16,8,96,48,OLED_UNFILLED);
        for (int x=17;x<=111;x++) {
            OLED_DrawLine(x,9,x,55);
            OLED_Update();
                HAL_Delay(5);

        }



    }
void interface_5_head(void) {
    OLED_Clear();
    OLED_ShowString(0,0,"EC_count:",OLED_8X16);
    OLED_ShowString(0,16,"ADC_value:",OLED_6X8);
    OLED_ShowString(0,32,"Voltage:",OLED_6X8);
    OLED_ShowString(0,48,"average:",OLED_6X8);


    OLED_Update();
}
void interface_5_main(void) {
    OLED_ShowSignedNum(72,0,EC_count,5,OLED_8X16);

    OLED_ShowNum(60,16,ADC_value[0],4,OLED_6X8);
    OLED_ShowNum(90,16,ADC_value[1],4,OLED_6X8);
    OLED_ShowNum(60,24,ADC_value[2],4,OLED_6X8);

    OLED_ShowFloatNum(48,32,voltage[0],1,2,OLED_6X8);
    OLED_ShowFloatNum(84,32,voltage[1],1,2,OLED_6X8);
    OLED_ShowFloatNum(48,40,voltage[2],1,2,OLED_6X8);

    OLED_ShowFloatNum(48,48,average,2,2,OLED_6X8);

    OLED_Update();
}




