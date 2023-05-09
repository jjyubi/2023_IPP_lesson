#include <stdio.h>

char* main()
{
	char str[10];
	char* ptr;

	printf("입력>> ");
	ptr = fgets(str, sizeof(str), stdin);
	printf("입력 받은 문자 : %s\n", str);
	printf("리턴값 : %p\n", ptr);
}
