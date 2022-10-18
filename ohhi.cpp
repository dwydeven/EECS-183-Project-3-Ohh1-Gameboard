/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 *
 * <Dominic Wydeven, Kevin Chen>
 * <dwydeven, chkev>
 *
 * <Ohhi.cpp function implementation>
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

 /**
  * --------------------------------------------------------
  * ---------- UTILITY FUNCTIONS ---------------------------
  * --------------------------------------------------------
  */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    //i for rows, j for columns, will iterate through entire board
    int unkCount = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == UNKNOWN) {
                unkCount++;
            }
        }
    }
    return unkCount;
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row,
    int color) {
    // i used to check colun spots of given row 
    if (color == RED) {
        for (int i = 0; i < size - 2; ++i) {
            if (board[row][i] == RED) {
                if (board[row][i + 1] == RED 
                    && board[row][i + 2] == RED) {
                    return false;
                }
            }
        }
    }
    else if (color == BLUE) {
        for (int i = 0; i < size - 2; ++i) {
            if (board[row][i] == BLUE) {
                if (board[row][i + 1] == BLUE 
                    && board[row][i + 2] == BLUE) {
                    return false;
                }
            }
        }
    }

    else {
        for (int i = 0; i < size - 2; ++i) {
            if (board[row][i] == UNKNOWN) {
                if (board[row][i + 1] == UNKNOWN 
                    && board[row][i + 2] == UNKNOWN) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col,
    int color) {
    // i to check row spots for given column
    if (color == RED) {
        for (int i = 0; i < size - 2; ++i) {
            if (board[i][col] == RED) {
                if (board[i + 1][col] == RED 
                    && board[i + 2][col] == RED) {
                    return false;
                }
            }
        }
    }
    else if (color == BLUE) {
        for (int i = 0; i < size - 2; ++i) {
            if (board[i][col] == BLUE) {
                if (board[i + 1][col] == BLUE 
                    && board[i + 2][col] == BLUE) {
                    return false;
                }
            }
        }
    }
    else {
        for (int i = 0; i < size - 2; ++i) {
            if (board[i][col] == UNKNOWN) {
                if (board[i + 1][col] == UNKNOWN 
                    && board[i + 2][col] == UNKNOWN) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
    // iterates through each row for each color, each column for each color
        if (!(row_has_no_threes_of_color(board, size, i, RED))) {
            return false;
        }
        if (!(row_has_no_threes_of_color(board, size, i, BLUE))) {
            return false;
        }
        if (!(col_has_no_threes_of_color(board, size, i, RED))) {
            return false;
        }
        if (!(col_has_no_threes_of_color(board, size, i, BLUE))) {
            return false;
        }
    }
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row1,
    int row2) {
    // count to track matching
    int count = 0;
    for (int j = 0; j < size; ++j) {
        // checks for unknowns 
        if (board[row1][j] == 0 || board[row2][j] == 0) {
            return true;
        }
    }
    // if row1 == row2 the rows must be the same if no unknown ^
    if (row1 == row2) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (board[row1][i] == board[row2][i]) {
            count++;
        }
    }
    // if the count is the same as the size, the rows are the same 
    if (count == size) {
        return false;
    }
    return true;

}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col1,
    int col2) {
    // count to track matching 
    int count = 0;
    for (int j = 0; j < size; ++j) {
        // checks for unknowns 
        if (board[j][col1] == 0 || board[j][col2] == 0) {
            return true;
        }
    }
    // if columns are the same, they must be the same if no unknown 
    if (col1 == col2) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (board[i][col1] == board[i][col2]) {
            count++;
        }
    }
    // if count is the same as size, columns are equal
    if (count == size) {
        return false;
    }
    return true;

}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // goes through each row and column, not if the rows/columns are equal
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((i != j) && ((!(rows_are_different(board, size, i, j)))
                || (!(cols_are_different(board, size, i, j))))) {
                return false;
            }
        }
    }
    return true;
}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row,
    bool announce) {
    for (int i = 0; i < size - 1; i++) {
        if ((board[row][i] == board[row][i + 1]) && (board[row][i] != 0)) {
            // if two adjacent spots are equal and nonzero... 
            if (i - 1 >= 0 && board[row][i - 1] == 0) {
                // and the left spot is open and zero
                // make it the opposite of the adjacents
                board[row][i - 1] = opposite_color(board[row][i]);
                if (announce) {
                    mark_square_as(board, size, row, i - 1,
                        opposite_color(board[row][i]), true);
                }
            }
            if (i + 2 < size && board[row][i + 2] == 0) {
                // and the right spot is open and zero
                // make it the opposite of the adjacents
                board[row][i + 2] = opposite_color(board[row][i + 1]);
                if (announce) {
                    mark_square_as(board, size, row, i + 2, 
                        opposite_color(board[row][i + 1]), true);
                }
            }
        }
        if ((board[row][i] == board[row][i + 2]) && (i + 2 < size)
            && (board[row][i + 1] == 0) && (board[row][i] != 0)) {
            // if two equal non zero spots have a spot between that is 0
            // make that spot the opposte of the two spots 
            board[row][i + 1] = opposite_color(board[row][i]);
            if (announce) {
                mark_square_as(board, size, row, i + 1, 
                    opposite_color(board[row][i]), true);
            }
        }
    }
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col,
    bool announce) {
    for (int i = 0; i < size - 1; i++) {
        // if two adjacent spots are equal and nonzero... 
        if ((board[i][col] == board[i + 1][col]) && (board[i][col] != 0)) {
            // and the spot to the right is open and zero
            // make that spot the opposite of the two adjacent
            if (i - 1 >= 0 && board[i - 1][col] == 0) {
                // and the spot to the left is open and nonzero 
                // make that spot the opposite of the two adjacent
                board[i - 1][col] = opposite_color(board[i][col]);
                if (announce) {
                    mark_square_as(board, size, i - 1, col,
                        opposite_color(board[i][col]), true);
                }
            }
            if (i + 2 < size && board[i + 2][col] == 0) {
                board[i + 2][col] = opposite_color(board[i + 1][col]);
                if (announce) {
                    mark_square_as(board, size, i + 2, col, 
                        opposite_color(board[i + 1][col]), true);
                }
            }
        }
        if ((board[i][col] == board[i + 2][col]) && (i + 2 < size)
            && (board[i + 1][col] == 0) && (board[i][col] != 0)) {
            // if two equal non zero spots have a spot between that is 0
            board[i + 1][col] = opposite_color(board[i][col]);
            if (announce) {
                // make that spot the opposte of the two spots 
                mark_square_as(board, size, i + 1, col, 
                    opposite_color(board[i][col]), true);
            }
        }
    }
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row,
    bool announce) {
    // write your code here

    int checkerRed = 0;
    int checkerBlue = 0;
    for (int i = 0; i < size; ++i) {
        if (board[row][i] == RED) {
            checkerRed++;
        }
        else if (board[row][i] == BLUE) {
            checkerBlue++;
        }
    }
    // if reds take up half the row, make unknowns blue 
    if (checkerRed == size / 2) {
        for (int i = 0; i < size; ++i) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, 
                    opposite_color(RED), announce);
            }
        }
    }
    // if blues take up half the row, make unknowns red
    else if (checkerBlue == size / 2) {
        for (int i = 0; i < size; ++i) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, 
                    opposite_color(BLUE), announce);
            }
        }
    }
    return;
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col,
    bool announce) {
    int checkerRed = 0;
    int checkerBlue = 0;
    for (int i = 0; i < size; ++i) {
        if (board[i][col] == RED) {
            checkerRed++;
        }
        if (board[i][col] == BLUE) {
            checkerBlue++;
        }
    }

    if (checkerRed == size / 2) {
        // if reds take up half the column, make unknowns blue
        for (int i = 0; i < size; ++i) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, 
                    opposite_color(RED), announce);
            }
        }
    }
    else if (checkerBlue == size / 2) {
        // if blues take up half the column, make unknowns red 
        for (int i = 0; i < size; ++i) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, 
                    opposite_color(BLUE), announce);
            }
        }
    }
    return;
}


