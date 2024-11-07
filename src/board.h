#ifndef QUEENS_SOLVER_BOARD_H
#define QUEENS_SOLVER_BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int N;
    bool **chessboard;
} board;

board* newBoard();

bool changeQueenState(board* b, int x, int y);

void printQueens(board b);

int countQueens(board b);

void freeBoard(board* b);

#endif //QUEENS_SOLVER_BOARD_H
