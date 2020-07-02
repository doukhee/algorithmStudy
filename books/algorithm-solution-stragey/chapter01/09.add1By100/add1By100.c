#include <stdio.h>

int main(int argc, char **argv){
    int Sum = 0;
    int i;

    for(i = 1; i <= 100; i++){
        Sum = Sum + i;
    }
    printf("1 by 100 Add Value : %d \r\n", Sum);
    return 0;
}