/**
 * 
 * 입력
 * 입력파일은 input.txt이다.
 * 파일의 첫 번째 행에는 세로 칸 숫자인 M, 가로 칸 숫자인 N, 사람들이 한 번에 이동할 수 있는 값인 X가 주어진다.
 * 두번째 행 이후는 M x N형태의 문자열로 건물의 초기 상태가 주어진다. 화재 발생 구역은 F, 현재 위치는 Y, 안전 구역은 O, 탈출구는 E로 표시한다.
 * 
 * 출력
 * 출력 파일의 이름은 output.txt다.
 * 첫 번째 행에는 최소 몇 번의 움직임으로 탈출구까지 도달하는지 횟수를 출력한다.
 * 두번째 행에는 이동 경로를 출력한다. 위(U), 아래(D), 왼쪽(L), 오른쪽(R)의 조합으로 이루어지며, 답이 여러개인 경우 그중 하나만 출력한다.
 * 
 * 입력 예
 * 5 5 2
 * F000E
 * 00000
 * 00000
 * 00000
 * Y0FF0
 * 
 * 출력 예
 * 8
 * UURURRRU
 * 
 */

#include <stdio.h>

#define INPUT_FILE      "input.txt"
#define OUTPUT_FILE     "output.txt"
#define MAX_M           100
#define MAX_N           100
#define FIRE_MAX        MAX_M * MAX_N
#define false           0
#define true            (!false)

typedef int BOOL;

int M, N, X;
int Building[MAX_M][MAX_N], Path[MAX_M][MAX_N];
int path[MAX_M][MAX_N];
char dir[5] = {' ','U','L','R','D'};
int res_n, res_y, res_x;
char res[FIRE_MAX];
BOOL found;
int stx, sty;
int MyQueue[FIRE_MAX][2];
int rear, front;

void Input_data(){
    int i, j;
    char ch;
    FILE *inf;
    inf = fopen(INPUT_FILE, "r");
    fscanf(inf, "%d %d %d\r\n", &M, &N, &X);

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            fscanf(inf, "%c", &ch);

            if(ch == 'F'){
                Building[i][j] = FIRE_MAX;
            }

            if(ch == 'Y'){
                sty = i;
                stx = j;
            }
            if(ch == 'E'){
                Building[i][j] = -1;
            }
        }
        fscanf(inf, "\r\n");
    }
    fclose(inf);
}

void InsertData(int y, int x, int dir, int count){
    MyQueue[rear][0] = y;
    MyQueue[rear][1] = x;

    if(Building[y][x] == -1){
        found = true;
        res_y = y;
        res_x = x;
    }

    Building[y][x] = count;
    path[y][x] = dir;
    rear++;
}

void RemoveData(int *y, int *x){
    *y = MyQueue[front][0];
    *x = MyQueue[front][1];
    front++;
}

void Fire(){
    int i, j;
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            if(Building[i][j] == FIRE_MAX){
                if(i > 0){
                    Path[i - 1][j] = FIRE_MAX;
                }
                if(j > 0){
                    Path[i][j - 1] = FIRE_MAX;
                }
                if(i < M - 1){
                    Path[i + 1][j] = FIRE_MAX;
                }
                if(j < N - 1){
                    Path[i][j + 1] = FIRE_MAX;
                }
            }
        }
    }
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            if(Path[i][j] == FIRE_MAX){
                Building[i][j] = FIRE_MAX;
            }
        }
    }
}

void SearchPath(){
    int y, x;
    int bound;
    int count = 0;
    InsertData(sty, stx, 0, count + 1);
    bound = rear + 1;
    while(rear >= front){
        RemoveData(&y, &x);
        if(front >= bound){
            count++;
            if((count > X) && ((count - 1) % X == 0)){
                Fire();
            }
            bound = rear + 1;
        }

        if(Building[y][x] == FIRE_MAX){
            continue;
        }

        if((y > 0) && (Building[y-1][x] <= 0 )){
            InsertData(y - 1, x, 4, count + 2);
        }

        if((y < M - 1) && (Building[y + 1][x] <= 0)){
            InsertData(y + 1, x, 1, count + 2);
        }

        if((x > 0) && (Building[y][x - 1] <= 0)){
            InsertData(y, x - 1, 3, count + 2);
        }

        if((x < N - 1) && (Building[y][x + 1] <= 0)){
            InsertData(y, x + 1, 2, count + 2);
        }

        if(found){
            res_n = count + 1;
            break;
        }
    }
}

void next(int *y, int *x){
    int temp = path[*y][*x];
    switch(temp){
        case 1:
            (*y)--;
        break;
        case 2:
            (*x)--;
        break;
        case 3:
            (*x)++;
        break;
        case 4:
            (*y)++;
        break;
    }
}

void Output_result(){
    int i;
    FILE *outf;
    outf = fopen(OUTPUT_FILE, "w");

    if(!found){
        fprintf(outf, "Impossible\r\n");
    }else{
        fprintf(outf, "%d\r\n", res_n);
        res[res_n] = '\0';

        for(i = res_n - 1; i >= 0; i--){
            res[i] = dir[5 - path[res_y][res_x]];
            next(&res_y, &res_x);
        }
        fprintf(outf, "%s\r\n", res);
    }
    fclose(outf);
}

int main(){
    Input_data();
    SearchPath();
    Output_result();
    return 0;
}