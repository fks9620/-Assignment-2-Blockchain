#include <stdio.h>

void testAShift() {
	unsigned char A = 56;
	A = A ^ (A >> 2); // Non-destructive bitshift replacement

	printf("Test A Shift: %d\n", A);
}

void testBShift() {
	unsigned char B = 99;
	B = B ^ (B >> 1); // Non-destructive bitshift replacement

	printf("Test B Shift: %d\n", B);
}

void testLetters(){
	unsigned char A = 56;
	unsigned char B = 99;
	unsigned char C = 102;
	unsigned char D = 67;
	unsigned char E = 76;
	
	unsigned char g = (B & C) | (C & D);

	unsigned char old_A = A;

	A = A ^ (A >> 2); 
	B = B ^ (B >> 1); 

	E = (g + 'test' + B);
	D = A ^ B;
	C = (A + E);
	A = E;
	B = old_A;

	printf("Test Letters: A=%d, B=%d, C=%d, D=%d, E=%d\n", A, B, C, D, E);
}