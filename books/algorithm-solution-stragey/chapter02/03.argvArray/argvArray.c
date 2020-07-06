#include <stdio.h>



#define MAX_ELEMENT         100
#define SENTINEL            0
#define TRUE                1
#define FALSE               0

int GetIntegerArray(int array[], int max, int sentinel);
int GetInteger(void);
void PrintIntegerArray(int array[], int n);
void ReverseIntegerArray(int array[], int n);
void SwapIntegerElements(int array[], int p1, int p2);

int GetIntegerArray(int array[], int max, int sentinel){
    int n, value;
    n = 0;

    while(TRUE){
        printf("==> ");
        value = GetInteger();

        if(value == sentinel){
            break;
        }

        if(n == max){
            printf("총 갯수를 초과 했습니다.\r\n");
        }
        array[n] = value;
        n++;
    }
    return n;
}

int GetInteger(void){
    int n;
    scanf("%d", &n);

    return n;
}

void PrintIntegerArray(int array[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d\r\n", array[i]);
    }
}

void ReverseIntegerArray(int array[], int n){
    int i;
    for(i = 0; i < n / 2; i++){
        SwapIntegerElements(array, i, n - i - 1);;
    }
}

void SwapIntegerElements(int array[], int p1, int p2){
    int temp;
    temp = array[p1];

    array[p1] = array[p2];
    array[p2] = temp;
}

void main(void){
    int list[MAX_ELEMENT] , n;

    printf("임의 정숫값을 입력하세요 \r\n");
    printf("0을 입력하면 입력을 종료 합니다.\r\n");

    n = GetIntegerArray(list, MAX_ELEMENT, SENTINEL);

    ReverseIntegerArray(list, n);
    PrintIntegerArray(list, n);
}