#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Box{
    struct Square** squares;
    int numbers;
    int possible[9];
    int solvable;
}Box;

typedef struct Square{
    int number;
    int possible[9];
    int solvable;
    Box* box;
    int row;
    int col;
}Square;

typedef struct Sudoku{
    struct Square*** squares;
    struct Box** boxes;
}Sudoku;

int ** createPuzzle();

void printPuzzle(Square*** puzzle);

Sudoku* setUpPuzzle(int** puzzle);

int checkPuzzle(Square*** sudoku,Box** boxes);


Sudoku* createSudoku(Square*** squares,Box** boxes);

int updateSudoku(Square*** sudoku,int row,int col);


void solveSquare(Square* square);


Box** createBoxes();

int updateBoxes(Square*** sudoku,int row,int col);

int boxSingles(Square*** sudoku,Box** boxes);


int checkRows(Square*** sudoku);


#endif //SUDOKU_SUDOKU_H
