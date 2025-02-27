# Sudoku Solver in C

This project is a simple Sudoku solver implemented in C. It uses a backtracking algorithm to find a valid solution to a given Sudoku puzzle.

## How It Works
- The Sudoku grid is represented as a 9x9 integer array.
- The program searches for an empty cell and attempts to fill it with numbers from 1 to 9.
- It checks whether a number placement is valid by ensuring it doesn’t violate Sudoku rules:
  - The number must not be present in the same row.
  - The number must not be present in the same column.
  - The number must not be present in the same 3x3 sub-grid.
- If a number is valid, it is placed, and the program recursively attempts to solve the rest of the puzzle.
- If no number fits, the program backtracks and tries a different number in a previous cell.

## How to Use
1. Clone or download the repository.
2. Compile the program using a C compiler.
3. Run the compiled program.
4. The solved Sudoku puzzle will be printed to the console.

## Modifying the Puzzle
- To change the Sudoku puzzle being solved, edit the `array` array inside `puzzle.c` in the function `createPuzzle`.
- Replace the existing grid with your desired puzzle, using `0` for empty spaces.

## Example Sudoku Grid
```
0 1 9  0 0 2  0 0 0
4 7 0  6 9 0  0 0 1
0 0 0  4 0 0  0 9 0

8 9 4  5 0 7  0 0 0
0 0 0  0 0 0  0 0 0
0 0 0  2 0 1  9 5 8

0 5 0  0 0 6  0 0 0
6 0 0  0 2 8  0 7 9
0 0 0  1 0 0  8 6 0

