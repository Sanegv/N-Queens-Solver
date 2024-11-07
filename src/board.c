#include "board.h"

board* newBoard(int N){
    board *b = malloc(sizeof(board));
    if(!b)
        return NULL;

    b->N = N;
    b->chessboard = malloc(N * sizeof (bool*));
    if(!b->chessboard)
        return NULL;
    for(int i = 0; i < N; i++){
        b->chessboard[i] = calloc(N, sizeof(bool));
        if(!b->chessboard[i])
            return NULL;
    }

    return b;
}

bool changeQueenState(board* b, int x, int y){
    if(b == NULL || x < 0 || y < 0 || b->N <= x || b->N <= y)
        return false;

    b->chessboard[x][y] = !b->chessboard[x][y];
    return true;
}

void printQueens(board b){
    printf("  A B C D E F G H\n");
    for(int i = 0; i < b.N; i++){
        printf("%d ", i+1);
        for(int j = 0; j < b.N; j++){
            printf((b.chessboard[i][j]) ? "D " : "# ");
        }
        printf("\n");
    }
}

int countQueens(board b){
    int count = 0;
    for(int i = 0; i < b.N; i++){
        for(int j = 0; j < b.N; j++){
            if(b.chessboard[i][j])
                count++;
        }
        printf("\n");
    }
    return count;
}

void freeBoard(board* b){
    for(int i = 0; i < b->N; i++)
        free(b->chessboard[i]);
    free(b->chessboard);
    free(b);
}