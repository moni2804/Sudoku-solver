//
// Created by Moni on 26-Feb-25.
//

#include "sudoku.h"

int checkRows(Square*** sudoku){
    int sum[9];
    int place[9];

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            place[j]=0;
            sum[j]=0;
        }

        for(int j=0;j<9;j++){
            if(sudoku[i][j]->number!=0)
                continue;

            for(int k=0;k<9;k++){
                if(sudoku[i][j]->possible[k] == 0){
                    sum[k]++;
                    place[k] = j;
                }
            }

        }
        for(int k=0;k<9;k++){
            if(sum[k]==1){
                sudoku[i][place[k]]->number= k+1;
                sudoku[i][place[k]]->solvable=0;
                UNSOLVED--;

                updateSudoku(sudoku,i,place[k]);
                updateBoxes(sudoku,i,place[k]);

                return 1;
            }
        }

    }

    return 0;
}
