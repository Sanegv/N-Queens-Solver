#include "solver.h"

bool solve(board *b, int x){
    return false; //TODO
//    for(int i = x; i < 8; i++){
//        for(int j = 0; j < 8; j++){
//            if(!checkEmpty(b, i, j))
//                continue;
//            changeQueenState(b, i, j);
//            if(!checkPlacement(b)) {
//                changeQueenState(b, i, j);
//                continue;
//            }
//            if(solve(b, i+1) || countQueens(*b) == 8)
//                return true;
//            changeQueenState(b, i, j);
//        }
//    }
//    return false;
}

bool checkEmpty(board *b, int i, int j){
    //TODO
    return false;
}

bool checkPlacement(board* b){
    if(b == NULL)
        return false;

    return checkDiagonals(b) && checkFiles(b) && checkRanks(b);
}

bool checkDiagonals(board *b){
    //TODO
    return false;
}

bool checkRanks(board* b){
    //TODO
    return false;
}

bool checkFiles(board* b){
    //TODO
    return false;
}