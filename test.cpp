/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 *
 * <Dominic Wydeven, Kevin Chen>
 * <dwydeven, chkev >
 *
 * <Testing File for ohhi.cpp>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();

void startTests() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_solve_balance_column();
    test_board_is_solved();
    test_check_valid_input();
    test_check_valid_move();
}

// Board templates for copy and paste
string test_board_2x2[] = {"--",
                           "--"};
string test_board_4x4[] = {"----",
                           "----",
                           "----",
                           "----"};
string test_board_6x6[] = {"------",
                           "------",
                           "------",
                           "------",
                           "------",
                           "------"};
string test_board_8x8[] = {"--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------"};

//Constants for size
const int SIZE_1 = 2;
const int SIZE_2 = 4;
const int SIZE_3 = 6;
const int SIZE_4 = 8;

void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = { "XOXO",
                             "--OO",
                             "---X",
                             "--O-" };
    read_board_from_string(board, test_board_1, SIZE_2);
    cout << "Expect 8; " << count_unknown_squares(board, SIZE_2) << endl;

    //test case 2
    string test_board_2[] = {"--",
                             "--"};
    read_board_from_string(board, test_board_2, SIZE_1);
    cout << "Expect 4; " << count_unknown_squares(board, SIZE_1) << endl;

    //test case 3
    string test_board_3[] = {"OO",
                             "XX"};
    read_board_from_string(board, test_board_3, SIZE_1);
    cout << "Expect 0; " << count_unknown_squares(board, SIZE_1) << endl;

    //test case 4
    string test_board_4[] = { "--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------" };
    read_board_from_string(board, test_board_4, SIZE_4);
    cout << "Expect 64; " << count_unknown_squares(board, SIZE_4) << endl;

    //test case 5
    string test_board_5[] = { "X------X",
                           "O------O",
                           "X------X",
                           "O------O",
                           "XO----OX",
                           "O------X",
                           "X------O",
                           "O------X" };
    read_board_from_string(board, test_board_5, SIZE_4);
    cout << "Expect 46; " << count_unknown_squares(board, SIZE_4) << endl;

    //test case 6
    string test_board_6[] = { "XOXOXO",
                           "OXOXOX",
                           "XO--XO",
                           "OX-X-X",
                           "-OXXO-",
                           "------" };
    read_board_from_string(board, test_board_6, SIZE_3);
    cout << "Expect 12; " << count_unknown_squares(board, SIZE_3) << endl;

    //test case 7
    string test_board_7[] = { "XOXOXO",
                           "OXOXOX",
                           "XOOXXO",
                           "OOXXOX",
                           "XOXXOO",
                           "OOXOXX" };
    read_board_from_string(board, test_board_7, SIZE_3);
    cout << "Expect 0; " << count_unknown_squares(board, SIZE_3) << endl;


    cout << "End of testing: count_unknown_squares\n" << endl;
}

void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = { "XX",
                              "OO" };
    read_board_from_string(board, test_board_1, SIZE_1);
    cout << "Expect 1; " << 
        row_has_no_threes_of_color(board, SIZE_1, 1, RED) << endl;

    //test case 2
    string test_board_2[] = { "-XXX",
                           "----",
                           "----",
                           "----" };
    read_board_from_string(board, test_board_2, SIZE_2);
    cout << "Expect 0; " <<
        row_has_no_threes_of_color(board, SIZE_2, 0, RED) << endl;

    //test case 3
    string test_board_3[] = { "-XXX",
                           "----",
                           "----",
                           "----" };
    read_board_from_string(board, test_board_3, SIZE_2);
    cout << "Expect 1; " <<
        row_has_no_threes_of_color(board, SIZE_2, 1, RED) << endl;

    //test case 4
    string test_board_4[] = { "-XXX",
                           "----",
                           "----",
                           "----" };
    read_board_from_string(board, test_board_4, SIZE_2);
    cout << "Expect 1; " <<
        row_has_no_threes_of_color(board, SIZE_2, 0, BLUE) << endl;

    //test case 5
    string test_board_5[] = { "-OOO",
                           "----",
                           "----",
                           "----" };
    read_board_from_string(board, test_board_5, SIZE_2);
    cout << "Expect 0; " <<
        row_has_no_threes_of_color(board, SIZE_2, 0, BLUE) << endl;

    //test case 6
    string test_board_6[] = { "------",
                               "------",
                               "------",
                               "------",
                               "------",
                               "---XXX" };
    read_board_from_string(board, test_board_6, SIZE_3);
    cout << "Expect 0; " <<
        row_has_no_threes_of_color(board, SIZE_3, 5, RED) << endl;

    //test case 7
    string test_board_7[] = { "------",
                               "------",
                               "------",
                               "------",
                               "------",
                               "---XXX" };
    read_board_from_string(board, test_board_7, SIZE_3);
    cout << "Expect 1; " <<
        row_has_no_threes_of_color(board, SIZE_3, 5, BLUE) << endl;

    //test case 8
    string test_board_8[] = { "------",
                               "------",
                               "XOOOXX",
                               "------",
                               "------",
                               "---XXX" };
    read_board_from_string(board, test_board_8, SIZE_3);
    cout << "Expect 0; " <<
        row_has_no_threes_of_color(board, SIZE_3, 2, BLUE) << endl;

    //test case 9
    string test_board_9[] = { "--------",
                               "--------",
                               "--------",
                               "--------",
                               "--------",
                               "-XXXX---",
                               "--------",
                               "--------" };
    read_board_from_string(board, test_board_9, SIZE_4);
    cout << "Expect 0; " <<
        row_has_no_threes_of_color(board, SIZE_4, 5, RED) << endl;

    //test case 10
    string test_board_10[] = { "OXOXOXOX",
                               "XOXOXOXO",
                               "OOXXOOXX",
                               "XXOOXXOO",
                               "XOXXOXOO",
                               "OXOOXOXX",
                               "OOXXOXOX",
                               "OOOXXXOX" };
    read_board_from_string(board, test_board_10, SIZE_4);
    cout << "Expect 1; " <<
        row_has_no_threes_of_color(board, SIZE_4, 8, RED) << endl;

    cout << "End of testing: row_has_no_threes_of_color\n" << endl;
}

