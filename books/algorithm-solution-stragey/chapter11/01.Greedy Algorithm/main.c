/** 
 * 
 * 입력 
 * 
 * 1. 입력 파일의 이름은 input.txt이다.
 * 2. 입력 데이터는 T개의 테스트 케이스로 이루어져 있으며 파일 첫번째 행에 주어진다.
 * 3. 각 테스트의 첫 번째 행에는 두 정수 E, F (1<=E<=F<=10000)가 주어진다. 이때 E는 운영체제가 
 * 기본적으로 차지하는 메모리의 크기고, F는 제공된 전체 메모리의 크기다.
 * 4. 각 테스트의 두번째 행에는 스마트폰에 포딩될 앱의 개수를 나타내는 정수 N이 주어진다.
 * 5. N행 각각에는 P(1<=P<=50000)와 W(1<=W<=10000)가 주어진다. P는 이앱을 실행하는 데 소요 
 * 되는 시간이고, W는 프로그램이 차지하는 메모리 크기다.
 * 
 * 출력
 * 
 * 1. 출력 파일은 output.txt이다.
 * 2. 각 테스트에 주어진 메모리의 크기를 갖는 앱들이 실행될 떄 소요되는 최소시간을 출력한다.
 * 3. 사용하는 앱의 메모리 크기가 정확히 맞지 않으면, -1을 대신 출력한다.
 * 
 * 입력 예
 * 3
 * 10 110
 * 2
 * 1 1
 * 30 50
 * 10 110
 * 2
 * 1 1
 * 50 30
 * 1 6
 * 2
 * 10 3
 * 20 4
 * 출력 예
 * 스마트폰의 최소 실행 시간 : 60
 * 스마트폰의 최소 실행 시간 : 100
 * -1
 * 
 */
#include <stdio.h>

#define INPUT_FILE      "input.txt"
#define OUTPUT_FILE     "output.txt"
#define MAX_N           1000
#define MAX_WEIGHT      10000
#define MAX_VALUE       (50000 * MAX_WEIGHT)

int T, E, F, N;
int P[MAX_N], W[MAX_N];
int S[MAX_WEIGHT];

FILE *inf, *outf;

void intput_data(){
    int i;
    fscanf(inf, "%d %d\r\n", &E, &F);
    fscanf(inf, "%d\r\n", &N);

    for(i = 0; i < N; i++){
        fscanf(inf, "%d %d\r\n", &P[i], &W[i]);
    }
}

void Initialize_S(){
    int i;
    S[0] = 0;

    for(i = 1; i <= F - E; i++){
        S[i] = MAX_VALUE;
    }
}

void solve(){
    int i, j;
    Initialize_S();

    for(i = 0; i < N; i++){
        for(j = 0; j <= F-E-W[i]; j++){
            if(S[j] + P[i] < S[j + W[i]]){
                S[j + W[i]] = S[j] + P[i];
            }
        }
    }
}

void output_result(){
    if(S[F - E] == MAX_VALUE){
        fprintf(outf, "-1\r\n");
    }else{
        fprintf(outf, "스마트폰의 최소 실행 시간 : %d\r\n", S[F - E]);
    }
}

int main(){
    int i;
    inf = fopen(INPUT_FILE, "r");
    outf = fopen(OUTPUT_FILE, "w");
    fscanf(inf, "%d\r\n", &T);

    for(i = 0; i < T; i++){
        intput_data();
        solve();
        output_result();
    }
    fclose(inf);
    fclose(outf);
    return 0;
}