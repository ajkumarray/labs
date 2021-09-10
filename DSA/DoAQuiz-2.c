//  DoA Quiz2      4 Queen Problem

#include <stdio.h>
#include <stdbool.h>
#define N 4

int ld[30] = { 0 };
int rd[30] = { 0 };
int cl[30] = { 0 };

void printSolution(int board[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool solveNQueen(int board[N][N], int col)
{
    if(col >= N)
        return true;
    
    for(int i = 0; i < N; i++)
    {
        if((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && cl[i] != 1)
        {
            board[i][col] = 1;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;
            
            if(solveNQueen(board, col + 1))
                return true;
            
            board[i][col] = 0;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
        }
    }
    return false;
}

bool nQueen()
{
    int board[N][N] =
        {{0, 0, 0, 0},
        { 0, 0, 0, 0},
        { 0, 0, 0, 0},
        { 0, 0, 0, 0}};
    if(solveNQueen(board, 0) == false)
    {
        printf("Solution does not exist\n");
        return false;
    }
    printSolution(board);
    return true;
}

int main(int argc, const char * argv[]) {
    printf("Solution of 4 Queen problem:\n");
    nQueen();
    return 0;
}
