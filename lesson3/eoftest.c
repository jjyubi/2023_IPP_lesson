#include <stdio.h>
#define BUFSIZE 100

int main(void)
{
	char buf[BUFSIZE];
	
	while (fgets(buf, BUFSIZE, stdin) != NULL) {
		printf("You entered: %s", buf);
	}
	if (feof(stdin)) {
		printf("End of file reached. \n");
        printf("enterd: %s\n", buf);
	}
	else if (ferror(stdin)) {
		printf("An error occurred while reading from the input stream. \n");
	}

	return 0;
}
