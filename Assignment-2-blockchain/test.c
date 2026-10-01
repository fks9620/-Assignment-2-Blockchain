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