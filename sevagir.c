i#include <stdio.h>
void foo (short* s) {
	char* ptr = (char*)s;
	char tmp = *ptr;
	*ptr = *(ptr + 1);
	*(ptr + 1) = tmp;


}


int main(void) {
    	//int target = 0;
	//char c1 = 0x12;
	//char c2 = 0x34;
	short s = 0x5678;
	foo( &s);
	printf("%08x",s);

 	
return 0;
}

