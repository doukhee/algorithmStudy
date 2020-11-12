/**
 * 1. 임의의 숫자의 약수를 구하는 방법
 * 2. 임의의 두 숫자에 공통으로 해당하는 앿수를 구하는 방법
 * 3. 임의의 두 숫자에 공통으로 해당하는 약수 중 최댓값을 선택하는 방법
 * 
 * 최대 공약수 프로그램은 수학 문제를 프로그램으로 만들 때, 어떤 접근 방식을 사용하는지 살펴볼 수 있는 몸풀기 문제이다.
 * 최대 공약수의 사전적인 의미ㅣ에서 출발하면, 최대공약수는 공약수 중 최댓값을 말한다. 
 * 두수의 공약수를 구한 후 그중에서 가장 큰 값을 최대공약수로 하면된다. 
 * 
 * 실행 결과 
 * 약수를 구할 두 정숫값을 입력하세요
 * 입력1: 280
 * 입력2: 30
 * 280과 30의 최대 공앿수는 10이다.
 * 
 */
#include <stdio.h>

int main(){
    int number1, number2, num;
    int GreatestCommonDivisor;
    printf("약수를 구할 두 정수 값을 입력하세요 \r\n");
    printf("첫번째 숫자 : ");
    scanf("%d", &number1);
    printf("두번째 숫자 : ");
    scanf("%d", &number2);
    printf("\r\n");

    if(number1 <= number2){
        num = number1;
    }else{
        num = number2;
    }
    printf("num : %d \r\n", num);
    for(int i = 1; i <= num; i++){
        if(((number1 % i) == 0) && ((number2 % i) == 0)){
            GreatestCommonDivisor = i;
            printf("%4d ", i);
            /*
            if((i == number1) || (i == number2)){
                printf("\r\n");
                break;
            }
            */
        }
    }
    printf("\r\n");
    printf("%4d %4d GreatestCommonDivisor is  %d\r\n", number1, number2, GreatestCommonDivisor);
    return 0;
}