void test_col_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = { "XO",
                              "XO" };
    read_board_from_string(board, test_board_1, SIZE_1);
    cout << "Expect 1; " << 
        col_has_no_threes_of_color(board, SIZE_1, 1, BLUE) << endl;

    //test case 2
    string test_board_2[] = { "---O",
                               "---O",
                               "---O",
                               "----" };
    read_board_from_string(board, test_board_2, SIZE_2);
    cout << "Expect 0; " <<
        col_has_no_threes_of_color(board, SIZE_2, 3, BLUE) << endl;

    //test case 3
    string test_board_3[] = { "---O",
                           "---O",
                           "---O",
                           "----" };
    read_board_from_string(board, test_board_3, SIZE_2);
    cout << "Expect 1; " <<
        col_has_no_threes_of_color(board, SIZE_2, 3, RED) << endl;

    //test case 4
    string test_board_4[] = { "---O",
                           "---O",
                           "---O",
                           "----" };
    read_board_from_string(board, test_board_4, SIZE_2);
    cout << "Expect 1; " <<
        col_has_no_threes_of_color(board, SIZE_2, 2, BLUE) << endl;

    //test case 5
    string test_board_5[] = { "---O",
                           "---O",
                           "---O",
                           "---O" };
    read_board_from_string(board, test_board_5, SIZE_2);
    cout << "Expect 0; " <<
        col_has_no_threes_of_color(board, SIZE_2, 3, BLUE) << endl;
    
    //test case 6
    string test_board_6[] = { "X-----",
                               "X-----",
                               "X-----",
                               "------",
                               "------",
                               "------" };
    read_board_from_string(board, test_board_6, SIZE_3);
    cout << "Expect 0; " <<
        col_has_no_threes_of_color(board, SIZE_3, 0, RED) << endl;

    //test case 7
    string test_board_7[] = { "OXOXOXOX",
                               "XOXOXOXO",
                               "OOXXOOXX",
                               "XXOOXXOO",
                               "XOXXOXOO",
                               "OXOOXOXX",
                               "OOXXOXOX",
                               "OOOXXXOX" };
    read_board_from_string(board, test_board_7, SIZE_4);
    cout << "Expect 0; " <<
        col_has_no_threes_of_color(board, SIZE_4, 0, BLUE) << endl;

    //test case 8
    string test_board_8[] = { "OXOXOXOX",
                               "XOXOXOXO",
                               "OOXXOOXX",
                               "XXOOXXOO",
                               "XOXXOXOO",
                               "OXOOXOXX",
                               "OOXXOXOX",
                               "OOOXXXOX" };
    read_board_from_string(board, test_board_8, SIZE_4);
    cout << "Expect 1; " <<
        col_has_no_threes_of_color(board, SIZE_4, 0, RED) << endl;

    //test case 9
    string test_board_9[] = { "OXOXOXOX",
                               "XOXOXOXO",
                               "OOXXOOXX",
                               "XXOOXXOO",
                               "XOXXOXOO",
                               "OXOOXOXX",
                               "OOXXOXOX",
                               "OOOXXXOX" };
    read_board_from_string(board, test_board_9, SIZE_4);
    cout << "Expect 0; " <<
        col_has_no_threes_of_color(board, SIZE_4, 7, RED) << endl;

    //test case 10
    string test_board_10[] = { "OXOXOXOX",
                               "XOXOXOXO",
                               "OOXXOOXX",
                               "XXOOXXOO",
                               "XOXXOXOO",
                               "OXOOXOXX",
                               "OOXXOXOX",
                               "OOOXXXOX" };
    read_board_from_string(board, test_board_10, SIZE_4);
    cout << "Expect 1; " <<
        col_has_no_threes_of_color(board, SIZE_4, 7, BLUE) << endl;

    cout << "End of testing: col_has_no_threes_of_color\n" << endl;
}

