#include <stdio.h>
#include <string.h>
#include "user.h"


void testAShift();
void testBShift();
void testLetters();

int main(void) {

	testAShift();
	testBShift();
	testLetters();

	struct user * head=NULL;
	head = add(head, "test");
	head = add(head, "huh");
	/*head = add(head, "gahyun");
	head = add(head, "matt");
	head = add(head, "sumita");
	head = add(head, "james");*/
	verify(head);
}