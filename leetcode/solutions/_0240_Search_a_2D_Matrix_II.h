//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0240_SEARCH_A_2D_MATRIX_II_H
#define LEETCODE__0240_SEARCH_A_2D_MATRIX_II_H


class _0240_Search_a_2D_Matrix_II {

    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.size() == 0 || matrix[0].size() == 0) return false;
            int pi = 0;
            int pj = matrix[0].size() - 1;
            while (pi < matrix.size() && pj >= 0) {
                if (target > matrix[pi][pj]) pi++;
                else if (target < matrix[pi][pj]) pj--;
                else return true;
            }
            return false;
        }
    };

};


#endif // LEETCODE__0240_SEARCH_A_2D_MATRIX_II_H