void test_board_has_no_threes() {
    int board[MAX_SIZE][MAX_SIZE];
    
    //test case 1
    string test_board_1[] = { "XO",
                              "XO" };
    read_board_from_string(board, test_board_1, SIZE_1);
    cout << "Expect 1; " << board_has_no_threes(board, SIZE_1) << endl;

    //test case 2
    string test_board_2[] = { "X---",
                               "X---",
                               "X---",
                               "----" };
    read_board_from_string(board, test_board_2, SIZE_2);
    cout << "Expect 0; " << board_has_no_threes(board, SIZE_2) << endl;

    //test case 3
    string test_board_3[] = {  "O---",
                               "X--O",
                               "X--O",
                               "O--O" };
    read_board_from_string(board, test_board_3, SIZE_2);
    cout << "Expect 0; " << board_has_no_threes(board, SIZE_2) << endl;

    //test case 4
    string test_board_4[] = { "O---",
                               "X--O",
                               "X--O",
                               "OXXX" };
    read_board_from_string(board, test_board_4, SIZE_2);
    cout << "Expect 0; " << board_has_no_threes(board, SIZE_2) << endl;

    //test case 5
    string test_board_5[] = {  "OXXO",
                               "XOXO",
                               "XOOX",
                               "OXOX" };
    read_board_from_string(board, test_board_5, SIZE_2);
    cout << "Expect 1; " << board_has_no_threes(board, SIZE_2) << endl;

    //test case 6
    string test_board_6[] = {  "O--O-O",
                               "O-X-XX",
                               "X-OX-X",
                               "X-O--O",
                               "O-X--O",
                               "XX-O-X" };
    read_board_from_string(board, test_board_6, SIZE_3);
    cout << "Expect 1; " << board_has_no_threes(board, SIZE_3) << endl;

    //test case 7
    string test_board_7[] = {  "XXXOOO",
                               "X-XOOO",
                               "X-OX-O",
                               "O-OXXX",
                               "OOO--X",
                               "OOOXXX" };
    read_board_from_string(board, test_board_7, SIZE_3);
    cout << "Expect 0; " << board_has_no_threes(board, SIZE_3) << endl;

    //test case 8
    string test_board_8[] =   {"XXOOXXOO",
                               "OOXXOOXX",
                               "XOXOXOXO",
                               "OXOXOXOX",
                               "XXOXOOXO",
                               "OOXOXXOX",
                               "XOOXOOXX",
                               "OXXOXXOO" };
    read_board_from_string(board, test_board_8, SIZE_4);
    cout << "Expect 1; " << board_has_no_threes(board, SIZE_4) << endl;

    //test case 9
    string test_board_9[] =   {"XXOOXXOO",
                               "XOXXXOOO",
                               "XOXOXOXO",
                               "OXOXOXOX",
                               "XXOXOOXO",
                               "OOOOXXXX",
                               "OOOXOXXX",
                               "OOXXXOOX"};
    read_board_from_string(board, test_board_9, SIZE_4);
    cout << "Expect 0; " << board_has_no_threes(board, SIZE_4) << endl;

    cout << "End of testing: board_has_no_threes\n" << endl;
}

void test_rows_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = { "XO",
                              "X-" };
    read_board_from_string(board, test_board_1, SIZE_1);
    cout << "Expect 1; " << rows_are_different(board, SIZE_1, 0, 1) << endl;

    //test case 2
    string test_board_2[] = { "XO",
                              "XO" };
    read_board_from_string(board, test_board_2, SIZE_1);
    cout << "Expect 0; " << rows_are_different(board, SIZE_1, 0, 1) << endl;

    //test case 3
    string test_board_3[] =  { "XOXO",
                               "OXOX",
                               "XOXO",
                               "OXOX" };
    read_board_from_string(board, test_board_3, SIZE_2);
    cout << "Expect 1; " << rows_are_different(board, SIZE_2, 0, 1) << endl;

    //test case 4
    string test_board_4[] = { "XOXO",
                               "OXOX",
                               "XOXO",
                               "OXOX" };
    read_board_from_string(board, test_board_4, SIZE_2);
    cout << "Expect 0; " << rows_are_different(board, SIZE_2, 0, 2) << endl;

    //test case 5
    string test_board_5[] = { "XOXO",
                               "OXOX",
                               "XOXO",
                               "OXO-" };
    read_board_from_string(board, test_board_5, SIZE_2);
    cout << "Expect 1; " << rows_are_different(board, SIZE_2, 1, 3) << endl;

    //test case 5.5
    cout << "NEW TEST" << endl;
    string test_board_12[] = { "OOXO",
                               "OOXO",
                               "OOXO",
                               "OXO-" };
    read_board_from_string(board, test_board_12, SIZE_2);
    cout << "Expect 0; " << rows_are_different(board, SIZE_2, 0, 2) << endl;

    //test case 6
    string test_board_6[] ={ "------",
                             "XXOOXX",
                             "------",
                             "XXOOXX",
                             "------",
                             "------" };
    read_board_from_string(board, test_board_6, SIZE_3);
    cout << "Expect 0; " << rows_are_different(board, SIZE_3, 1, 3) << endl;

    //test case 7
    string test_board_7[] = { "------",
                             "XXOOXX",
                             "------",
                             "XXOOXX",
                             "------",
                             "------" };
    read_board_from_string(board, test_board_7, SIZE_3);
    cout << "Expect 1; " << rows_are_different(board, SIZE_3, 2, 3) << endl;

    //test case 8
    string test_board_8[] =   { "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "------XX" };
    read_board_from_string(board, test_board_8, SIZE_4);
    cout << "Expect 1; " << rows_are_different(board, SIZE_4, 6,7) << endl;

    //test case 9
    string test_board_9[] = { "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "OOXXOOXX",
                                "OOXXOOXX" };
    read_board_from_string(board, test_board_9, SIZE_4);
    cout << "Expect 0; " << rows_are_different(board, SIZE_4, 6, 7) << endl;

    //test case 10
    string test_board_10[] = { "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "OOXXOOXX",
                                "OOXXOOXX" };
    read_board_from_string(board, test_board_10, SIZE_4);
    cout << "Expect 1; " << rows_are_different(board, SIZE_4, 6, 5) << endl;

    //test case 11
    string test_board_11[] = { "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "------XX",
                                "OOXXOOXX",
                                "OOXXOOXX" };
    read_board_from_string(board, test_board_11, SIZE_4);
    cout << "Expect 0; " << rows_are_different(board, SIZE_4, 7, 6) << endl;

    cout << "End of testing: rows_are_different\n" << endl;
}

