/* '!' // 논리 부정 연산자 이용
   valid(유효한)_line // fgets로 입력받은 값의 유효성을 비교하여 조건문 작성
   Ctrl+D입력의 조건문을 위로 변경 // continue 문 사용
   숫자가 아닌 문자의 예외처리를 위해 배열검사를 단축 // !isdigit(line[i]) 사용
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

int main()
{
    char line[SIZE];
    int i, j;
    int num;
    int valid_line = 0; // line입력 유효성. 0=유효하지 않은 입력. 1=유효한 입력.

    // valid_line 값이 0인 경우 while 계속 실행
    // valid_line 값이 1인 경우 while 종료
    while (!valid_line) {
        printf("How many lines? (1..100) >> ");
        if(fgets(line, sizeof(line), stdin) == NULL) {
            printf("Ctrl+D가 입력되었습니다. 다시 입력해주세요.\n");
            continue;
        }
        line[strcspn(line, "\n")] = '\0';
        // 개행문자의 위치를 찾아서 제거

        int valid_num = 1;
        for (i = 0; i <strlen(line); i++) {
            if(!isdigit(line[i])) { // 입력이 숫자가 아닌 경우. 정수를 판별하는 isdigit 이욯
                valid_num = 0;
                printf("숫자를 입력하시오.\n");
                printf("Invalid input - Range 1..100\n");
                break;
            }
            if(isdigit(line[i])) {  // 입력이 숫자인 경우
                if(!isdigit(line[i+1])) {   // 숫자 다음의 입력이 숫자가 아닌 경우.
                    valid_num = 0;
                    printf("숫자를 입력하시오.\n");
                    printf("Invalid input - Range 1..100\n");
                    break;
                }
            }
        }
        

        // 1~100 사이의 값인지 검사
        if(valid_num) {
            num = atoi(line);   // 정수로변환
            // 1보다 작고 100보다 큰 경우 (범위를 벗어나게 된 경우)
            if (num <1 || num > 100) {
                printf("1~100 사이의 값을 입력하시오.\n");
            } else {
                // while 문의 입력값이 유효한 경우 루프를 끝내도록 만들어준다.
                valid_line = 1;
            }
        }
    }

    // * 라인을 출력하는 코드 작성
    for (i = 0; i < num; i++) {    // 정수로 변환한 num변수 사용
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
