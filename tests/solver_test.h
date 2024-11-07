#ifndef QUEENS_SOLVER_SOLVER_TEST_H
#define QUEENS_SOLVER_SOLVER_TEST_H

#include <assert.h>
#include "src/solver.h"

void testSolve(){
    printf("Running solve() tests... ");

    assert(false); //todo

    printf("Passed.\n");
}

void testCheckPlacement(){
    printf("Running checkPlacement() tests... ");

    assert(false); //todo

    printf("Passed.\n");
}

void testCheckDiagonals(){
    printf("Running checkDiagonals() tests... ");

    assert(false); //todo

    printf("Passed.\n");
}

void testCheckFiles(){
    printf("Running checkFiles() tests... ");

    assert(false); //todo

    printf("Passed.\n");
}

void testCheckRanks(){
    printf("Running checkRanks() tests... ");

    assert(false); //todo

    printf("Passed.\n");
}

void testCheckEmpty(){
    printf("Running checkEmpty() tests... ");

    assert(false); //todo
    assert(checkEmpty(&test, 0, 0) && "Empty tile should return true.");
    assert(!checkEmpty(&test, 3, 2) && "Occupied tile should return false.");
    assert(!checkEmpty(&test, -1, 2) && "x < 0 should return false.");
    assert(!checkEmpty(&test, 1, -1) && "y < 0 should return false.");
    assert(!checkEmpty(&test, 8, 2) && "x > 7 should return false.");
    assert(!checkEmpty(&test, 1, 8) && "y > 7 should return false.");

    printf("Passed.\n");
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
