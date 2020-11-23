/**
 * 1 ~ 25 사이의 숫자를 화면에 출력하는 방법이다. 그러나 단순히 출력 하는 것이 아니라 
 * 일정한 규칙에 맞춰서 출력하는 것이다. 이러한 문제는 가급적 빠른 시간 내에 주어진 문제를 
 * 해결하는 것이 실력 향상에 도움이ㅣ 된다.
 * 그림 1 ~ 25 사이의 숫자를 다음과 같은 실행 결과 형태로 화면에 출력하는 프로그램을 작성해 
 * 보자
 * 
 * 실행 결과
 * 지그재그 숫자 출력 프로그램
 * 1    2   3   4   5
 * 10   9   8   7   6
 * 11   12  13  14  15
 * 20   19  18  17  16
 * 21   22  23  24  25
 * 
 * 핵심 세가지
 * 1. 전체 총 몇 행을 출력하는지 결정하는 for문
 * 2. 출력하는 행이 홀수인 경우의 for문
 * 3. 출력할 행이 짝수인 경우의 for문
 */

#include <stdio.h>

int main(){
    int MAXLine = 5;
    int data;
    int MInteger;
    int LineNumber;
    printf("지그재그 숫자 출력 프로그램\r\n");
    for(LineNumber = 1; LineNumber <= MAXLine; LineNumber++){
        if((LineNumber % 2) == 0){
            for(data = LineNumber * 5; data >= (LineNumber * 5) - 4; data--){
                printf("%d\t", data);
            }
        }else{
            for(data = (5 * (LineNumber - 1)) + 1; data <= (5 * (LineNumber - 1)) + 5; data++){
                printf("%d\t", data);
            }
        }
        printf("\r\n");
    }
    printf("\r\n");
    return 0;
}