void test_cols_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = { "OO",
                              "XX" };
    read_board_from_string(board, test_board_1, SIZE_1);
    cout << "Expect 0; " << cols_are_different(board, SIZE_1, 0, 1) << endl;

    //test case 2
    string test_board_2[] = { "OO",
                          "X-" };
    read_board_from_string(board, test_board_2, SIZE_1);
    cout << "Expect 1; " << cols_are_different(board, SIZE_1, 0, 1) << endl;

    //test case 3
    string test_board_3[] = { "O-",
                              "X-" };
    read_board_from_string(board, test_board_3, SIZE_1);
    cout << "Expect 1; " << cols_are_different(board, SIZE_1, 0, 1) << endl;
    
    //test case 4
    string test_board_4[] =   { "XOX-",
                                "OXO-",
                                "OOO-",
                                "XOX-" };
    read_board_from_string(board, test_board_4, SIZE_2);
    cout << "Expect 1; " << cols_are_different(board, SIZE_2, 0, 1) << endl;

    //test case 5
    string test_board_5[] =   { "XOX-",
                                "OXO-",
                                "OOO-",
                                "XOX-" };
    read_board_from_string(board, test_board_5, SIZE_2);
    cout << "Expect 0; " << cols_are_different(board, SIZE_2, 0, 2) << endl;

    //test case 6
    string test_board_6[] =  { "XO----",
                               "XO----",
                               "XO----",
                               "XO----",
                               "XO----",
                               "XO----" };
    read_board_from_string(board, test_board_6, SIZE_3);
    cout << "Expect 1; " << cols_are_different(board, SIZE_3, 0, 2) << endl;

    //test case 7
    string test_board_7[] = {  "XX----",
                               "XX----",
                               "XX----",
                               "XX----",
                               "XX----",
                               "X-----" };
    read_board_from_string(board, test_board_7, SIZE_3);
    cout << "Expect 1; " << cols_are_different(board, SIZE_3, 0, 1) << endl;

    //test case 8
    string test_board_8[] = { "XOXOXOXO",
                               "--------",
                               "XOXOXOXO",
                               "--------",
                               "--------",
                               "--------",
                               "--------",
                               "--------" };
    read_board_from_string(board, test_board_8, SIZE_4);
    cout << "Expect 1; " << cols_are_different(board, SIZE_4, 0, 2) << endl;

    //test case 9
    string test_board_9[] = {  "XOXOXOOX",
                               "O-O----O",
                               "XOXOXOOX",
                               "O-O----O",
                               "O-O----O",
                               "X-X----X",
                               "X-X----X",
                               "O-O----O" };
    read_board_from_string(board, test_board_9, SIZE_4);
    cout << "Expect 0; " << cols_are_different(board, SIZE_4, 0, 2) << endl;

    //test case 10
    string test_board_10[] = { "XOXOXOOX",
                               "O-O----O",
                               "XOXOXOOX",
                               "O-O----O",
                               "O-O----O",
                               "X-X----X",
                               "X-X----X",
                               "O-O----O" };
    read_board_from_string(board, test_board_10, SIZE_4);
    cout << "Expect 0; " << cols_are_different(board, SIZE_4, 0, 7) << endl;

    //test case 11
    string test_board_11[] = { "XOXOXOOX",
                               "O-O----O",
                               "XOXOXOOX",
                               "O-O----O",
                               "O-O----O",
                               "X-X----X",
                               "X-X----X",
                               "O-O----O" };
    read_board_from_string(board, test_board_11, SIZE_4);
    cout << "Expect 0; " << cols_are_different(board, SIZE_4, 7, 2) << endl;

    //test case 12
    string test_board_12[] = { "XOXOXOOX",
                               "O-O----O",
                               "XOXOXOOX",
                               "O-O----O",
                               "O-O----O",
                               "X-X----X",
                               "X-X----X",
                               "O-O----O" };
    read_board_from_string(board, test_board_12, SIZE_4);
    cout << "Expect 1; " << cols_are_different(board, SIZE_4, 7, 6) << endl;

    //test case 13
    string test_board_13[] = { "XOXOXOOX",
                               "O-O----O",
                               "XOXOXOOX",
                               "O-O----O",
                               "O-O----O",
                               "X-X----X",
                               "X-X----X",
                               "O-O----O" };
    read_board_from_string(board, test_board_13, SIZE_4);
    cout << "Expect 1; " << cols_are_different(board, SIZE_4, 6, 6) << endl;

    //test case 14
    string test_board_14[] = { "O-O-",
                              "O-O-",
                              "X-X-",
                              "O-O-" };
    read_board_from_string(board, test_board_14, SIZE_2);
    cout << "Expect 0; " << cols_are_different(board, SIZE_2, 0, 2) << endl;

    cout << "End of testing: cols_are_different\n" << endl;
}

