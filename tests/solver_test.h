#ifndef QUEENS_SOLVER_SOLVER_TEST_H
#define QUEENS_SOLVER_SOLVER_TEST_H

#include <assert.h>
#include "src/solver.h"

void testSolve(){
    printf("Running solve() tests... ");

    board *test = newBoard(8);
    assert(solve(test, 0) && "solve() should find a solution");
    assert(countQueens(*test) == 8 && "Solution should have eight queens exactly.");
    assert(checkPlacement(test) && "Solution should be valid.");

    test->chessboard[0][1] = true;
    test->chessboard[1][1] = true;
    assert(!solve(test, 0) && "solve() should not find an impossible solution");
    assert((test->chessboard[0][1] && test->chessboard[1][1]) && "solve() should not alter the board if it does not find a solution.");

    printf("Passed.\n");
}

void testCheckPlacement(){
    printf("Running checkPlacement() tests... ");

    board *test = newBoard(8);
    assert(checkPlacement(test) && "Empty board should be valid.");
    test->chessboard[1][2] = true;
    assert(checkPlacement(test) && "Board with one queen should be valid.");
    test->chessboard[7][0] = true;
    assert(checkPlacement(test) && "Board with two separated queens should be valid.");
    test->chessboard[7][0] = false;
    assert(!checkPlacement(test) && "Board with two queens on the same rank should not be valid.");
    test->chessboard[5][2] = true;
    test->chessboard[5][2] = false;
    test->chessboard[1][5] = true;
    assert(!checkPlacement(test) && "Board with two queens on the same file should not be valid.");
    test->chessboard[1][5] = false;
    test->chessboard[3][4] = true;
    assert(!checkPlacement(test) && "Board with two queens on the same diagonal should not be valid.");

    printf("Passed.\n");
    freeBoard(test);
}

void testCheckDiagonals(){
    printf("Running checkDiagonals() tests... ");

    board *test = newBoard(8);
    assert(checkDiagonals(test) && "Empty board should be valid.");
    test->chessboard[1][3] = true;
    assert(checkDiagonals(test) && "Board with one queen should be valid.");
    test->chessboard[7][0] = true;
    assert(checkDiagonals(test) && "Board with two separated queens should be valid.");
    test->chessboard[7][0] = false;
    test->chessboard[5][3] = true;
    assert(checkDiagonals(test) && "Board with two queens on the same file should be valid.");
    test->chessboard[5][5] = true;
    assert(checkDiagonals(test) && "Board with two queens on the same rank should be valid.");
    test->chessboard[5][5] = false;

    test->chessboard[0][4] = true;
    assert(!checkDiagonals(test) && "Board with two queens on the same (lower) diagonal should not be valid.");
    test->chessboard[0][4] = false;
    test->chessboard[2][2] = true;
    assert(!checkDiagonals(test) && "Board with two queens on the same (upper) diagonal should not be valid.");
    test->chessboard[2][2] = false;
    test->chessboard[2][4] = true;
    assert(!checkDiagonals(test) && "Board with two queens on the same (lower anti) diagonal should not be valid.");
    test->chessboard[2][4] = false;
    test->chessboard[0][2] = true;
    assert(!checkDiagonals(test) && "Board with two queens on the same (upper anti) diagonal should not be valid.");

    printf("Passed.\n");
    freeBoard(test);
}

void testCheckFiles(){
    printf("Running checkFiles() tests... ");

    board *test = newBoard(8);
    assert(checkFiles(test) && "Empty board should be valid.");
    test->chessboard[3][1] = true;
    assert(checkFiles(test) && "Board with one queen should be valid.");
    test->chessboard[0][7] = true;
    assert(checkFiles(test) && "Board with two separated queens should be valid.");
    test->chessboard[3][5] = true;
    assert(checkFiles(test) && "Board with two queens on the same rank should be valid.");
    test->chessboard[5][5] = true;
    assert(!checkFiles(test) && "Board with two queens on the same file should not be valid.");

    printf("Passed.\n");
    freeBoard(test);
}

void testCheckRanks(){
    printf("Running checkRanks() tests... ");

    board *test = newBoard(8);
    assert(checkRanks(test) && "Empty board should be valid.");
    test->chessboard[1][3] = true;
    assert(checkRanks(test) && "Board with one queen should be valid.");
    test->chessboard[7][0] = true;
    assert(checkRanks(test) && "Board with two separated queens should be valid.");
    test->chessboard[5][3] = true;
    assert(checkRanks(test) && "Board with two queens on the same file should be valid.");
    test->chessboard[5][5] = true;
    assert(!checkRanks(test) && "Board with two queens on the same rank should not be valid.");

    printf("Passed.\n");
    freeBoard(test);
}

void testCheckEmpty(){
    printf("Running checkEmpty() tests... ");
    
    board *test = newBoard(8);
    int x = 3;
    int i = 2;
    test->chessboard[x][i] = true;
    assert(checkEmpty(test, 0, 0) && "Empty tile should return true.");
    assert(!checkEmpty(test, x, i) && "Occupied tile should return false.");
    assert(!checkEmpty(test, -1, 1) && "x < 0 should return false.");
    assert(!checkEmpty(test, 1, -1) && "y < 0 should return false.");
    assert(!checkEmpty(test, 8, 2) && "x > 7 should return false.");
    assert(!checkEmpty(test, 1, 8) && "y > 7 should return false.");

    printf("Passed.\n");
    freeBoard(test);
}

void allSolverTests(){
    printf("Running solver.h tests...\n");

    testCheckEmpty();
    testCheckRanks();
    testCheckFiles();
    testCheckDiagonals();
    testCheckPlacement();
    testSolve();

    printf("All solver.h tests passed.\n");
}

#endif //QUEENS_SOLVER_SOLVER_TEST_H
