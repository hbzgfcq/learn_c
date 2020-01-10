#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLS 8

struct cell{
    int row;
    int col;
};

char maze[ROWS][COLS];
int seed = 314159;

void initMaze();
int printMaxe();
int genRandom(int);
void nextStepRandom();

int main(){
    
    initMaze();
    printMaxe();

    //struct cell a_cell;
    //a_cell.row = 3;
    //a_cell.col =5;
    //nextStepRandom(&a_cell);
}

/********************************************************/
int printMaxe(){
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (maze[i][j]==1){
                printf("\033[41;31m   \033[0m  ");
            }
            else{
                printf("\033[42;31m   \033[0m  ");
            }
        }
        printf("\n\n");
    }
}

void initMaze(){
    int i,j;
    for(i=0;i<ROWS;i++){
        for (j=0;j<COLS;j++){
            maze[i][j] = 1;
        }
    }
    int r = genRandom(ROWS);
    struct cell current_cell={0, r};
    while((current_cell.row>=0) && (current_cell.row<ROWS) && (current_cell.col>=0) &&(current_cell.row<COLS)){
        maze[current_cell.row][current_cell.col] = 0;
        nextStepRandom(&current_cell);
    }
}

int genRandom(int max){
    seed = (seed + rand()) * seed;
    srand(seed);
    return rand() % max;
}

void nextStepRandom(struct cell * p_cell){
    int dlta = genRandom(2)-1;
    int dltaR = 0, dltaC = 0;
    int x = genRandom(9);
    if (x>5){
        dltaR = dltaR + dlta;
    }
    else if (x<5)
    {
        dltaC = dltaC + dlta;
    }

    (*p_cell).row += dltaR;
    (*p_cell).col += dltaC;
}