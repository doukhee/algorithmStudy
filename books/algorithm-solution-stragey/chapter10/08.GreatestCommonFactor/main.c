/**
 * 최대 공약수를 구하는 프로그램
 * 2개의 수를 입력하세요
 * 입력 => 4 6
 * 1회 실행한다.
 * x = 4, y = 6
 * 2회 실행한다
 * x = 6, y = 4
 * 3회 실행한다.
 * x = 4, y = 2
 * 4회 실행한다.
 * 4와 6의 최대 공약수는 : 2
 * 재귀 호출을 사용해 함수를 구성할 때는 다음 세 가지 항목이 가장 중요하다.
 * 1. 재귀함수로 사용할 매개변수
 * 2. 재귀함수의 반환 값
 * 3. 재귀 함수가 종료될 조건
 * 
 */
#include <stdio.h>

int gcd(int, int);

int gcd(int x, int y){
    static int ExeNum = 1;
    printf("%d 실행한다.\r\n", ExeNum++);

    if(y != 0){
        printf("x: %d, y : %d \r\n", x, y);
        return gcd(y, x % y);
    }else{
        return x;
    }
}

int main(){
    int result;
    int num1, num2;
    printf("최대 공약수를 구하는 프로그램\r\n");
    printf("2개의 수를 입력하세요.\r\n");
    printf("입력 => ");
    scanf("%d %d",&num1, &num2);

    result = gcd(num1, num2);
    printf("%d 와 %d의 최대 공약수는 : %d \r\n", num1, num2, result);
    return 0;
}