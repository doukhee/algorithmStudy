#include <stdio.h>

int main(int argc, char **argv){
    int i;
    for(i = 0; i < 10; i++){
        printf("%d X %d = %d \r\n", i, i, i * i);
    }
    return 0;
}