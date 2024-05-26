/*
 * disp7.h
 *
 * Created: 24.04.2022 17:25:01
 *  Author: Ralf Petry
 */ 


#ifndef DISP7_H_
#define DISP7_H_

	#define DIGITS 4
	#define DIGITS_NEG DIGITS-1
	
	// GLOBAL VARIABLES
	// ========================================================================
	extern volatile int8_t SevSeg_element;	// counter for elements
	extern volatile uint8_t SevSeg_update;	// update variable: if 1 --> main loop will be executed
	extern volatile int16_t number;			// number which will be displayed
	// ========================================================================

	void setup(void);
	void disp_int(void);
	void calc_digits(uint8_t [DIGITS], uint16_t);
	void int2digits(uint8_t [DIGITS], int16_t);
	void disp_float(float);
	void float2digits(uint8_t [DIGITS], float);
	uint8_t digit_to_port(uint8_t);

#endif /* DISP7_H_ */