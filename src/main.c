#include "solver.h"

int main(){
    board* b = newBoard(15);
    solve(b, 0);
    printQueens(*b);
    freeBoard(b);
}