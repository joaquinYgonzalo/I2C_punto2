#include "MKL25Z4.h"
#include "LCD.h"
#define LCD_I2C_ADDRESS 0x27


int D[8]={0,1,2,3,4,5,6,7};

void LCD_init(){
SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK
SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;
SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
     PORTC->PCR[10] = PORT_PCR_MUX(2);
    PORTC->PCR[11] = PORT_PCR_MUX(2);
    for(int i=0;i<8;i++){
        PORTD->PCR[D[i]] |=(1<<8); 
        PTD->PDDR|=(1<<D[i]);
    }
    I2C1->C1 =0;
    I2C1->C1 = I2C_C1_IICEN_MASK;
    I2C1->F = 0x14;
}
void LCD_sendCmd(uint8_t command){
    uint8_t parteMS = comand & 0xF0;
    uint8_t parteLS =(command << 4) & 0xF0;
    I2C0->D =(LCD_I2C_ADDRESS << 1);
    while(!(I2C0->S & I2C_S_IICIF_MASK));
    I2C0->S |= I2C_S_IICIF_MASK;
    I2C0->D = data;
    while(!(I2C0->S & I2C_S_IICIF_MASK));
    I2C0->S |= I2C_S_IICIF_MASK;
}
void LCD_clear(){
 
}
void LCD_scrollDisplayLeft(){

}
void LCD_scrollDisplayRight(){

}
void LCD_print(){
    LCD_I2C_WriteByte(parteMS|0x08);
    LCD_I2C_WriteByte(parteLS|0x08);
    I2C1->C1 |= IC_C1_TX_MASK;
    I2C1->C1 |= IC_C1_MST_MASK;

}
void LCD_setCursor(int row, int col){
uint8_t addr;
if(row==0){
    addr=0X00 + col;
}else{
    addr=0X80 + col;
}

}
void LCD_createChar(uint8_t nByte, uint8_t[] nuevoCaracter){

}