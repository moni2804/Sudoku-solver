#include <stdio.h>
#include "sudoku.h"
int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main(void) {
    int** puzzle = createPuzzle();
    int progress;
    Sudoku * sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);

    while(UNSOLVED>0){
        progress = checkPuzzle(sudoku->squares,sudoku->boxes);

        if(progress==0){
            printf("Failed to solve the puzzle\n\n");
            break;
        }

    }

    printf("\n solved: \n");

    printPuzzle(sudoku->squares);

    return 0;
}
