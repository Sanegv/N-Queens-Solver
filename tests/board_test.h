#ifndef QUEENS_SOLVER_BOARD_TEST_H
#define QUEENS_SOLVER_BOARD_TEST_H

#include <assert.h>
#include "src/board.h"

void testNewBoard(){
    printf("Running newBoard() tests... ");

    assert(false); //todo

    printf("Passed.\n");
}

void testChangeQueenState(){
    printf("Running changeQueenState() tests... ");

    assert(false); //todo

    printf("Passed.\n");
}

void testCountQueens(){
    printf("Running board.h tests...\n");

    assert(false); //todo

    printf("Passed.\n");
}

void allBoardTests(){
    testNewBoard();
    testChangeQueenState();
    testCountQueens();
    printf("All board.h tests passed.\n");
}

#endif