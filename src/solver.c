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
    if(b == NULL || i < 0 || j < 0 || b->N <= i || b->N <= j)
        return false;
    return !(b->chessboard[i][j]);
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
    if(b == NULL)
        return false;
    int count;
    for(int i = 0; i < b->N; i++){
        count = 0;
        for(int j = 0; j < b->N; j++){
            if(b->chessboard[j][i])
                count++;
        }
        if(count > 1)
            return false;
    }
    return true;
}

bool checkFiles(board* b){
    if(b == NULL)
        return false;
    int count;
    for(int i = 0; i < b->N; i++){
        count = 0;
        for(int j = 0; j < b->N; j++){
            if(b->chessboard[i][j])
                count++;
        }
        if(count > 1)
            return false;
    }
    return true;
}