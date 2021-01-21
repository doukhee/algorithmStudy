/**
 * 1. 몇 개의 블록을 사용할지는 사용자가 직접 값을 입력하게 한다. 그리고 블록 개수는 'N x (N + 1) / 2'로 한다.
 * 2. 판 크기와 판매 들어 있는 숫자는 입력 데이터로 제공한다.
 * 3. 블록 하ㅏ나는 2개의 숫자로 구성되어 있으며, 같은 숫자 쌍으로 구성된 블록은 오직 하나의 블록만 존재한다.
 * 4. 각 블록은 직사각형의 형태로 판 위에 한번만 놓여야 하고 판의 셀을 중복해서 사용할 수 없다.
 * 
 * 입력
 * 입력 파일의 이름은 input.txt이다.
 * 첫번째 행은 블록의 개수를 결정하는 N값이 주어진다.
 * 두번째 행 이후는 블록이 놓일 판의 크기와 판의 셀 위에 적혀 있는 숫자 조합을 의미한다.
 * 
 * 출력
 * 출력 파일의 이름은 output.txt이다.
 * 각 블록에 적혀 있는 2개의 숫자를 하나의 쌍으로 해서 텍스트로 출력한다.
 * 같은 숫자의 쌍으로 이루어진 가로, 세로 배치는 입력 데이터 판 위치에 놓이는 블록 배치가 되어야한다.
 * 
 */


#include <stdio.h>
#include <stdlib.h>

#define MAX_N           100
#define INPUT_FILE      "input.txt"
#define OUTPUT_FILE     "output.txt"
#define true            1
#define false           (!true)

typedef struct _pList{
    int x1;
    int y1;
    int x2;
    int y2;
    struct _pList *next;
} pList;

int n;
int Board[MAX_N][MAX_N + 1];
int CounterBoard[MAX_N + 1][MAX_N + 1];
int Visited[MAX_N + 1][MAX_N + 1];
pList *PositionList[MAX_N + 1][MAX_N + 1];
pList *header[MAX_N + 1][MAX_N + 1];
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int Result[MAX_N][MAX_N + 1];
int res_n;
int found = false;
int RC = 0;

void Input_data();
void AddPositionList(int, int, int, int, int, int);
void preprocess(void);
int out(int , int);
void decrease(int, int);
void increase(int, int);
void Output_result(void);
void find_solution(void);
void Solve(void);

void Input_data(){
    int i, j;
    FILE *inf;
    inf = fopen(INPUT_FILE, "r");
    fscanf(inf, "%d\r\n", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n + 1; j++){
            fscanf(inf, "%d", &Board[i][j]);
        }
    }
    fclose(inf);
}

void AddPositionList(int p, int q, int y1, int x1, int y2, int x2){
    int temp;
    if(p > q){
        temp = p;
        p = q;
        q = temp;
    }

    CounterBoard[p][q]++;
    PositionList[p][q]->next = (pList *) malloc(sizeof(pList));
    PositionList[p][q] = PositionList[p][q]->next;

    PositionList[p][q]->y1 = y1;
    PositionList[p][q]->x1 = x1;
    PositionList[p][q]->y2 = y2;
    PositionList[p][q]->x2 = x2;
    PositionList[p][q]->next = NULL;
}

void preprocess(void){
    int i, j;
    int p, q;

    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            PositionList[i][j]  = (pList *)malloc(sizeof(pList));
            PositionList[i][j]->next = NULL;
            header[i][j] = PositionList[i][j];
        }
    }

    for(i = 0; i < n; i++){
        p = Board[i][0];

        for(j = 1; j < n + 1; j++){
            q = Board[i][j];
            AddPositionList(p, q, i, j - 1, i, j);
            p = q;
        }
    }

    for(i = 0; i < n + 1; i++){
        p = Board[0][i];
        for(j = 1; j < n; j++){
            q = Board[j][i];
            AddPositionList(p, q, j - 1, i, j, i);
            p = q;
        }
    }
}

int out(int y, int x){
    if((y < 0) || (x < 0) || (y >= n) || (x > n)){
        return true;
    }else{
        return false;
    }
}

void increase(int n1, int n2){
    if(n1 < n2){
        CounterBoard[n1][n2]++;
    }else{
        CounterBoard[n2][n1]++;
    }
}

void decrease(int n1, int n2){
    if(n1 < n2){
        CounterBoard[n1][n2]--;
    }else{
        CounterBoard[n2][n1]--;
    }
}

void Output_result(){
    int i, j;
    FILE *outf;
    outf = fopen(OUTPUT_FILE, "w");

    if(!found){
        fprintf(outf, "Impossible\r\n");
    }else{
        for(i = 0; i < n; i++){
            for(j = 0; j < n + 1; j++){
                fprintf(outf, "%d ", Result[i][j]);
            }
            fprintf(outf, "\r\n");
        }
    }
    //fclose(outf);
}

void find_solution(){
    int i, j;
    int p, q, min;
    pList *PositionList;
    int y1, x1, y2, x2;
    int yy, xx;
    RC++;

    p = q = -1;

    if(RC == MAX_N * (MAX_N + 1) / 2){
        found = true;
        Output_result();
        exit(0);
    }

    min = MAX_N * MAX_N * 2 + 1;

    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            if((!Visited[i][j]) && (CounterBoard[i][j] < min)){
                min = CounterBoard[i][j];
                p = i;
                q = j;
            }
        }
    }

    if(min == 0){
        return;
    }

    if(p < 0 || q < 0){
        found = true;
        Output_result();
        exit(0);
    }

    PositionList = header[p][q];
    Visited[p][q] = true;

    while(PositionList->next != NULL){
        PositionList = PositionList->next;
        y1 = PositionList->y1;
        x1 = PositionList->x1;
        y2 = PositionList->y2;
        x2 = PositionList->x2;

        if(Result[y1][x1] || Result[y2][x2]){
            continue;
        }

        for(i = 0; i < 4; i++){
            yy = y1 + dir[i][0];
            xx = x1 + dir[i][1];

            if(out(yy, xx) || (yy == y2) && (xx == x2)){
                continue;
            }

            if(!Result[yy][xx]){
                decrease(Board[y1][x1], Board[yy][xx]);
            }
        }

        for(i = 0; i < 4; i++){
            yy = y2 + dir[i][0];
            xx = x2 + dir[i][1];

            if((out(yy, xx)) || (yy == y1) && (xx == x1)){
                continue;
            }

            if(!Result[yy][xx]){
                decrease(Board[y2][x2], Board[yy][xx]);
            }
        }

        res_n++;
        Result[y1][x1] = res_n;
        Result[y2][x2] = res_n;

        find_solution();

        res_n--;
        Result[y1][x1] = 0;
        Result[y2][x2] = 0;

        for(i = 0; i < 4; i++){
            yy = y1 + dir[i][0];
            xx = x1 + dir[i][1];

            if((out(yy, xx)) || (yy == y2) && (xx == x2)){
                continue;
            }

            if(!Result[yy][xx]){
                increase(Board[y1][x1], Board[yy][xx]);
            }
        }

        for(i = 0; i < 4; i++){
            yy = y2 + dir[i][0];
            xx = x1 + dir[i][1];

            if((out(yy, xx)) || (yy == y1) && (xx == x1)){
                continue;
            }
            if(!Result[yy][xx]){
                increase(Board[y2][x2], Board[yy][xx]);
            }
        }
    }
    Visited[p][q] = false;
}

void Solve(){
    preprocess();
    find_solution();
    Output_result();
}

int main(){
    Input_data();
    Solve();
    return 0;
}