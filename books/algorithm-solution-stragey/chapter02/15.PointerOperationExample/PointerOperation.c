#include <stdio.h>


int main(void){
    char buf[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char *ptr = buf;
    int i = 0;
    printf("ptr step one by one\r\n");

    for(i = 0; i < 6; i++){
        printf("ptr : 0x%p, *ptr : %c \r\n", ptr, *ptr);
        ptr++;
    }

    printf("\r\n retry ptr point buf\r\n");
    ptr = buf;

    printf("*ptr++ result \r\n");
    printf("ptr : 0x%p, *ptr : %c\r\n", ptr, *ptr++);

    printf("*(ptr++) result \r\n");
    printf("ptr : 0x%p, *ptr : %c\r\n", ptr, *(ptr++));

    printf("--ptr then *(ptr++) result \r\n");
    --ptr;
    printf("ptr : 0x%p, *ptr : %c \r\n", ptr, *(ptr++));

    printf("(*ptr)++ result \r\n");
    (*ptr)++;
    printf("ptr : 0x%p, *ptr : %c\r\n", ptr, *ptr);

    printf("ptr += 1 then result *ptr result \r\n");
    ptr += 1;
    printf("ptr : 0x%p, *ptr : %c \r\n", ptr, *ptr);
    printf("ptr -= 2 then result \r\n");
    ptr -= 2;
    printf("ptr : 0x%p, *ptr : %c \r\n", ptr, *ptr);
    return 0;
}