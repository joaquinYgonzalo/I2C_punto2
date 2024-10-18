#include "MKL25Z4.h"
#include "LCD.h"
int lcd[2][16];
int main(void){
    SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;
    SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
    PORTC->PCR[10] = PORT_PCR_MUX(2);
    PORTC->PCR[11] = PORT_PCR_MUX(2);
    for( i=0;i<8;i++){
        PORTD->PCR[D[i]] |=(1<<8); 
        PTD->PDDR|=(1<<D[i]);
    }
    while(1){
        while(LCD_sendByte(byte)!=8);
        for(j=0;j<16;j++){
            if(lcd[2][j]!= 0){
                if(j!=0){
                    LCD_scrollDisplayLeft();
                }else if(j!=15){
                    LCD_scrollDisplayRight();
                }
            }
               
        }
        LCD_sendCmd(command);
        for(int i=7000000;i>0;i--);
        LCD_print();
        for(int i=7000000;i>0;i--);
        LCD_clear();
    }
    return 0;
}