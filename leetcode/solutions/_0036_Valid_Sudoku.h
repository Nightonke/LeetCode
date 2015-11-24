//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0036_VALID_SUDOKU_H
#define LEETCODE__0036_VALID_SUDOKU_H


class _0036_Valid_Sudoku {

    class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {
            int blockI[18] = {0, 3, 0, 3, 0, 3, 3, 6, 3, 6, 3, 6, 6, 9, 6, 9, 6, 9};
            int blockJ[18] = {0, 3, 3, 6, 6, 9, 0, 3, 3, 6, 6, 9, 0, 3, 3, 6, 6, 9};

            //check row
            for (int i = 0; i < 9; i++) {
                int exist[10];
                for (int j = 1; j <= 9; exist[j++] = 0);
                for (int j = 0; j < 9; j++) {
                    if ('0' <= board[i][j] && board[i][j] <= '9') exist[board[i][j] - '0']++;
                }
                for (int j = 1; j <= 9; j++) {
                    if (exist[j] >= 2) return false;
                }
            }

            //check column
            for (int i = 0; i < 9; i++) {
                int exist[10];
                for (int j = 1; j <= 9; exist[j++] = 0);
                for (int j = 0; j < 9; j++) {
                    if ('0' <= board[j][i] && board[j][i] <= '9') exist[board[j][i] - '0']++;
                }
                for (int j = 1; j <= 9; j++) {
                    if (exist[j] >= 2) return false;
                }
            }

            //check block
            for (int i = 0; i < 18; i += 2) {
                int exist[10];
                for (int j = 1; j <= 9; exist[j++] = 0);
                for (int j1 = blockI[i]; j1 < blockI[i + 1]; j1++) {
                    for (int j2 = blockJ[i]; j2 < blockJ[i + 1]; j2++) {
                        if ('0' <= board[j1][j2] && board[j1][j2] <= '9') exist[board[j1][j2] - '0']++;
                    }
                }
                for (int j = 1; j <= 9; j++) {
                    if (exist[j] >= 2) return false;
                }
            }
            return true;
        }
    };

};


#endif //LEETCODE__0036_VALID_SUDOKU_H
