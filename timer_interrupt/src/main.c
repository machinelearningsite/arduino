#include <avr/io.h>
#include <avr/interrupt.h>
#include "disp7_ueb2.h"

volatile int16_t number = 0;	// number which will be displayed
volatile int8_t flag = 0;

void main(void){
  setup();
  cli();
  DDRB |= (1<<DDB7);
  EICRB |= ((1<<ISC40) | (1<<ISC41));
  EIMSK |= (1<<INT4);

  EICRB |= (1<<ISC50) | (1<<ISC51);
  EIMSK |= (1<<INT5);
  
  //TCCR1B |= (1 << WGM12);
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 15624/4;
  
  sei();
  
  while(1){
    disp_int();
  }
}

ISR(INT4_vect){
  flag = 1;
  TCCR1B |= (1<<CS12) | (1<<CS10); // prescaler 1024
  TIMSK1 |= (1<<OCIE1A);
}

ISR(INT5_vect){
  flag = 0;
  TCCR1B |= (1<<CS12) | (1<<CS10); // prescaler 1024
  TIMSK1 |= (1<<OCIE1A);
}


ISR(TIMER1_COMPA_vect){
  if (flag == 1){
    number += 1;
  }
  else if (flag == 0){
    number -= 1;
  }
  TCCR1B = 0;
  TCNT1 = 0;
}