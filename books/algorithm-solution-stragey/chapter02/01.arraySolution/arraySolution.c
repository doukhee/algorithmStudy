#include <stdio.h>



void main(int argc, char **argv){
    int i = 0;
    char buf[11];

    printf("소문자 11개를 입력해봅시다.\r\n");
    printf("입력 : ");

    while(i < 11){
        scanf("%c", &buf[i]);
        i++;
    }

    printf("문자를 입력하셨군요. 대문자로 변환 합니다.\r\n");
    for(i = 0; i < 11; i++){
        printf("%c", buf[i] - ('a' - 'A'));
    }
    printf("\r\n");
}