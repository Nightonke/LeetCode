//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0031_NEXT_PERMUTATION_H
#define LEETCODE__0031_NEXT_PERMUTATION_H


class _0031_Next_Permutation {

    class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            next_permutation(num.begin(), num.end());
        }
    };

};


#endif //LEETCODE__0031_NEXT_PERMUTATION_H
