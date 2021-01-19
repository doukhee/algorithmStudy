/**
 * 입력
 * 입력파일의 이름은 input.txt이다.
 * 입력 데이터는 T개의 테스트 케이스로 이루어져 있고, T는 파일 첫번째 행에 주어진다.
 * 각 테스트의 첫 번째 행에는 DNA의 개수 N, 두번째 행에는 DNA의 패턴이 주어진다.
 * 
 * 출력
 * 출력 파일의 이름은 output.txt이다.
 * 세포가 자기 증식을 한 과정을 모두 출력한다.
 * 몇 회 분할했는지 "X회 분활"이라고 출력한다.
 * 의미 없는 값은 음수로 변환해 나타낸다.
 * 
 */

#include <stdio.h>

#define INPUT_FILE      "input.txt"
#define OUTPUT_FILE     "output.txt"
#define MAX             100
#define false           0
#define true            (!false)

typedef int bool;

int T, N;
int DNA[2][MAX];
int split_n;
FILE *inf, *outf;

void input_data(){
    int i;
    fscanf(inf, "%d\r\n", &N);

    for(i = 0; i < N; i++){
        fscanf(inf, "%d", &DNA[0][i]);
    }
}

void solve(){
    int flag = 0;
    int i, j;
    bool NotComplete = true;
    split_n = -1;


    while(NotComplete){
        DNA[1 - flag][N - 2] = DNA[flag][N - 1];

        for(i = N - 4; i >= 0; i -= 2){
            DNA[1 - flag][i] = DNA[flag][i + 1] - DNA[1 - flag][i + 2];
        }

        j = i + 2;
        j = 1 - j;

        DNA[1 - flag][j] = DNA[flag][0] - DNA[1 - flag][1 - j];

        for(i = j + 2; i < N; i += 2){
            DNA[1 - flag][i] = DNA[flag][i - 1] - DNA[1 - flag][i - 2];
        }

        split_n++;
        flag = 1 - flag;

        for(i = 0; i < N; i++){
            fprintf(outf, "%2d", DNA[flag][i]);
            if(DNA[flag][i] < 0){
                NotComplete = false;
            }
        }
        fprintf(outf, "\r\n");
    }
    if(split_n == 0){
        split_n = -1;
    }
}

void output_result(){
    fprintf(outf, "=========================================================\r\n");
    fprintf(outf, "%d회 분할 \r\n\r\n", split_n);
}


int main(){
    int i;
    inf = fopen(INPUT_FILE, "r");
    outf = fopen(OUTPUT_FILE, "w");
    fscanf(inf, "%d\r\n", &T);
    for(i = 0; i < T; i++){
        input_data();
        solve();
        output_result();
    }
    fclose(inf);
    fclose(outf);
    return 0;
}