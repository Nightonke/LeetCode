//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0053_MAXIMUM_SUBARRAY_H
#define LEETCODE__0053_MAXIMUM_SUBARRAY_H


class _0053_Maximum_Subarray {

    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int * A = &nums[0];
            return maxSubArray(A, nums.size());
        }
        int maxSubArray(int A[], int n) {
            int nowMax = A[0];
            int Max = A[0];
            for (int i = 1; i < n; i++) {
                if (nowMax <= 0) {
                    nowMax = A[i];
                } else {
                    nowMax += A[i];
                }
                if (nowMax > Max) Max = nowMax;
            }
            return Max;
        }
    };

};


#endif //LEETCODE__0053_MAXIMUM_SUBARRAY_H