/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // a valid board with no unknowns is solved
    if (count_unknown_squares(board, size) == 0 
        && board_is_valid(board, size)) {
        return true;
    }
    return false;
}


bool check_valid_input(int size, int row_input, char col_input,
    char color_char, int& row, int& col) {
    if ((row_input < 1 || row_input > size) ||
        (toupper(col_input) < 'A' || toupper(col_input) > 'A' + size - 1)) {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    if (toupper(color_char) != RED_LETTER &&
        toupper(color_char) != BLUE_LETTER && color_char != UNKNOWN_LETTER) {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    row = row_input - 1;
    col_input = toupper(col_input);
    // Since A is 65, A = 0, B = 1, etc. 
    col = col_input - 'A';
    return true;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
    const int current_board[MAX_SIZE][MAX_SIZE],
    int size, int row, int col, int color) {
    int copy[MAX_SIZE][MAX_SIZE];
    copy_board(current_board, copy, size);
    copy[row][col] = color;
    // original board spots will be the same on the current board 
    if (original_board[row][col] == current_board[row][col]
        && original_board[row][col] != 0) {
        cout << "Sorry, original squares cannot be changed.";
        return false;
    }
    // a move on the copy that makes board_is_valid to fail is a violation
    if (!board_is_valid(copy, size)) {
        cout << "Sorry, that move violates a rule.";
        return false;
    }
    return true;
}
