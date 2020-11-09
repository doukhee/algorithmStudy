/**
 * 
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    
    int num, data, index;
    srand(time(NULL));
    num = rand() % 10;
    index = 1;
    printf("0부터 9까지 숫자를 입력하세요\r\n");
    while(1){
        scanf("%d", &data);
        printf("[%2d번째 도전] : %d\r\n", index, data);
        if(data < num){
            printf("%d보다 큽니다.", data);
        }else if(data > num){
            printf("%d보다 작습니다.", data);
        }else{
            printf("우와! 정확하다. %2d번째 만에 맞췄군요\r\n", index);
            break;
        }
        index++;
    }

    return 0;
}