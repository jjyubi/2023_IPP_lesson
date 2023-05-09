#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // isdigit

int main()
{
    int i, j;     // [i = \n][j = *]을 찍기 위한 반복 계산 변수
    int len, num;
    char line_s[50 + 2];
    char* ptr;

    while (1) {
        printf("How many lines? (1..100) >> ");
        ptr = fgets(line_s, sizeof(line_s), stdin);

        //printf("리턴값 : %p\n", ptr);
        //printf("입력한 문자 : %s", line_s);
        //printf("입력한 문자의 길이 : %d\n", (strlen(line_s) - 1));

        line_s[strlen(line_s) - 1] = '\0';

        // fgets 에서는 \n를 함께 저장하기 때문에 입력받은 문자의 길이는 -1이고
        // 배열은 0 에서부터 시작하므로 '\n'이전에 입력받은 마지막 문자의 배열 번호는 문자의 길이에서 -1을 더 해주어야함
        // 마지막 배열의 번호를 알기위해 문자길이에서 -2를 한 변수 : len
        len = (strlen(line_s) - 2);

        for (num = 0; num <= len; num++) {
            if (line_s[num] < 48 || line_s[num]>57) {
                // 입력받은 문자가 정수가 아닐 경우
                //printf("    배열 번호 [ %d ]", num);
                //printf("    입력한 [% c] 는 정수가 아닙니다.\n", line_s[num]);
                //printf("    isdigit : % d\n\n", isdigit(line_s[num]));
                
                // 정수가 아닌 문자가 들어있다면 배열 검사를 종료
                break;
            }
        }

        // 정수를 판단하는 함수 isdigit 사용.
        //  -> 값이 정수일 경우 0이 아닌 수를 반환함
        //  -> 값이 정수가 아닌 경우 0을 반환함
        //printf("마지막 배열 번호 [ %d ] => isdigit : %d\n", num, isdigit(line_s[num]));
        //printf("마지막에 들어있는 문자 : %c \n", line_s[num]);
        //printf("리턴값 : %p \n", ptr);

        if (ptr == NULL) {
            //printf("현재 마지막 배열 번호 : %d\n", num);
            //printf("%d번에 들어있는 문자 : %c\n", num-1, line_s[num-1]);
            //printf("%d번에 들어있는 문자 : %c\n", num, line_s[num]);
            //printf("%d번에 들어있는 문자 : %c\n", num+1, line_s[num+1]);
            rewind(stdin);
            printf("\nInvalid input - Range 1..100\n");
        }
        else if ((isdigit(line_s[num])) == 0) {
            printf("Invalid input - Range 1..100\n");
        }
        else if ((isdigit(line_s[num])) != 0) {
            int line = (strtol(line_s, NULL, 10));
            //printf("10진수로 변환한 line 값 : %d\n\n", line);
            //printf("리턴값 : %p\n\n", ptr);

            rewind(stdin);

            if (line >= 1 && line <= 100) {
                printf("입력한 라인 수 만큼 출력합니다.\n\n");
                for (i = 0; i < line; i++) {
                    for (j = 0; j <= i; j++) {
                        printf("*");
                    }
                    printf("\n");
                }
                printf("\n종료합니다.\n");
                break;
            }

            else {
                printf("Invalid input - Range 1..100\n");
            }
        }
    }
}
