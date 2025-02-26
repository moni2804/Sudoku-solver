#include <malloc.h>
#include <stdio.h>
#include "sudoku.h"
#include "square.h"

int ** createPuzzle(){
    int ** puzzle;
    int array[9][9]={0,1,9,       0,0,2,       0,0,0,
                     4,7,0,       6,9,0,       0,0,1,
                     0,0,0,       4,0,0,       0,9,0,

                     8,9,4,       5,0,7,       0,0,0,
                     0,0,0,       0,0,0,       0,0,0,
                     0,0,0,       2,0,1,       9,5,8,

                     0,5,0,       0,0,6,       0,0,0,
                     6,0,0,       0,2,8,       0,7,9,
                     0,0,0,       1,0,0,       8,6,0
    };

    puzzle = (int **)malloc(sizeof(int*)*SIZE_ROWS);

    for(int i=0;i<SIZE_ROWS;i++){
        puzzle[i] = (int*)malloc(sizeof(int)*SIZE_COLUMNS);
        for(int j=0;j<SIZE_COLUMNS;j++){
            puzzle[i][j]=array[i][j];
        }
    }

    return puzzle;
}

void printPuzzle(Square*** puzzle) {
    for (int i = 0; i < SIZE_ROWS; i++) {
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            if (i % 3 == 0 && j == 0) {
                printf("-------------------------------------\n");
            }
            if (j % 3 == 0) {
                printf(" | ");
            }

            printf(" %d ", puzzle[i][j]->number);
        }
        printf("|\n");
    }
}

///Once a single square is solved, all other squares along the same row
///and column must be updated to reflect the change
int updateSudoku(Square*** sudoku,int row,int col){
    int number = sudoku[row][col]->number;

    for (int i=0;i<SIZE_ROWS;i++) {
        if (sudoku[i][col]->possible[number - 1] == 0) {
            sudoku[i][col]->solvable--;
        }

        sudoku[i][col]->possible[number - 1] = 1;
    }

    for (int i=0;i<SIZE_COLUMNS;i++) {
        if (sudoku[row][i]->possible[number - 1] == 0) {
            sudoku[row][i]->solvable--;
        }

        sudoku[row][i]->possible[number - 1] = 1;
    }

    return 1;
}

///Initial puzzle creation
Sudoku* setUpPuzzle(int** puzzle){

    Square *** sudoku;
    Box** boxes;
    int currentBox =0;

    sudoku=(Square***)malloc(sizeof(Square**)*9);
    boxes=createBoxes();

    //loop through rows
    for(int i=0;i<SIZE_ROWS;i++){
        sudoku[i]=(Square**)malloc(sizeof(Square*)*SIZE_ROWS);

        //loop through columns
        for(int j=0;j<SIZE_COLUMNS;j++){
            sudoku[i][j]=(Square*)malloc(sizeof(Square)*SIZE_COLUMNS);

            //assign number to sudoku adt
            sudoku[i][j]->number=puzzle[i][j];

            sudoku[i][j]->row=i;
            sudoku[i][j]->col=j;
            sudoku[i][j]->solvable = 9;

            boxes[currentBox]->squares[boxes[currentBox]->numbers] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;

            for(int k=0;k<SIZE_ROWS;k++){
                sudoku[i][j]->possible[k]=0;
            }

            if(j == 2 || j==5){
                currentBox++;
            }
        }

        currentBox -=2;

        if(i == 2 || i==5)
            currentBox = i+1;
    }

    for(int i=0;i<SIZE_ROWS;i++){
        for(int j=0;j<SIZE_COLUMNS;j++){
            if(sudoku[i][j]->number != 0){
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku,i,j);
                updateBoxes(sudoku,i,j);
                UNSOLVED--;
            }
        }
    }

    return createSudoku(sudoku,boxes);
}

Sudoku* createSudoku(Square*** squares,Box** boxes){
    struct Sudoku* sudoku=malloc(sizeof(Sudoku));

    sudoku->squares=squares;
    sudoku->boxes=boxes;

    return sudoku;
}

///Function ti check for a solvable square
int checkPuzzle(Square*** sudoku,Box** boxes){
    for(int i=0;i<SIZE_ROWS;i++){
        for(int j=0;j<SIZE_COLUMNS;j++){
            if(sudoku[i][j]->solvable == 1){
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku,i,j);
                updateBoxes(sudoku,i,j);

                return 1;
            }
        }
    }

    if(boxSingles(sudoku,boxes)){
        return 1;
    }

    return checkRows(sudoku);
}

