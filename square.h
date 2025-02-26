//
// Created by Moni on 21-Feb-25.
//

#ifndef SUDOKU_SQUARE_H
#define SUDOKU_SQUARE_H

#include "sudoku.h"

void solveSquare(Square* square){
    for(int i=0;i<SIZE_ROWS;i++){
        if(square->possible[i] == 0){
            square->number = i+1;
            square->solvable = 0;
            UNSOLVED --;
        }
    }
}

#endif //SUDOKU_SQUARE_H