void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] =   { "XX",
                                "XX" };
    read_board_from_string(board, test_board_1, SIZE_1);
    cout << "Expect 0; " << board_has_no_duplicates(board, SIZE_1) << endl;

    //test case 2
    string test_board_2[] = { "XO",
                              "OX" };
    read_board_from_string(board, test_board_2, SIZE_1);
    cout << "Expect 1; " << board_has_no_duplicates(board, SIZE_1) << endl;

    //test case 3
    string test_board_3[] = { "XXOO",
                              "XXOO",
                              "XXO-",
                              "OXOO" };
    read_board_from_string(board, test_board_3, SIZE_2);
    cout << "Expect 0; " << board_has_no_duplicates(board, SIZE_2) << endl;

    //test case 4
    string test_board_4[] = { "OXXO",
                              "XXOO",
                              "OOXX",
                              "XOOX" };
    read_board_from_string(board, test_board_4, SIZE_2);
    cout << "Expect 1; " << board_has_no_duplicates(board, SIZE_2) << endl;

    //test case 5
    string test_board_5[] = { "------",
                              "------",
                              "------",
                              "------",
                              "XOXOXO",
                              "XOXOXO" };
    read_board_from_string(board, test_board_5, SIZE_3);
    cout << "Expect 0; " << board_has_no_duplicates(board, SIZE_3) << endl;

    //test case 6
    string test_board_6[] = { "OX-XX-",
                              "OX-XX-",
                              "XO-OO-",
                              "OX-OO-",
                              "XOXXX-",
                              "XOXOOX" };
    read_board_from_string(board, test_board_6, SIZE_3);
    cout << "Expect 0; " << board_has_no_duplicates(board, SIZE_3) << endl;

    //test case 7
    string test_board_7[] = { "XOXOXOXO",
                              "OXOXOXOX",
                              "OOXXOOXX",
                              "XXOOXXOO",
                              "XOOXOOXX",
                              "OXXOXXOO",
                              "OOXOXOXX",
                              "XXOXOXOO" };
    read_board_from_string(board, test_board_7, SIZE_4);
    cout << "Expect 0; " << board_has_no_duplicates(board, SIZE_4) << endl;

    //test case 8
    string test_board_8[] = { "XOXOXOXO",
                              "OXOXOXOX",
                              "OOXXOOXX",
                              "XXOOXXOO",
                              "XOOXOOXX",
                              "OXXOXXOO",
                              "OOXOXOXX",
                              "OOXOXOXX" };
    read_board_from_string(board, test_board_8, SIZE_4);
    cout << "Expect 0; " << board_has_no_duplicates(board, SIZE_4) << endl;

    //test case 9
    string test_board_9[] = { "XOXOXOXO",
                              "OXOXOXOX",
                              "OOXXOOXX",
                              "XXOOXXOO",
                              "XOOXOOXX",
                              "OXXOXXO-",
                              "OOXOXOXX",
                              "OOXOXOXX" };
    read_board_from_string(board, test_board_9, SIZE_4);
    cout << "Expect 0; " << board_has_no_duplicates(board, SIZE_4) << endl;

    //test case 10
    string test_board_10[] = { "XOXOXOXO",
                               "OXOXOXOX",
                               "OOXXOOXX",
                               "XXOOXXOO",
                               "XOOXOOXX",
                               "OXXOXXO-",
                               "OOXOXOXX",
                               "OOXOXOX-" };
    read_board_from_string(board, test_board_10, SIZE_4);
    cout << "Expect 0; " << board_has_no_duplicates(board, SIZE_4) << endl;

    //test case 11
    string test_board_11[] = { "O-O-",
                              "O-O-",
                              "X-X-",
                              "O-O-" };
    read_board_from_string(board, test_board_11, SIZE_2);
    cout << "Expect 0; " << board_has_no_duplicates(board, SIZE_2) << endl;

    //test case 12
    string test_board_12[] = { "XOXOXO",
                               "OXOXOX",
                               "OOXXOX",
                               "OXOOXX",
                               "XXOOXO",
                               "XOXXOO" };
    read_board_from_string(board, test_board_12, SIZE_3);
    cout << "Expect 1; " << board_has_no_duplicates(board, SIZE_3) << endl;

    cout << "End of testing: board_has_no_duplicates\n" << endl;
}

