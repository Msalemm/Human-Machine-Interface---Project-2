#include <avr/io.h>
#include <util/delay.h>
//Mohamed Mohamed 202101548
//Ahmed aimen EDeib 202000526
//marwan gadara 202000099

void init(){
  
  Adc_Init();
  LCD_Init();
  showtemp();
  



}

int main(){

 init();
  DDRB=0b11100111; // initializing the pins as input 
 float incs=40; // the max temp value is defined
  float decs=30; // the minimum temp value is defined
  float temp_val; // the value that will be inputed
 
  char *dataa[0]; // a set string name to hold the maximum value
  char *daata[0]; // a set string name to hold the lowest value
 
  while(1)
  {
  temp_val = showtemp(); // the temp value is now Show temp
  
  _delay_ms(300);
  
  if((temp_val/20)>incs|(temp_val/20)<decs){ // if function to turn on the LED light if the max/min values are exceeded
     
  PORTB=0b11111111; // the alarm light is turned on
  }
  else{
     
  PORTB=0b11111011; // else it wont turn on ( remains off)
  }
  
if(Adc_ReadChannel(0)>300){ // the button starts to work ( ADC IS READ)
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    
    LCD_Clear();
    incs++; // when the push button is pressed the value increments by 1
  }
    LCD_String_xy(0,0,"40 C changed to "); // 40 is shown ( the initial value)
    itoa(incs,*dataa,10); 
    LCD_String_xy(1,0,*dataa); // shows the incremented value after 1 is added
    LCD_String_xy(1,6,"C");
   
    
    _delay_ms(3000);
    LCD_Clear(); // clears the LCD screen
    


  
  }
  if(Adc_ReadChannel(2)>300){ // the button starts to work ADC reads a voltage value
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){
    
    LCD_Clear(); // LCD is cleared 
    decs--; // when the push button is pressed the value of the minimum is decremented by 1
  }
    LCD_String_xy(0,0,"30 C changed to "); // shows the initial value
    itoa(decs,*daata,10); // passes the said value to the string
    LCD_String_xy(1,0,*daata); // displays the value that was decremented by 1
    LCD_String_xy(1,6,"C");
   
    
    _delay_ms(3000);
    LCD_Clear(); // LCD is cleared
  }
    
}
}