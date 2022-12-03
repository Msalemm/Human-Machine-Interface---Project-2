#include <avr/io.h>

#define SetBit(Reg,Pin) (Reg |= (1<<Pin))//A Function that access register and sets a pin 
#define ClearBit(Reg,Pin) (Reg &=~ (1<<Pin))//A Function that clears the pin in a register
#define ToggleBit(Reg,Pin) (Reg ^= (1<<Pin))//Changes pin in the register from 0 to 1 and vice versa
#define GetBit(Reg,Pin) (Reg&(1<<Pin))//function obtaining a value on the pin of the register

void Dio_SetPinDirection(unsigned char DDRX, unsigned char Pin,unsigned char Direction){//takes DDR value, A pin in the DDReither output or input
  switch (DDRX)//switches the cas function
  {
    
       case 'B'://register B in the DDR (ddrb)
    if (Direction == 1)
    {
      SetBit(DDRB,Pin);//sets the DDRB and a Pin number
     
    }
    else{
      ClearBit(DDRB,Pin); //clears a Pin and DDRB        
      
    }
    break;
        case 'C':
    if (Direction == 1)
    {
      SetBit(DDRC,Pin); //sets a DDRC and a Pin number
      
    }
    else{
      ClearBit(DDRC,Pin); //clears a Pin and DDRC      
      
    }
    break;
        case 'D'://the DDRD
    if (Direction == 1)
    {
      SetBit(DDRD,Pin); //sets tjhe DDRD and Pin 
      
    }
    else{
      ClearBit(DDRD,Pin);  //  clears the pin  
      
    }
    break; //when the condition is reached the condition is broken
}
}
unsigned char Dio_GetPinState(unsigned char Port,unsigned char pin){// reads the port and pin value
  int BitValue;
  switch(Port){//switches the case
    
    case 'B':
    BitValue = GetBit(PORTB,pin);//reads if PORT B is output or input
    
    break;
    case 'C':
    BitValue = GetBit(PORTC,pin);//reads if PORT C is output or input
    break;
    case 'D':
    BitValue = GetBit(PORTD,pin);//reads if PORT D is output or input
    break;
  }
  return BitValue;
}
void Dio_SetPortDirection(unsigned char PORTX, unsigned char Pin,unsigned char Direction){//the function takes the value for the Port, pin in the Port, the output or input
  switch (PORTX)
  {
    
       case 'B':
    if (Direction == 1)//sets the port as an output
    {
      SetBit(PORTB,Pin); //Sets Port B and the pin number as output      
     
    }
    else{
      ClearBit(PORTB,Pin);//Clears Port B and Pin number         
      
    }
    break;
        case 'C':
    if (Direction == 1)
    {
      SetBit(PORTC,Pin);//sets the port as an output
      
    }
    else{
      ClearBit(PORTC,Pin); //Clears Port C and Pin number        
      
    }
    break;
        case 'D':
    if (Direction == 1)
    {
      SetBit(PORTD,Pin);//sets the port as an output      
      
    }
    else{
      ClearBit(PORTD,Pin);//Clear Port D and Pin number        
      
    }
    break;
}
}

