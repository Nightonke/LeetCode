//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0054_SPIRAL_MATRIX_H
#define LEETCODE__0054_SPIRAL_MATRIX_H


class _0054_Spiral_Matrix {

    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            vector<int> ans;
            if (matrix.empty()) return ans;
            int wMin = 0, wMax = matrix[0].size() - 1;
            int hMin = 0, hMax = matrix.size() - 1;
            int si = 0, sj = 0;
            int sum = matrix[0].size() * matrix.size();
            int counter = 0;
            while (counter < sum) {
                for (; sj <= wMax && counter < sum; counter++) ans.push_back(matrix[si][sj++]);  // move right
                si++, sj--, hMin++;
                for (; si <= hMax && counter < sum; counter++) ans.push_back(matrix[si++][sj]);  // move down
                si--, sj--, wMax--;
                for (; sj >= wMin && counter < sum; counter++) ans.push_back(matrix[si][sj--]);  // move left
                si--, sj++, hMax--;
                for (; si >= hMin && counter < sum; counter++) ans.push_back(matrix[si--][sj]);  // move up
                si++, sj++, wMin++;
            }
            return ans;
        }
    };

};


#endif //LEETCODE__0054_SPIRAL_MATRIX_H
