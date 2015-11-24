//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0048_ROTATE_IMAGE_H
#define LEETCODE__0048_ROTATE_IMAGE_H


class _0048_Rotate_Image {

    class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
            int swapTimes = matrix.size() * matrix[0].size() / 4;
            int swapStartI, swapStartJ, nowLineEnd, nowLineStart;
            swapStartI = swapStartJ = 0;
            nowLineEnd = matrix[0].size() - 1;
            nowLineStart = 0;
            for (int i = 0; i < swapTimes; i++) {
                swapFour(matrix[swapStartI][swapStartJ],
                         matrix[swapStartJ][matrix.size() - 1 - swapStartI],
                         matrix[matrix.size() - 1 - swapStartI][matrix.size() - 1 - swapStartJ],
                         matrix[matrix.size() - 1 - swapStartJ][swapStartI]);  // swap four numbers
                swapStartI++;
                if (swapStartI == nowLineEnd) {
                    swapStartI = ++nowLineStart;
                    nowLineEnd--;
                    swapStartJ++;
                }
            }
        }
        void swapFour(int & a, int & b, int & c, int & d) {
            int temp;
            //int temp = a, a = b, b = c, c = d, d = temp;  // anticlockwise
            temp = d, d = c, c = b, b = a, a = temp;  // clockwise
        }
    };

};


#endif //LEETCODE__0048_ROTATE_IMAGE_H
