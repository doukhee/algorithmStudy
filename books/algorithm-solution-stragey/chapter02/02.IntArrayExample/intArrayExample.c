#include <stdio.h>

#define MAX     5

void main(){
    int Scores[MAX];
    double total, aver;
    int i;

    printf("5 score input : ");

    for(i = 0; i < MAX; i++){
        printf("score -->");
        scanf("%d", &Scores[i]);
    }

    total = 0;

    for(i = 0; i < MAX; i++){
        total += Scores[i];
    }

    aver = total / MAX;
    printf("Total Score : %f, Average : %2f \r\n", total, aver);
}