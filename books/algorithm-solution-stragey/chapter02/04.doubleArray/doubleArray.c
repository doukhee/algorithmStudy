#include <stdio.h>


void DisplayTable(void);

int Grade[5][2];

void main(void){
    int i;

    printf("각 학생의 영어 점수와 수학 점수를 입력하세요\r\n");
    for(i = 0; i < 5; i++){
        printf("%d번 학생의 영어 점수 : ", i+1);
        scanf("%d", &Grade[i][0]);
        printf("%d번 학생의 수학 점수 : ", i+1);
        scanf("%d", &Grade[i][1]);
    }

    printf("입력을 종료 합니다.\r\n");
    DisplayTable();
}

void DisplayTable(){
    int i;
    int Total[2] = {0,0};
    printf("학샘 번호 \t영어 점수\t수학 점수\r\n");


    for(i = 0; i < 5; i++){
        printf("\t%d\t\t%d\t\t%d\r\n", i+1, Grade[i][0], Grade[i][1]);
        Total[0] += Grade[i][0];
        Total[1] += Grade[i][1];
    }

    printf("===================================================\r\n");
    printf("총점\t\t\t%d\t\t%d\r\n", Total[0], Total[1]);
    printf("평균\t\t\t%d\t\t%d\r\n", Total[0]/5, Total[1]/5);
}