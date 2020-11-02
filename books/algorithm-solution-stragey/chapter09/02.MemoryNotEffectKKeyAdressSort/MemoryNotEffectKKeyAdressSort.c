#include <stdio.h>
#include <stdlib.h>


typedef struct _Node{
    int Number;
    char Name;
} Node;

Node Students[100];

int main(){
    int i;
    for(i = 0; i < 100; i++){
        if(i % 2 == 0){
            Students[i].Number = 1000 + i;
            Students[i].Name = 'A' + i;
        }else{
            continue;
        }
    }
    printf("전체 데이터 크기와 저장된 데이터 크기 비교 \r\n");
    printf("전체 데이터 크기 : %lu bytes\r\n", sizeof(Node) * 100);
    printf("저장된 데이터 크기 : %lu bytes \r\n", sizeof(Node) * 100/2);
    return 0;
}