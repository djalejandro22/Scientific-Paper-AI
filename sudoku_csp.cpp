#include <iostream>
#include <vector>
using namespace std;
#define SIZE 9
int grid[SIZE][SIZE];  // 0 represents empty cell

bool isValidChoice(int r, int c, int val) {
    // Check row and column
    for(int i = 0; i < SIZE; ++i) {
        if(grid[r][i] == val || grid[i][c] == val) 
            return false;
    }
    // Check 3x3 subgrid
    int subRow = (r/3) * 3;
    int subCol = (c/3) * 3;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(grid[subRow+i][subCol+j] == val) 
                return false;
        }
    }
    return true;
}

bool solveSudoku() {
    // Find an empty cell (denoted by 0)
    int row = -1, col = -1;
    bool emptyFound = false;
    for(int i = 0; i < SIZE && !emptyFound; ++i) {
        for(int j = 0; j < SIZE && !emptyFound; ++j) {
            if(grid[i][j] == 0) {
                row = i; col = j;
                emptyFound = true;
            }
        }
    }
    if(!emptyFound) {
        return true;  // no empty cells, puzzle solved
    }
    // Try filling the empty cell with a valid number
    for(int val = 1; val <= 9; ++val) {
        if(isValidChoice(row, col, val)) {
            grid[row][col] = val;
            if(solveSudoku()) {
                return true;
            }
            // Backtrack
            grid[row][col] = 0;
        }
    }
    return false;  // trigger backtracking
}

int main(){
    // Example Sudoku puzzle (0 represents blanks)
    int puzzle[SIZE][SIZE] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},
        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},
        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };
    // Copy puzzle into grid
    for(int i=0;i<SIZE;i++){ for(int j=0;j<SIZE;j++){ grid[i][j] = puzzle[i][j]; } }
    if(solveSudoku()) {
        cout << "Sudoku solved:\n";
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                cout << grid[i][j] << " ";
                if((j+1)%3==0) cout<<"| ";
            }
            cout << "\n";
            if((i+1)%3==0) cout << string(21,'-') << "\n";
        }
    } else {
        cout << "No solution exists.\n";
    }
}
