#ifndef QUEENS_SOLVER_BOARD_TEST_H
#define QUEENS_SOLVER_BOARD_TEST_H

#include <assert.h>
#include "src/board.h"

void testNewBoard(){
    printf("Running newBoard() tests... ");

    board * test;
    int testSize = 8;
    assert((test = newBoard(testSize)) != NULL && "Board allocation failed.");
    assert(testSize == test->N && "N initialization incorrect.");
    bool **array = test->chessboard;
    free(test);
    assert(array != NULL && "Chessboard allocation failed.");
    for(int i = 0; i < testSize; i++){
        assert(array[i] != NULL && "Chessboard row allocation failed.");
        for(int j = 0; j < testSize; j++)
            assert(array[i][j] == false && "Chessboard file allocation failed.");
        free(array[i]);
    }

    free(array);
    printf("Passed.\n");
}

void testChangeQueenState(){
    printf("Running changeQueenState() tests... ");

    int testSize = 8;
    int x = 5, y = 4;
    board *test = newBoard(testSize);
    changeQueenState(test, x, y);
    printf("\n");
    printQueens(*test);
    for(int i = 0; i < testSize; i++){
        for(int j = 0; j < testSize; j++){
            if(i != x || j != y)
                assert(test->chessboard[i][j] == false && "Board should be empty except for the right tile.");
            else
                assert(test->chessboard[i][j] == true && "The right tile should be true.");
        }
    }
    changeQueenState(test, x, y);
    for(int i = 0; i < testSize; i++){
        for(int j = 0; j < testSize; j++){
                assert(test->chessboard[i][j] == false && "Board should be entirely empty.");
        }
    }

    printf("Passed.\n");
    freeBoard(test);
}

void testCountQueens(){
    printf("Running board.h tests...\n");

    int testSize = 8;
    int x1 = 1, y1 = 2, x2 = 3, y2 = 4;
    board* test = newBoard(testSize);
    assert(countQueens(*test) == 0 && "Board should be empty at first.");
    test->chessboard[x1][y1] = true;
    test->chessboard[x2][y2] = true;
    assert(countQueens(*test) == 2 && "Board should now contain 2 queens.");

    printf("Passed.\n");
    freeBoard(test);
}

void allBoardTests(){
    testNewBoard();
    testChangeQueenState();
    testCountQueens();
    printf("All board.h tests passed.\n");
}

#endif