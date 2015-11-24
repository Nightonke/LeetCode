

//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0037_SUDOKU_SOLVER_H
#define LEETCODE__0037_SUDOKU_SOLVER_H


class _0037_Sudoku_Solver {

    struct pos_poss {
        int ii;
        int jj;
        int poss;
        pos_poss() {}
        pos_poss(int ni, int nj, int np) {
            ii = ni;
            jj = nj;
            poss = np;
        }
    };

    bool bmp(pos_poss a, pos_poss b) {
        return a.poss < b.poss;
    }

    class Solution {
    public:
        Solution() {}
        void solveSudoku(vector<vector<char> > &board) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    s[i][j] = board[i][j] - '0';
                }
            }

            h = board.size();
            w = board[0].size();
            numP = 0;
            finishPos = 0;
            finish = false;
            prun();
            DFS(0);

            for (int i = 0; i < h; i++) {  // write in
                for (int j = 0; j < w; j++) {
                    board[i][j] = s[i][j] + '0';
                }
            }
        }
        void prun() {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (s[i][j] == -2) {
                        bool isExist[10];
                        for (int k = 1; k <= 9; isExist[k++] = false);
                        for (int k = 0; k < h; k++) {  // from up to down
                            if (s[k][j] != -2) {
                                isExist[s[k][j]] = true;
                            }
                        }
                        for (int k = 0; k < w; k++) {  // from left to right
                            if (s[i][k] != -2) {
                                isExist[s[i][k]] = true;
                            }
                        }
                        short blockHMax = (i / 3 + 1) * 3;  // in a block
                        short blockHMin = i / 3 * 3;
                        short blockWMax = (j / 3 + 1) * 3;
                        short blockWMin = j / 3 * 3;
                        for (int k1 = blockHMin; k1 < blockHMax; k1++) {
                            for (int k2 = blockWMin; k2 < blockWMax; k2++) {
                                if (s[k1][k2] != -2) {
                                    isExist[s[k1][k2]] = true;
                                }
                            }
                        }
                        int possibility = 9;
                        for (int k = 1; k <= 9; k++) {
                            if (isExist[k]) {
                                possibility -= 1;
                            }
                        }
                        pp[numP++] = pos_poss(i, j, possibility);
                    }
                }
            }
            sort(pp, pp + numP, bmp);  // from small possibility to big
        }
        void DFS(int nowPos) {
            if (nowPos == numP) {
                finish = true;
                return;
            }
            bool isExist[10];
            for (int k = 1; k <= 9; isExist[k++] = false);
            for (int k = 0; k < h; k++) {  // from up to down
                if (s[k][pp[nowPos].jj] != -2) {
                    isExist[s[k][pp[nowPos].jj]] = true;
                }
            }
            for (int k = 0; k < w; k++) {  // from left to right
                if (s[pp[nowPos].ii][k] != -2) {
                    isExist[s[pp[nowPos].ii][k]] = true;
                }
            }
            short blockHMax = (pp[nowPos].ii / 3 + 1) * 3;  // in a block
            short blockHMin = pp[nowPos].ii / 3 * 3;
            short blockWMax = (pp[nowPos].jj / 3 + 1) * 3;
            short blockWMin = pp[nowPos].jj / 3 * 3;
            for (int k1 = blockHMin; k1 < blockHMax; k1++) {
                for (int k2 = blockWMin; k2 < blockWMax; k2++) {
                    if (s[k1][k2] != -2) {
                        isExist[s[k1][k2]] = true;
                    }
                }
            }
            for (int k = 1; k <= 9; k++) {  // check every one
                if (!isExist[k]) {
                    s[pp[nowPos].ii][pp[nowPos].jj] = k;
                    DFS(nowPos + 1);
                    if (finish) {  // if not finish
                        return;
                    }
                    s[pp[nowPos].ii][pp[nowPos].jj] = -2;
                }
            }
        }
    private:
        int w, h;
        int s[9][9];
        pos_poss pp[81];
        int numP;
        int block[9][9];
        int finishPos;
        bool finish;
    };

};


#endif //LEETCODE__0037_SUDOKU_SOLVER_H