void test_solve_three_in_a_row() {
    int board[MAX_SIZE][MAX_SIZE];   

    //test case 1 
    string test_board_1[] = {  "-X-X",
                               "--XX",
                               "OO--",
                               "X--X" };
    read_board_from_string(board, test_board_1, SIZE_2);
    solve_three_in_a_row(board, SIZE_2, 0, true);
    print_board(board, SIZE_2);

    //test case 2   
    string test_board_2[] = {  "-X-X",
                               "--XX",
                               "OO--",
                               "X--X" };
    read_board_from_string(board, test_board_2, SIZE_2);
    solve_three_in_a_row(board, SIZE_2, 1, true);
    print_board(board, SIZE_2);

    //test case 3  
    string test_board_3[] = {  "-X-X",
                               "--XX",
                               "OO--",
                               "X--X" };
    read_board_from_string(board, test_board_3, SIZE_2);
    solve_three_in_a_row(board, SIZE_2, 2, true);
    print_board(board, SIZE_2);


    //test case 4
    string test_board_4[] = { "-X-X",
                               "--XX",
                               "OO--",
                               "X--X" };
    read_board_from_string(board, test_board_4, SIZE_2);
    solve_three_in_a_row(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 5
    string test_board_5[] = { "X-X-X-",
                                "-O-O-O",
                                "XX--X-",
                                "-OO--O",
                                "XOX-XO",
                                "-OX-X-" };
    read_board_from_string(board, test_board_5, SIZE_3);
    solve_three_in_a_row(board, SIZE_3, 0, true);
    print_board(board, SIZE_3);

    //test case 6
    string test_board_6[] = { "X-X-X-",
                                "-O-O-O",
                                "XX--X-",
                                "-OO--O",
                                "XOX-XO",
                                "-OX-X-" };
    read_board_from_string(board, test_board_6, SIZE_3);
    solve_three_in_a_row(board, SIZE_3, 1, true);
    print_board(board, SIZE_3);

    //test case 7
    string test_board_7[] = { "X-X-X-",
                                "-O-O-O",
                                "XX--X-",
                                "-OO--O",
                                "XOX-XO",
                                "-OX-X-" };
    read_board_from_string(board, test_board_7, SIZE_3);
    solve_three_in_a_row(board, SIZE_3, 3, true);
    print_board(board, SIZE_3);

    //test case 8
    string test_board_8[] = { "X-X-X-",
                                "-O-O-O",
                                "XX--X-",
                                "-OO--O",
                                "XOX-XO",
                                "-OX-X-" };
    read_board_from_string(board, test_board_8, SIZE_3);
    solve_three_in_a_row(board, SIZE_3, 5, true);
    print_board(board, SIZE_3);

    //test case 9
    string test_board_9[] = { "-XO-OXO-",
                               "--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------",
                           "--------" };
    read_board_from_string(board, test_board_9, SIZE_4);
    solve_three_in_a_row(board, SIZE_4, 0, true);
    print_board(board, SIZE_4);

    //test case 10
    string test_board_10[] = { "----",
                           "----",
                           "----",
                           "----" };
    read_board_from_string(board, test_board_10, SIZE_2);
    solve_three_in_a_row(board, SIZE_2, 0, true);
    print_board(board, SIZE_2);


    //test case 11
    string test_board_11[] = { "O-OXX-",
                               "-O-O-O",
                               "XX--X-",
                               "-OO--O",
                               "XOX-XO",
                               "-OX-X-" };
    read_board_from_string(board, test_board_11, 6);
    solve_three_in_a_row(board, SIZE_3, 0, true);
    print_board(board, SIZE_3);

    //test case 12
    string test_board_12[] = { "-OO-",
                       "----",
                       "----",
                       "----" };
    read_board_from_string(board, test_board_12, SIZE_2);
    solve_three_in_a_row(board, SIZE_2, 0, true);
    print_board(board, SIZE_2);

    cout << "End of testing: solve_three_in_a_row\n" << endl;
}

void test_solve_three_in_a_column() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = { "---X",
                              "---X",
                              "----",
                              "----" };
    read_board_from_string(board, test_board_1, SIZE_2);
    solve_three_in_a_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 2
    string test_board_2[] = { "---X",
                              "----",
                              "---X",
                              "----" };
    read_board_from_string(board, test_board_2, SIZE_2);
    solve_three_in_a_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 3
    string test_board_3[] = { "---X",
                              "---X",
                              "----",
                              "---X" };
    read_board_from_string(board, test_board_3, SIZE_2);
    solve_three_in_a_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 4
    string test_board_4[] = { "---X",
                              "----",
                              "----",
                              "---X" };
    read_board_from_string(board, test_board_4, SIZE_2);
    solve_three_in_a_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 5
    string test_board_5[] = { "---X",
                              "---O",
                              "---O",
                              "---X" };
    read_board_from_string(board, test_board_5, SIZE_2);
    solve_three_in_a_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 6
    string test_board_6[] = { "----",
                              "---O",
                              "---O",
                              "----" };
    read_board_from_string(board, test_board_6, SIZE_2);
    solve_three_in_a_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 7
    string test_board_7[] = { "----",
                              "---O",
                              "---O",
                              "----" };
    read_board_from_string(board, test_board_7, SIZE_2);
    solve_three_in_a_column(board, SIZE_2, 2, true);
    print_board(board, SIZE_2);

    //test case 8
    string test_board_8[] = { "O-------",
                              "X-------",
                              "--------",
                              "X-------",
                              "X-------",
                              "--------",
                              "O-------",
                              "O-------" };
    read_board_from_string(board, test_board_8, SIZE_4);
    solve_three_in_a_column(board, SIZE_4, 0, true);
    print_board(board, SIZE_4);

    cout << "End of testing: solve_three_in_a_column\n" << endl;
}

