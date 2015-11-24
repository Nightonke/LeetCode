//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0051_N_QUEENS_H
#define LEETCODE__0051_N_QUEENS_H


class _0051_N_Queens {

    class Solution {
    public:
        vector<vector<string> > solveNQueens(int n) {
            NLine = n;
            w = n;
            h = n;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    chessBoard[i][j] = '.';
                }
            }
            ans.clear();  // notice that this class may be used to solve a question more than one time
            DFS(0);
            return ans;
        }
        void DFS(int nowLine) {
            if (nowLine == NLine) {  // have got the answer
                writeIn();
                return;
            }
            for (int j = 0; j < NLine; j++) {
                if (isValid(nowLine, j)) {
                    chessBoard[nowLine][j] = 'Q';
                    DFS(nowLine + 1);
                    chessBoard[nowLine][j] = '.';
                }
            }
        }
        bool isValid(int i, int j) {  // to judge if a position is valid to put a queen
            for (int k = 0; k < w; k++) {
                if (chessBoard[i][k] == 'Q') return false;  // from left to right
                if (chessBoard[k][j] == 'Q') return false;  // from up to down
            }
            for (int k = 0; k < h; k++) {
                if (inBoard(i + 1 * k, j + 1 * k) && chessBoard[i + 1 * k][j + 1 * k] == 'Q') return false;  // from leftUp to rightDown
                if (inBoard(i - 1 * k, j - 1 * k) && chessBoard[i - 1 * k][j - 1 * k] == 'Q') return false;  // from rightDown to leftUp
                if (inBoard(i - 1 * k, j + 1 * k) && chessBoard[i - 1 * k][j + 1 * k] == 'Q') return false;  // from leftDown to rightUp
                if (inBoard(i + 1 * k, j - 1 * k) && chessBoard[i + 1 * k][j - 1 * k] == 'Q') return false;  // from rightUp to leftDown
            }
            return true;
        }
        bool inBoard(int i, int j) {
            return 0 <= i && i < h && 0 <= j && j < w;
        }
        void writeIn() {
            vector<string> ansPart;
            for (int i = 0; i < h; i++) {
                string temp;
                for (int j = 0; j < w; j++) {
                    temp.push_back(chessBoard[i][j]);
                }
                ansPart.push_back(temp);
            }
            ans.push_back(ansPart);
        }
    private:
        char chessBoard[16][16];
        int NLine;
        int w, h;
        vector<vector<string> > ans;
    };

};


#endif //LEETCODE__0051_N_QUEENS_H
