#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int Number;
    char Name;
} NODE;


NODE Student[10];

int main(){
    int i;
    for(i = 0; i < 10; i++){
        Student[i].Number = 1000 + i;
        Student[i].Name = 'A' + i;
    }
    printf("다섯번쨰 학생의 학번과 이름 출력 \r\n");
    printf("학번 : [%d]\r\n", Student[4].Number);
    printf("이름 : [%c]\r\n", Student[4].Name);
    return 0;
}