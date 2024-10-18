#ifndef "LCD_h"
#define "LCD_h"
void LCD_sendCmd(uint8_t command); 
void LCD_sendByte(uint8_t byte); //como el write de antes
void LCD_init(); // combinen inicialización de i2c de antes con la del lcd
void LCD_clear();
void LCD_scrollDisplayLeft();
void LCD_scrollDisplayRight();
void LCD_print(char* str);// imprimir una cadena de caracteres (tengan en cuenta el enviar datos al LCD)
void LCD_setCursor(int row, int col);
void LCD_createChar(uint8_t nByte, uint8_t[] nuevoCaracter)


#endif
