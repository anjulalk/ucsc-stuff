#include <stdio.h>

int main(void) {
	int *pc;
	int c;
	printf("Address of pointer pc: %u\n", pc);
	printf("Address of c: %u\n", &c);
	printf("Value of c: %i\n\n", c);
	
	c = 22;
	printf("c = 22\n");
	printf("Address of c: %u\n", &c);
	printf("Value of c: %i\n\n", c);
	
	pc = &c;
	printf("pc = &c\n");
	printf("Address of pointer pc: %u\n", pc);
	printf("Value of c: %i\n\n", *pc);
	
	c = 11;
	printf("c = 11\n");
	printf("Address of pointer pc: %u\n", pc);
	printf("Content of pointer pc: %i\n\n", *pc);
	   
	*pc = 2;
	printf("*pc = 2\n");
	printf("Address of c:%u\n",&c);
   	printf("Value of c:%i\n\n",c);
   
   	return 0;
}
