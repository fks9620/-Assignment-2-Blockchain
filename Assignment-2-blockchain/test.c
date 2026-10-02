#include <stdio.h>

void testAShift() {
	unsigned char A = 56;
	unsigned char shiftedA = A >> 2;

	printf("Test A Shift: %d\n", shiftedA);
}

void testBShift() {
	unsigned char B = 99;
	unsigned char shiftedB = B >> 1;

	printf("Test B Shift: %d\n", B);
}

void testLetters(){
	unsigned char A = 56;
	unsigned char B = 99;
	unsigned char C = 102;
	unsigned char D = 67;
	unsigned char E = 76;
	
	unsigned char g = (B & C) | (C & D);

	unsigned char shiftedA = A >> 2;
	unsigned char shiftedB = B >> 1;

	A = E; //good
	B = A; //good
	C = shiftedA + E; //good
	D = shiftedA ^ shiftedB; //good
	E = g + shiftedB + "test"; //good

	printf("Test Letters: A=%d, B=%d, C=%d, D=%d, E=%d\n", A, B, C, D, E);
}