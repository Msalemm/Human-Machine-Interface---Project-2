#include <avr/io.h>
#include <util/delay.h>

float showtemp(){ // returns a float value for temperature
  Adc_Init(); // initializing the ADC 

  float temp_val; // defining the temp value
  char *data[0]; // defining the string that will be used to display the value on LCD
  
  DDRC=0b00000000;
  PORTC=0b00000000;
  temp_val=Adc_ReadChannel(4); 
  itoa(temp_val/20,*data,10); // divides the temperature value by 20
  _delay_ms(300);
  LCD_String_xy(0,0,"current temp is "); //prints current temp is on the first row of the LCD
  LCD_String_xy(1,0,*data); //prints the value on the second row of the LCD
  LCD_String_xy(1,6,"C"); //prints C (degrees celcius)  on the second row of the LCD
  _delay_ms(300);
  return temp_val; // returns the temperature value
}