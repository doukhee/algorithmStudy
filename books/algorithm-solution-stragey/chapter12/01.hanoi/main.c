/**
 * 조건
 * 1. 한번에 하나의 원판만 옮길 수 있다.
 * 2. 큰 원판이 작은 원판 위에 있어서는 안된다.
 * 
 * 실제 원판이 n개라면 메르센 수라고 하는 2^n - 1번의 이동으로 원판을 모두 옮길 수 있다.
 * 
 */
#include <stdio.h>

int Cnt;

void hanoi(int n, int a, int b){
    int temp;

    if(n == 1){
        printf("원판 %d을(를) %d에서 %d로 이동한다.\r\n", n, a, b);
    }else{
        temp = 6 - a - b;
        hanoi(n - 1, a, temp);
        printf("원판 %d을(를) %d에서 %d로 이동한다.\r\n", n, a, b);
        hanoi(n - 1, temp, b);
    }
    Cnt++;
}

int main(){
    int n;
    printf("이동할 원판 수를 입력하세요 : ");
    scanf("%d", &n);

    hanoi(n, 1 ,2);
    printf("원판의 총 이동 횟수 : %d회\r\n", Cnt);
    return 0;
}