void test_solve_balance_row() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = { "-X",
                              "O-" };
    read_board_from_string(board, test_board_1, SIZE_1);
    solve_balance_row(board, SIZE_1, 0, true);
    print_board(board, SIZE_1);

    //test case 2
    string test_board_2[] = { "--XX",
                              "----",
                              "----",
                              "----" };
    read_board_from_string(board, test_board_2, SIZE_2);
    solve_balance_row(board, SIZE_2, 0, true);
    print_board(board, SIZE_2);

    //test case 3
    string test_board_3[] = { "X--X",
                              "----",
                              "----",
                              "----" };
    read_board_from_string(board, test_board_3, SIZE_2);
    solve_balance_row(board, SIZE_2, 0, true);
    print_board(board, SIZE_2);

    //test case 4
    string test_board_4[] = { "X-X-",
                              "----",
                              "----",
                              "----" };
    read_board_from_string(board, test_board_4, SIZE_2);
    solve_balance_row(board, SIZE_2, 0, true);
    print_board(board, SIZE_2);

    //test case 5
    string test_board_5[] = { "X-XX",
                              "----",
                              "----",
                              "----" };
    read_board_from_string(board, test_board_5, SIZE_2);
    solve_balance_row(board, SIZE_2, 0, true);
    print_board(board, SIZE_2);

    //test case 6
    string test_board_6[] = { "---X",
                              "----",
                              "----",
                              "----" };
    read_board_from_string(board, test_board_6, SIZE_2);
    solve_balance_row(board, SIZE_2, 0, true);
    print_board(board, SIZE_2);

    //test case 7
    string test_board_7[] = { "X--X",
                              "----",
                              "----",
                              "----" };
    read_board_from_string(board, test_board_7, SIZE_2);
    solve_balance_row(board, SIZE_2, 1, true);
    print_board(board, SIZE_2);

    cout << "End of testing: solve_balance_row\n" << endl;
}

void test_solve_balance_column() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = { "X-",
                              "-O" };
    read_board_from_string(board, test_board_1, SIZE_1);
    solve_balance_column(board, SIZE_1, 1, true);
    print_board(board, SIZE_1);

    //test case 2
    string test_board_2[] = { "X-",
                              "-O" };
    read_board_from_string(board, test_board_2, SIZE_1);
    solve_balance_column(board, SIZE_1, 0, true);
    print_board(board, SIZE_1);

    //test case 3
    string test_board_3[] = { "---X",
                              "---X",
                              "----",
                              "----" };
    read_board_from_string(board, test_board_3, SIZE_2);
    solve_balance_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 4
    string test_board_4[] = { "---X",
                              "----",
                              "---X",
                              "----" };
    read_board_from_string(board, test_board_4, SIZE_2);
    solve_balance_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 5
    string test_board_5[] = { "---X",
                              "----",
                              "----",
                              "---X" };
    read_board_from_string(board, test_board_5, SIZE_2);
    solve_balance_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 6
    string test_board_6[] = { "----",
                              "----",
                              "----",
                              "---X" };
    read_board_from_string(board, test_board_6, SIZE_2);
    solve_balance_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 7
    string test_board_7[] = { "---X",
                              "----",
                              "---X",
                              "---X" };
    read_board_from_string(board, test_board_7, SIZE_2);
    solve_balance_column(board, SIZE_2, 3, true);
    print_board(board, SIZE_2);

    //test case 8
    string test_board_8[] = { "---X",
                              "----",
                              "----",
                              "---X" };
    read_board_from_string(board, test_board_8, SIZE_2);
    solve_balance_column(board, SIZE_2, 2, true);
    print_board(board, SIZE_2);

    //test case 9
    string test_board_9[] = { "O--O",
                              "O--X",
                              "-XXO",
                              "-XOX" };
    read_board_from_string(board, test_board_9, SIZE_2);
    solve_balance_column(board, SIZE_2, 1, true);
    print_board(board, SIZE_2);

    cout << "End of testing: solve_balance_column\n" << endl;
}

void test_board_is_solved() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = { "XO",
                              "XO" };
    read_board_from_string(board, test_board_1, SIZE_1);
    cout << "Expect 0: " << board_is_solved(board, SIZE_1) << endl;

    //test case 2
    string test_board_2[] = { "XOXO",
                              "OXOX",
                              "OOXX",
                              "XXOO" };
    read_board_from_string(board, test_board_2, SIZE_2);
    cout << "Expect 1: " << board_is_solved(board, SIZE_2) << endl;

    //test case 3
    string test_board_3[] = { "XOXO",
                          "OXOX",
                          "OOXX",
                          "XXO-" };
    read_board_from_string(board, test_board_3, SIZE_2);
    cout << "Expect 0: " << board_is_solved(board, SIZE_2) << endl;


    //test case 4
    string test_board_4[] = { "XOXO",
                              "OXOX",
                              "OOXX",
                              "OOXX" };
    read_board_from_string(board, test_board_4, SIZE_2);
    cout << "Expect 0: " << board_is_solved(board, SIZE_2) << endl;

    //test case 5
    string test_board_5[] = { "XOXOXO",
                              "OXOXOX",
                              "OOXXOX",
                              "XXOOXO",
                              "OXOOXX",
                              "XOXXOO" };
    read_board_from_string(board, test_board_5, SIZE_3);
    cout << "Expect 1: " << board_is_solved(board, SIZE_3) << endl;

    //test case 6
    string test_board_6[] = { "XO-OXO",
                              "OXOXOX",
                              "OOXXOX",
                              "XXOOXO",
                              "OXOOXX",
                              "XOXXOO" };
    read_board_from_string(board, test_board_6, SIZE_3);
    cout << "Expect 0: " << board_is_solved(board, SIZE_3) << endl;

    //test case 7
    string test_board_7[] =  { "XXOOXXOO",
                               "OOXXOOXX",
                               "XOXOXOXO",
                               "OXOXOXOX",
                               "XOOXOOXX",
                               "OXXOXXOO",
                               "XOXXOXOO",
                               "OXOOXOXX" };
    read_board_from_string(board, test_board_7, SIZE_4);
    cout << "Expect 1: " << board_is_solved(board, SIZE_4) << endl;

    //test case 8
    string test_board_8[] = {  "XXOOXXOO",
                               "OOXXOOXX",
                               "XOXOXOXO",
                               "OXOXOXOX",
                               "XOOXOOXX",
                               "OXXOXXOO",
                               "XOXXOXOO",
                               "OXXOXOXO" };
    read_board_from_string(board, test_board_8, SIZE_4);
    cout << "Expect 0: " << board_is_solved(board, SIZE_4) << endl;

    cout << "End of testing: board_is_solved\n" << endl;
}

