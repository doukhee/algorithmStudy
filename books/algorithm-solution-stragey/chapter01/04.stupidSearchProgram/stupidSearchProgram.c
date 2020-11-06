/**
 * Not good search program example
 */
#include <stdio.h>

int main(int argc, char **argv){
    
    int i, input;

    int data[1000];

    for(i = 0; i < 1000; i++){
        data[i] = i + 1;
    }

    printf("search number input : ");
    scanf("%d", &input);

    for(i = 0; i < 1000; i++){
        if(input == data[i]){
            printf("%d value in data[%d]\r\n", input, i+1);
            break;
        }
    }
    
    return 0;
}