void test_check_valid_input() {

    //set to 99 to see if changed properly through pass-by-reference
    int row = 99;
    int col = 99;

    //test case 1
    cout << "Expect 1: row = 0; col = 0 --> "
        << check_valid_input(4, 1, 'a', 'O', row, col) << ": "
        << "row = " << row << "; col = " << col << endl << endl;

    //test case 2
    cout << "Expect invalid: "
         << check_valid_input(4, 0, 'a', 'x', row, col) << endl;

    //test case 3
    cout << "Expect invalid: "
        << check_valid_input(4, 1, 'e', 'o', row, col) << endl;

    //test case 4
    cout << "Expect invalid: "
        << check_valid_input(4, 5, 'a', 'O', row, col) << endl;

    //test case 5
    cout << "Expect invalid: "
        << check_valid_input(4, -1, 'a', 'X', row, col) << endl;

    //test case 6
    cout << "Expect invalid: "
        << check_valid_input(4, 0, 'a', 'b', row, col) << endl;

    //test case 7
    cout << "Expect 1: row = 7; col = 7 --> "
        << check_valid_input(8, 8, 'h', 'O', row, col) << ": "
        << "row = " << row << "; col = " << col << endl << endl;

    //test case 7
    cout << "Expect 1: row = 2; col = 2 --> "
        << check_valid_input(6, 3, 'c', 'x', row, col) << ": "
        << "row = " << row << "; col = " << col << endl << endl;

    cout << "End of testing: check_valid_input\n" << endl;
}

void test_check_valid_move() {
    int og_board[MAX_SIZE][MAX_SIZE];
    int curr_board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_og_board_1[] = { "-OX-",
                                 "---X",
                                 "-O--",
                                 "X--O" };
    string test_curr_board_1[] = {"OOXX",
                                  "OO-X",
                                  "---O",
                                  "X--O" };
    read_board_from_string(og_board, test_og_board_1, SIZE_2);
    read_board_from_string(curr_board, test_curr_board_1, SIZE_2);
    cout << "Expect 0, violaltion of rule: " <<
        check_valid_move(og_board, curr_board, SIZE_2, 2, 2, RED) << endl;

    //test case 2
    string test_og_board_2[] =     { "-OX-",
                                     "---X",
                                     "-O--",
                                     "X--O" };
    string test_curr_board_2[] =  {  "OOXX",
                                     "OO-X",
                                     "---O",
                                     "X--O" };
    read_board_from_string(og_board, test_og_board_2, SIZE_2);
    read_board_from_string(curr_board, test_curr_board_2, SIZE_2);
    cout << " Expect 0, original squares cannot be changed: " <<
        check_valid_move(og_board, curr_board, SIZE_2, 0, 3, BLUE) << endl;

    //test case 3
    string test_og_board_3[] = { "-OX-",
                                 "---X",
                                 "-O--",
                                 "X--O" };
    string test_curr_board_3[] = { "OOXX",
                                     "OO-X",
                                     "---O",
                                     "X--O" };
    read_board_from_string(og_board, test_og_board_3, SIZE_2);
    read_board_from_string(curr_board, test_curr_board_3, SIZE_2);
    cout << " Expect 0, that move violates a rule: " <<
        check_valid_move(og_board, curr_board, SIZE_2, 1, 2, RED) << endl;

    //test case 4
    string test_og_board_4[] = { "-OX-",
                             "---X",
                             "-O--",
                             "X--O" };
    string test_curr_board_4[] = { "-OX-",
                                     "---X",
                                     "-O--",
                                     "X--O" };
    read_board_from_string(og_board, test_og_board_4, SIZE_2);
    read_board_from_string(curr_board, test_curr_board_4, SIZE_2);
    cout << " Expect 0, original squares cannot be changed: " <<
        check_valid_move(og_board, curr_board, SIZE_2, 1, 3, RED) << endl;

    //test case 5
    string test_og_board_5[] = {  "-OX-",
                                  "---X",
                                  "-O--",
                                  "X--O" };
    string test_curr_board_5[] = {"-OX-",
                                  "--XX",
                                  "-OO-",
                                  "X--O" };
    read_board_from_string(og_board, test_og_board_5, SIZE_2);
    read_board_from_string(curr_board, test_curr_board_5, SIZE_2);
    cout << "Expect 0, violation of rule: " <<
        check_valid_move(og_board, curr_board, SIZE_2, 0, 2, RED) << endl;

    //test case 6
    string test_og_board_6[] = { "-OX-",
                                  "---X",
                                  "-O--",
                                  "X--O" };
    string test_curr_board_6[] = { "-OX-",
                                  "--XX",
                                  "-OO-",
                                  "X--O" };
    read_board_from_string(og_board, test_og_board_6, SIZE_2);
    read_board_from_string(curr_board, test_curr_board_6, SIZE_2);
    cout << "Expect 1: " <<
        check_valid_move(og_board, curr_board, SIZE_2, 0, 0, RED) << endl;

    cout << "End of testing: check_valid_move\n" << endl;
}